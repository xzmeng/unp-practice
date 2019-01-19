objs = timecli1.o timeserv1.o get_time.o lib.o \
	echoserv.o echocli.o echocliclose.o

all: s1 c1 echoserv echocli echocliclose

$(objs): %.o: %.c
	gcc -g -c $< -o $@

echo: echoserv echocli

c1: timecli1.o lib.o lib.h
	gcc -g -o c1 timecli1.o lib.o

s1: timesrv1.o get_time.o lib.o lib.h
	gcc -g -o s1 timesrv1.o get_time.o lib.o

echoserv: echoserv.o lib.o lib.h
	gcc -g -o echoserv echoserv.o lib.o

echocli: echocli.o lib.o lib.h
	gcc -g -o echocli echocli.o lib.o

echocliclose: echocliclose.o lib.o lib.h
	gcc -g -o echocliclose echocliclose.o lib.o

clean:
	rm s1 c1 *.o echocli echoserv