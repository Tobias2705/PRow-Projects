#include "Nag³ówek.h"

#include <time.h>

// Zak³adamy, ¿e M, N > 1
// const int M = 2, N = 20000000;
// Czas obliczeñ = 4.732

// const int M = 2, N = 10000000;
// Czas obliczeñ = 2.112

const int M = 10000000, N = 20000000;
// Czas obliczeñ = 2.498

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
	int i, indexPierwsze = 0, indexLiczby = 0;
	const int SIZE = N - M + 1;

	int* pierwsze = new int[N];
	int* liczby = new int[SIZE];
	clock_t start, stop;

	for (i = M; i <= N; ++i)
		liczby[indexLiczby++] = i;

	start = clock();

	// Zebranie wszystkich liczb pierwszych z danego zakresu
	for (i = 2; i * i <= N; ++i) {
		if (liczbaPierwsza(i))
			pierwsze[indexPierwsze++] = i;
	}

	// Odsiewanie
	for (i = 0; i < SIZE; ++i) {
		if (wielokrotnosci(liczby[i], pierwsze, indexPierwsze)) {
			liczby[i] = 0;
			--indexLiczby;
		}
	}

	stop = clock();

	printf("Znaleziono %d liczb pierwszych: ", indexLiczby);
	
	printf("\nCzas przetwarzania wynosi %f sekund\n", (double(stop - start) / 1000.0));

	delete[] liczby;
	delete[] pierwsze;
	return 0;
}