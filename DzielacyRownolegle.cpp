/*#include "Nag³ówek.h"
#include <time.h>
#include <omp.h>

#define THREADS 4

// Zak³adamy, ¿e M, N > 1
// const int M = 2, N = 20000000;
// Czas obliczeñ = 

// const int M = 2, N = 10000000;
// Czas obliczeñ = 

const int M = 10000000, N = 20000000;
// Czas obliczeñ = 

bool liczbaPierwsza(int n) {
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return false;
	return true;
}

int main(int argc, char* argv[])
{
	omp_set_num_threads(THREADS);

	const int SIZE = N - M + 1;
	int i, indexLiczby = 0;

	int* liczby = new int[SIZE];
	clock_t start, stop;

	for (i = 0; i < SIZE; ++i)
		liczby[i] = 0;

	start = clock();

#pragma omp parallel
	{
#pragma omp for nowait
		for (i = M; i <= N; i++) {
			if (liczbaPierwsza(i)) {
				liczby[i - M] = i;
			}
		}
	}

	stop = clock();

	for (int j = 0; j < SIZE; ++j)
		if (liczby[j] != 0) ++indexLiczby;

	printf("Znaleziono %d liczb pierwszych: ", indexLiczby);

	printf("\nCzas przetwarzania wynosi %f sekund\n", ((double)(stop - start) / 1000.0));

	delete[] liczby;
	return 0;
}*/