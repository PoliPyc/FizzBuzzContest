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
    int parameter;
    Comparator comparator;
    int result;
    char * message;
} Condition;

void setDefaultConditions(Condition *condition);

void allocateFizzBuzzTable(char *table);

int main() {
    char FizzBuzzTable[DEFAULT_LENGTH];

    Condition fizzBuzzConditions[DEFAULT_CONDITION_LENGTH];

    setDefaultConditions(fizzBuzzConditions);
//    allocateFizzBuzzTable(FizzBuzzTable);

    printf("Hello, World!\n");
    printf("%d", fizzBuzzConditions[0].operation);
    printf("%d", fizzBuzzConditions[0].parameter);
    printf("%d", fizzBuzzConditions[0].comparator);
    printf("%d", fizzBuzzConditions[0].result);
    printf("%s", fizzBuzzConditions[0].message);

    printf("%d", fizzBuzzConditions[1].operation);
    printf("%d", fizzBuzzConditions[1].parameter);
    printf("%d", fizzBuzzConditions[1].comparator);
    printf("%d", fizzBuzzConditions[1].result);
    printf("%s", fizzBuzzConditions[1].message);
    return 0;
}

void allocateFizzBuzzTable(char *table) {
    table = realloc(table, DEFAULT_LENGTH * sizeof(table));
}

void setDefaultConditions(Condition *condition) {
    condition->operation = MOD;
    condition->parameter = 3;
    condition->comparator = EQ;
    condition->result = 0;
    condition->message = "Fizz";

    condition++;

    condition->operation = MOD;
    condition->parameter = 5;
    condition->comparator = EQ;
    condition->result = 0;
    condition->message = "Buzz";
}