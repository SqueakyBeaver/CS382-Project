.PHONY: all
all: test

CFLAGS := -Wall

BUILDDIR := $(CURDIR)/build

build: main.c lex.c parse.c | $(BUILDDIR)
	cc -Wall *.c -o $(BUILDDIR)/parser	


test: build input
	$(BUILDDIR)/parser

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

.PHONY: clean
clean:
	rm -f $(BUILDDIR)/*