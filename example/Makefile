ALL:run

.PHONY:build link run clean
build:
	nasm -felf64 test.asm

link:build
	ld test.o -o test
run:link
	./test
clean:
	@rm -rf *.o
	@rm -rf test