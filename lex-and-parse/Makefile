.PHONY: all
all: test

CFLAGS := -Wall

BUILDDIR := $(CURDIR)/build

build: main.c lex.c parse.c | $(BUILDDIR)
	cc -Wall -std=c17 *.c -o $(BUILDDIR)/parser	


test: build input
	$(BUILDDIR)/parser

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

.PHONY: clean
clean:
	rm -f $(BUILDDIR)/*