#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_LENGTH 100
#define DEFAULT_CONDITION_LENGTH 10
#define DEFAULT_MESSAGE_LENGTH 10

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
    char * message;
} Condition;

void allocateFizzBuzzTable(char *table);

int main() {
    char FizzBuzzTable[DEFAULT_LENGTH];

    Condition fizzBuzzConditions[DEFAULT_CONDITION_LENGTH];

    fizzBuzzConditions[0].operation = MOD;
    fizzBuzzConditions[0].comparator = EQ;
    fizzBuzzConditions[0].result = 0;
    fizzBuzzConditions[0].message = 'Fizz';

//    allocateFizzBuzzTable(FizzBuzzTable);

    printf("Hello, World!\n");
    printf("%d", fizzBuzzConditions[0].operation);
    printf("%d", fizzBuzzConditions[0].comparator);
    printf("%d", fizzBuzzConditions[0].result);
    return 0;
}

void allocateFizzBuzzTable(char *table) {
    table = realloc(table, DEFAULT_LENGTH * sizeof(table));
}