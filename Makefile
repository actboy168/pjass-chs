CFLAGS = -O3 -flto -MMD -s -fexec-charset=GBK
VERSION := f128812

# when testing and releasing, we can't run both in parallel
# but we also don't want to test when we're just making the zip
# additionaly we want to test before we make any zip file
# so these rules depend on test just when we're both releasing and testing
ifneq (,$(findstring release,$(MAKECMDGOALS)))
  ifneq (,$(findstring test,$(MAKECMDGOALS)))

pjass-git-$(VERSION).zip: | test
pjass-git-$(VERSION)-src.zip: | test

  endif
endif

SRC := misc.c hashtable.c paramlist.c funcdecl.c typeandname.c

OBJS := $(SRC:.c=.o)
OBJS += main.o token.yy.o grammar.tab.o

.PHONY: all release clean debug prof
.PHONY: clean-release-files clean-prof-files clean-build-files
.PHONY: binary-release src-release
.PHONY: help

all: pjass-latest

help:
	@awk -F ':|##' \
		'/^[^\t].+?:.*?##/ { \
			printf "\033[36m%-20s\033[0m %s\n", $$1, $$NF \
		}' $(MAKEFILE_LIST)

-include $(OBJS:.o=.d)

pjass-latest: $(OBJS) ## Builds pjass
	$(CC) $(CFLAGS) $^ -o $@

test: should-fail should-check map-scripts ## Runs all tests

release: src-release binary-release ## Builds a pjass release with src- and bin-zipballs

clean: clean-build-files clean-release-files clean-prof-files ## Cleans the whole project



debug: CFLAGS = -w -g
debug: pjass ## Builds pjass with debugging support

prof: CFLAGS = -w -pg
prof: pjass ## Builds pjass with profiling support. You can run all tests with profiling enabled via `make PROF=1 test`



main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $< -DVERSIONSTR="\"git-$(VERSION)\""

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<


token.yy.o: token.yy.c | grammar.tab.h
main.o: main.c grammar.tab.h token.yy.h

# see token.l options block
%.yy.c %.yy.h: %.l
	flex $<

%.tab.c %.tab.h: %.y
	bison -d $<


clean-build-files: ## Cleans all build files
	rm -f grammar.tab.h grammar.tab.c token.yy.c token.yy.h \
		$(OBJS) $(OBJS:.o=.d) \
		pjass

clean-release-files: ## Cleans all release zipballs
	rm -f pjass-git-*.zip

clean-prof-files: ## Cleans all profiling files
	rm -f tests/should-check/*-analysis.txt \
          tests/should-fail/*-analysis.txt \
          gmon.out


src-release: pjass-git-$(VERSION)-src.zip ## Builds the source zipball
binary-release: pjass-git-$(VERSION).zip ## Builds the exe zipball

pjass-git-$(VERSION)-src.zip: main.c grammar.y token.l Makefile notes.txt readme.txt $(SRC:.c=.h) $(SRC)
	zip -q -r pjass-git-$(VERSION)-src.zip $^ tests/should-check/ tests/should-fail/

pjass-git-$(VERSION).zip: pjass
	strip pjass
	upx --best --ultra-brute pjass > /dev/null
	zip -q pjass-git-$(VERSION).zip pjass


SHOULD_FAIL := $(wildcard tests/should-fail/*.j)
SHOULD_CHECK := $(wildcard tests/should-check/*.j)
MAP_SCRIPTS := $(wildcard tests/map-scripts/*.j)

.PHONY: test print-test should-check should-fail map-scripts
.PHONY: $(SHOULD_CHECK) $(SHOULD_FAIL) $(MAP_SCRIPTS)

$(MAP_SCRIPTS): pjass print-test
	@MAPSCRIPT=1 ./check.sh $@

$(SHOULD_CHECK): pjass print-test
	@./check.sh $@


$(SHOULD_FAIL): pjass print-test
	@./fail.sh $@


should-fail: $(SHOULD_FAIL) ## Tests that should fail
should-check: $(SHOULD_CHECK) ## Tests that should check
map-scripts: $(MAP_SCRIPTS) ## Tests which are run with common.j and Blizzard.j



print-test: pjass
	@echo 'Testing... '

