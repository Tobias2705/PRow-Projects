/*#include "Nag³ówek.h"
#include <time.h>
#include <omp.h>
#include <math.h>

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

bool wielokrotnosci(int n, int* pierwsze, int licznik) {
	for (int i = 0; i < licznik; ++i) {
		if (n == pierwsze[i]) break;
		if (n % pierwsze[i] == 0) return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
	omp_set_num_threads(THREADS);

	int i, indexPierwsze = 0, indexLiczby = 0;
	const int SIZE = N - M + 1;
	const int SQRN = sqrt(N);

	int* pierwsze = new int[SQRN];
	int* liczby = new int[SIZE];
	clock_t start, stop;

	for (i = M; i <= N; ++i)
		liczby[indexLiczby++] = i;

	for (i = 0; i < SQRN; ++i)
		pierwsze[i] = 0;

	start = clock();

#pragma omp parallel
	{

		// Zebranie wszystkich liczb pierwszych z danego zakresu
#pragma omp for schedule(dynamic) 
		for (i = 2; i <= SQRN; ++i) {
			if (liczbaPierwsza(i))
				pierwsze[i - 2] = i;
		}

		// Przesuniêcie zer w tablicy liczb pierwszych
#pragma omp single
		{
			int memo = -1;
			for (i = 0; i < SQRN; ++i) {
				if (pierwsze[i] != 0) {
					if (memo != -1) {
						pierwsze[memo++] = pierwsze[i];
						pierwsze[i] = 0;
					}
					++indexPierwsze;
				}
				else if (memo == -1) {
					memo = i;
				}

			}
		}

		// Odsiewanie
#pragma omp for nowait schedule(dynamic) 
		for (i = 0; i < SIZE; ++i) {
			if (wielokrotnosci(liczby[i], pierwsze, indexPierwsze))
				liczby[i] = 0;
		}
	}

	stop = clock();

	indexLiczby = 0;
	for (int j = 0; j < SIZE; ++j)
		if (liczby[j] != 0) ++indexLiczby;

	printf("Znaleziono %d liczb pierwszych: ", indexLiczby);

	printf("\nCzas przetwarzania wynosi %f sekund\n", ((double)(stop - start) / 1000.0));

	delete[] liczby;
	delete[] pierwsze;
	return 0;
}*/