CC = gcc
LDFLAGS=
CFLAGS= --std=c11 -Wall -O0 -g 
SRCDIR=src
APPNAME =sse_tout
src=$(addprefix $(SRCDIR)/, *.c)

$(APPNAME): $(src)
	$(CC) $(CFLAGS) $(src) -o $(APPNAME) $(LDFLAGS)


.PHONY: clean
clean:
	rm -f $(APPNAME)*