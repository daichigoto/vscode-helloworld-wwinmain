CMD=	helloworld.exe

SRCS=	$(wildcard *.c)
OBJS=	$(SRCS:.c=.o)

CC=	clang
CFLAGS+=-g
EXIST=	cmd.exe //C if exist

build: $(CMD)

$(CMD): $(OBJS)
	$(CC) $(CFLAGS) -o $(CMD) $(OBJS)

.c.o:
	$(CC) -c $< -o $@

clean:
	$(EXIST) $(CMD) del $(CMD)
	$(EXIST) main.o del $(OBJS)
	$(EXIST) $(CMD:.exe=.ilk) del $(CMD:.exe=.ilk)
	$(EXIST) $(CMD:.exe=.pdb) del $(CMD:.exe=.pdb)
	$(EXIST) $(CMD).stackdump del $(CMD).stackdump
	$(EXIST) nul del *.tmp nul
