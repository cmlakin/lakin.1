#lakin/4760/Project1

GCC = gcc

CFLAGS = -g -Wall

driver.o: driver.c
	$(GCC) $(CFLAGS) -c driver.c

clean:
	rm *.o
