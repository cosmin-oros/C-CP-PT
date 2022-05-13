#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//numarul de combinatii
int contor = 0;
int repere[10] = { 0 };

//functie pentru aflarea numarului de combinari
int genereazaCombinatii(int L, int N) {
	int calePosibila;
	if (L < 0)
	{
		return -1;
	}
	if (L == 0)
	{
		contor++;
		printf("%d combinatii \n Lungimi: 0\n", contor);
	}

	
	int* lungimi = calloc(L, sizeof(int));
	if (!lungimi)
	{
		printf("Nu am putut aloca memorie\n");
		return -1;
	}

	for (int i = N - 1; i >= 0; i--)
	{

		//gasim cea mai mare lungime pe care o putem folosi
		while (repere[i] > L)
		{
			i--;
		}

		calePosibila = 1;
		while (calePosibila)
		{
			int final = 0;
			int m = L;
			int k = 0;
			int j = i;
			lungimi[0] = repere[i];
			m -= repere[i];

			while (m > 0 && j >= 0)
			{
				if ((m - repere[j]) >= 0)
				{
					lungimi[k++] = repere[j];
					m -= repere[j];
				}
				else {
					j--;
				}

			}

			//verificam daca am ajuns la ultima solutie pe aceasta cale
			for (int p = 1; lungimi[p]; p++)
			{
				if (lungimi[p] == repere[0])
				{
					final = 1;
				}
				else {
					final = 0;
				}

			}

			//resetam toate elementele la 0
			printSolutie(lungimi);
			memset(lungimi, 0, repere);

			if (final)
			{
				calePosibila = 0;
			}
		}

	}

	free(lungimi);
}

void printSolutie(int* lungimi) {
	printf("\n--------------------------------\n");
	for (int i = 0; lungimi[i]; i++)
	{
		printf("%d ", lungimi[i]);
	}
	printf("\n");

}

int main() {
	int L, N, c;
    char a;
	FILE* in = fopen("bri.in", "r");
	if (!in) {
		printf("Nu am putut deschide fisierul\n");
		exit(0);
	}

	FILE* out = fopen("bri.out", "w");
	if (!out) {
		printf("Nu am putut deschide fisierul\n");
		exit(0);
	}

    a = fgetc(in);
	while (a != ' ') {
		c = atoi(a);
		L *= 10 + c;
		a = fgetc(in);
	}
	if (L > 1000 || L < 1) {
		printf("Numarul din fisier nu este in intervalul [1,1000]\n");
	}

	a = fgetc(in);
	while (a != '\n') {
		c = atoi(a);
		N *= 10 + c;
		a = fgetc(in);
	}
	if (N > 10 || L < 1) {
		printf("Numarul din fisier nu este in intervalul [1,1000]\n");
	}

	a = fgetc(in);
	int spatii = 0;

	while (spatii < N) {
		while (a != ' ') {
			c = atoi(a);
			repere[spatii] *= 10 + c;
			a = fgetc(in);
		}

		a = fgetc(in);
		spatii++;
	}

	genereazaCombinatii(L, N);
	return 0;
}