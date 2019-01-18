objs = timecli1.o timeserv1.o get_time.o lib.o

all: s1 c1

$(objs): %.o: %.c
	gcc -g -c $< -o $@


c1: timecli1.o lib.o lib.h
	gcc -g -o c1 timecli1.o lib.o

s1: timesrv1.o get_time.o lib.o lib.h
	gcc -g -o s1 timesrv1.o get_time.o lib.o

clean:
	rm s1 c1 *.o