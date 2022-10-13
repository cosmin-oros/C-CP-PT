#include <stdio.h>
#include <stdlib.h>

#define N 15001

typedef struct Student{
	int age;
	float grade;
}student;

// function to generate random age and grade for the N students
void generateRandStudents(student s[N]){
	for (int i = 0; i < N-1; i++){
		s[i].age = rand() % 30 + 10;
		s[i].grade = 1 / (float)(rand() % 10 + 1) + (float)(rand() % 9);
	}
}

// function to print all the students grades and ages
void printStudents(student s[N]){
	for (int i = 0; i < N-1; i++){
		printf("Student %d. age: %d, grade: %.1f\n", i + 1, s[i].age, s[i].grade);
	}
}

// sentinel search
int sentinelSearch(student s[N], int age){
	int i = 0;
	s[N].age = age;

	do{
		i++;
	} while (s[i].age != age);

	if (i == N){
		return 0;
	}
	else{
		return i;
	}
}

int main(){
	// array of N students
	student s[N];
	int age;

	generateRandStudents(s);

	printStudents(s);

	printf("\n Input age you want to search for:");
	scanf("%d", &age);

	int pos = sentinelSearch(s, age);

	if (pos){
		printf("Student with age %d found at position %d\n", age, pos);
	}
	else{
		printf("Didn't find age %d \n", age);
	}

	return 0;
}