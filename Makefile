CC = gcc
CFLAGS = -g -std=c99 -Wall
BUILDDIR = build
SRCDIR = src

.phony: clean test all debug bubble_sort.o main.o list.o

all: clean bubble_sort.o list.o main.o

main.o:
	${CC} ${CFLAGS} -o ${BUILDDIR}/main ${SRCDIR}/main.c ${BUILDDIR}/list.o ${BUILDDIR}/bubble_sort.o

list.o:
	${CC} ${CFLAGS} -c ${SRCDIR}/list.c -o ${BUILDDIR}/list.o

bubble_sort.o:
	${CC} ${CFLAGS} -c ${SRCDIR}/bubble_sort.c -o ${BUILDDIR}/bubble_sort.o

clean:
	rm -f ${BUILDDIR}/*.o ${BUILDDIR}/main

test:
	${BUILDDIR}/main

debug:
	gdb -q ${BUILDDIR}/main

