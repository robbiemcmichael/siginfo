NAME = siginfo

.PHONY: build
build: bin/$(NAME)

bin:
	mkdir -p $@

bin/$(NAME): bin
	gcc -o $@ main.c

.PHONY: clean
clean:
	-rm -r bin
