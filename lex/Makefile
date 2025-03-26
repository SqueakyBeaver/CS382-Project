all: lexer test

lexer: main.c
	mkdir ./build
	$(CC) -Wall main.c -o ./build/lexer.out	


test: lexer input
	./build/lexer.out

clean:
	rm -r ./build