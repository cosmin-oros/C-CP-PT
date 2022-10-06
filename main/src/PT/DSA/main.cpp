#include  "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 55000

void functie_test(int* arr, int size)
{
	int i,j,k; 
	for (i = 0; i <= size; i++) {
		for (j = 0; j <= size-1; j++){
			if (arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int* generateArr(){
	int* arr = (int*)malloc(N*sizeof(int));

	if (!arr){
		return NULL;
	}

	for (int i = N - 1; i >= 0; i--){
		arr[i] = N - i;
	}

	return arr;
}

void main(void)
{ 
	float timp;
	int* arr = generateArr();
	int size = N;

	starton(); 
	functie_test(arr, size);
	timp=startoff(); 
	printf("%f",timp);
} 