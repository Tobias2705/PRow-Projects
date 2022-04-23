#include "Nag³ówek.h"

#include <time.h>

// Zak³adamy, ¿e M, N > 1
 const int M = 2, N = 20000000;
// Czas obliczeñ = 13.443

//const int M = 2, N = 10000000;
// Czas obliczeñ = 4.992

//const int M = 10000000, N = 20000000;
// Czas obliczeñ = 8.427

bool liczbaPierwsza(int n) {
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return false;
	return true;
}


int main(int argc, char* argv[])
{
	int i, indexPierwsze = 0;
	const int SIZE = N - M + 1;

	int* liczby = new int[SIZE];
	clock_t start, stop;

	start = clock();

	for (i = M; i <= N; i++) {
		if (liczbaPierwsza(i))
			liczby[indexPierwsze++] = i;
	}

	stop = clock();

	printf("Znaleziono %d liczb pierwszych: ", indexPierwsze);
	//for (int j = 0; j < indexPierwsze; ++j)
	//	printf("%d, ", liczby[j]);

	printf("\nCzas przetwarzania wynosi %f sekund\n", ((double)(stop - start) / 1000.0));

	delete[] liczby;
	return 0;
}