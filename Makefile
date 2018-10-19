CC = gcc
CFLAGS = -O0 -g -Wall -Werror -m32
LIBS = -lm

GIT_HOOKS := .git/hooks/applied
all: $(GIT_HOOKS) btest fshow ishow

$(GIT_HOOKS):
	@scripts/install-git-hooks
	@echo

btest: btest.c bits.c decl.c tests.c btest.h bits.h
	$(CC) $(CFLAGS) $(LIBS) -o btest bits.c btest.c decl.c tests.c

fshow: fshow.c
	$(CC) $(CFLAGS) -o fshow fshow.c

ishow: ishow.c
	$(CC) $(CFLAGS) -o ishow ishow.c

check: btest
	./btest

clean:
	rm -f *.o btest fshow ishow *~


