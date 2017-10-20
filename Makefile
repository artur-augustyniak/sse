CC = gcc
LDFLAGS=
CFLAGS= --std=c11 -Wall -O0 -g 
SRCDIR=src
APPNAME =sse_tout
src=$(addprefix $(SRCDIR)/, *.c)

.PHONY: $(APPNAME)
$(APPNAME): $(src)
	$(CC) $(CFLAGS) $(src) -o $(APPNAME) $(LDFLAGS)
	./$(APPNAME)


.PHONY: clean
clean:
	rm -f $(APPNAME)*