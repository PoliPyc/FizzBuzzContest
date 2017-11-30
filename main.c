#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_LENGTH 100
#define DEFAULT_CONDITION_LENGTH 10

typedef enum operation {
    ADD,
    SUB,
    MUL,
    DIV,
    MOD
} Operation;

typedef enum comparator {
    EQ,
    NEQ,
    LES,
    GRT
} Comparator;

typedef struct condition {
    Operation operation;
    Comparator comparator;
    int result;
} Condition;

void allocateFizzBuzzTable(char *table);

int main() {
    char FizzBuzzTable[DEFAULT_LENGTH];

    Condition fizzBuzzConditions[DEFAULT_CONDITION_LENGTH];

    fizzBuzzConditions[0].operation = ADD;
    fizzBuzzConditions[0].comparator = EQ;
    fizzBuzzConditions[0].result = 0;

//    allocateFizzBuzzTable(FizzBuzzTable);

    printf("Hello, World!\n");
    printf("%s", fizzBuzzConditions[0].operation);
    return 0;
}

void allocateFizzBuzzTable(char *table) {
    table = realloc(table, DEFAULT_LENGTH * sizeof(table));
}