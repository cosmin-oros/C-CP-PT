#include <iostream>
#include <cstring>

#define N 5

typedef struct employee {
    char name[35];
    int year;
    int bonus;
}EMPLOYEE;

void fillArr(EMPLOYEE employees[N]) {
    for (int i = 0; i < N; i++)
    {
        strcpy(employees[i].name, "A" + i);
        employees[i].year = 2000 + i;
        employees[i].bonus = i % 2;
    }
}

void printArr(EMPLOYEE employees[N]) {
    for (int i = 0; i < N; i++)
    {
        std::cout << employees[i].name << " " << employees[i].year << " " << employees[i].bonus << std::endl;
    }
    
}

void move_bonus_employees(EMPLOYEE employees[N]) {
    int i = 0, j = N - 1;

    // Move bonus employees to the front of the array
    // O(n)
    while (i <= j) {
        if (employees[i].bonus == 1) {
            i++;
        } else if (employees[j].bonus == 0) {
            j--;
        } else {
            struct employee temp = employees[i];
            employees[i] = employees[j];
            employees[j] = temp;
            i++;
            j--;
        }
    }

    // Sort non-bonus employees in reverse alphabetical order
    // bubble sort
    // O(n^2)
    for (i = 0; i < N; i++) {
        if (employees[i].bonus == 0) {
            for (j = i + 1; j < N; j++) {
                if (employees[j].bonus == 0) {
                    if (strcmp(employees[i].name, employees[j].name) < 0) {
                        struct employee temp = employees[i];
                        employees[i] = employees[j];
                        employees[j] = temp;
                    }
                }
            }
        }
    }
}

int main() {
    EMPLOYEE employees[N];

    fillArr(employees);

    printArr(employees);

    move_bonus_employees(employees);
    
    printArr(employees);

    return 0;
}