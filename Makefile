all:
	lex

lex:
	cd lex-and-parse
	$(MAKE)

lex-build:
	cd lex-and-parse
	$(MAKE) build
