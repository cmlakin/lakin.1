#Makefile/lakin/4760/Project1

GCC = gcc
CFLAGS = -g 

driver: driver.o log.o
	$(GCC) $(CFLAGS) -o driver

driver.o: driver.c log.h
	$(GCC) $(CFLAGS) -c driver.c

log.o: log.c log.h
	$(GCC) $(CFLAGS) -c log.c


clean:
	rm *.o driver
