
/*
#include <math.h>
#include <time.h>
#include <omp.h>
#include "Nagłówek.h"
#define THREADS 4

// zakladamy, ze M, N > 1
const int M = 2, N = 20000000;
// t = 0.221
// const int M = 2, N = 10000000;
// Czas obliczeñ = 
//const int M = 10000000, N = 20000000;
// Czas obliczeñ = 
bool liczbaPierwsza(int n) {
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return false;
	return true;
}

int main(int argc, char* argv[])
{
	omp_set_num_threads(THREADS);

	int i, indexPierwsze = 0, indexLiczby  = 0;
	const int SIZE = N - M + 1;
	const int SQRN = sqrt(N);

	int* pierwsze = new int[N];
	int* liczby = new int[SIZE];
	int** usuwanie = new int* [THREADS];
	clock_t start, stop;

	for (i = M; i <= N; ++i)
		liczby[indexLiczby ++] = i;

	for (int j = 0; j < THREADS; ++j) {
		usuwanie[j] = new int[SIZE];
		for (i = 0; i < SIZE; ++i)
			usuwanie[j][i] = 1;
	}

	start = clock();

#pragma omp parallel
	{
		int j;

		// generowanie wszystkich liczb pierwszych z przedzialu 2 do sqrt(N)
#pragma omp for
		for (i = 2; i <= SQRN; ++i) {
			if (liczbaPierwsza(i))
				pierwsze[i - 2] = i;
		}

		// "odsiewanie"
#pragma omp for nowait
		for (i = 0; i < SQRN; ++i) { // dla kazdej pierwszej

			if (pierwsze[i] == 0) continue;

			// wyszukaj pierwsze wystapienie
			for (j = 0; liczby[j] % pierwsze[i] != 0; ++j);

			// nie usuwaj jesli jest w przedziale do sqrt(n)
			if (liczby[j] == pierwsze[i]) j += pierwsze[i];

			for (j; j < SIZE; j += pierwsze[i]) // dla kazdej wielokrotnosci
				usuwanie[omp_get_thread_num()][j] = 0;

		}
	}

	stop = clock();

	int suma;
	indexLiczby  = 0;
	for (i = 0; i < SIZE; ++i) {
		suma = 1;
		for (int j = 0; j < THREADS; ++j)
			suma *= usuwanie[j][i];

		if (liczby[i] * suma != 0)
			++indexLiczby ;
	}

	printf("Znaleziono %d liczb pierwszych: ", indexLiczby );
	//for (int j = 0; j < SIZE; ++j)
	//	if (liczby[j] != 0) printf("%d, ", liczby[j]);

	printf("\nCzas przetwarzania wynosi %f sekund\n", ((double)(stop - start) / 1000.0));

	delete[] pierwsze;
	delete[] liczby;
	return 0;
}*/