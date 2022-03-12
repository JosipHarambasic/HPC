cpi: cpi.o getTime.o
	cc -O3 -o cpi cpi.o getTime.o

cpi_mpi: cpi_mpi.o getTime.o
	cc -O3 -o cpi_mpi cpi_mpi.o getTime.o

cpi_mpi.o: cpi_mpi.c getTime.h
	cc -O3 -c -o cpi_mpi.o cpi_mpi.c

cpi.o: cpi.c getTime.h	
	cc -O3 -c -o cpi.o cpi.c

getTime.o: getTime.c getTime.h
	cc -O3 -c -o getTime.o getTime.c

all: cpi_mpi cpi

clean:
	rm -f cpi_mpi cpi
