# makefile for generating word lists for espace
SHELL:=$(shell which bash)
default:  all
# include toc.make

LC = perl ${PWD}/lc
RECASE = perl -n ${PWD}/recase

STRIPPUNCT = ./strippunct

MASTER_INPUT = lotsofwords

INPUT_DIRS = inputs
WORDS_OUT = words.out
ITERATIONS = 5
SAMPLES_PER_OUTPUT = 10000

$(MASTER_INPUT): Makefile
	@-test -e $@ && rm $@
	@echo "Creating Master word list [$@] ..."
	@for i in $$(find $(INPUT_DIRS) -maxdepth 1 -type f); do cat $$i; done \
		| $(STRIPPUNCT) | sort -fu > $@;

$(WORDS_OUT): Makefile $(MASTER_INPUT)
	@-test -e $@ && rm $@
	@echo "Creating words..."; \
	it=$(ITERATIONS); \
	while test "$$it" -gt "0"; do \
		echo "$$it iteration(s) to go...";\
		$(LC) -$(SAMPLES_PER_OUTPUT) $(MASTER_INPUT) >> $@; \
		it=$$((it - 1)); \
	done;
	@sort -fu < $@ | $(RECASE) > foo; mv foo $@
	@echo "Generated $$(wc -l $@ | awk '{print $$1;}') words. Output file=$@"


CLEAN_FILES += $(WORDS_OUT) $(MASTER_INPUT) *~
clean:
	-rm -f $(CLEAN_FILES)


all: $(WORDS_OUT)
