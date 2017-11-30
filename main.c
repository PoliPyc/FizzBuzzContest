#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LENGTH 100
#define DEFAULT_CONDITION_LENGTH 10
#define DEFAULT_MESSAGE_LENGTH 10

/******* TYPES *******/

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

/******* TYPES *******/


/******* PROTOTYPES *******/

void setDefaultConditions(Condition *condition);

void allocateFizzBuzzTable(char *table);

void iterateConditionsOnTable(char *table, Condition *conditions);

char *runCondition(int i, Condition *conditions);

/******* PROTOTYPES *******/


/******* MAIN *******/

int main() {
    char fizzBuzzTable[DEFAULT_LENGTH];

    Condition fizzBuzzConditions[DEFAULT_CONDITION_LENGTH];

    setDefaultConditions(fizzBuzzConditions);

//    allocateFizzBuzzTable(FizzBuzzTable);

    iterateConditionsOnTable(fizzBuzzTable, fizzBuzzConditions);

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

/******* MAIN *******/



/******* FUNCTIONS *******/

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

void iterateConditionsOnTable(char *table, Condition *conditions) {
    int i = 0;
    char *result;

    printf("%s", conditions->message);

    for(;i < DEFAULT_LENGTH; ++i){
        result = runCondition(i, conditions);
        printf("%s \n", result);
    }
}

char *runCondition(int number, Condition *conditions) {
    int i = 0;
    int result = 0;
    char strNumber[12] = ""; //"char" size of every int number
    char response[100] = "";

    for(; i < DEFAULT_CONDITION_LENGTH; ++i){
        if(conditions->operation == NULL){
            break;
        }

        switch(conditions->operation){
            case ADD:
                result = number + conditions->parameter;
                break;
            case SUB:
                result = number - conditions->parameter;
                break;
            case MUL:
                result = number * conditions->parameter;
                break;
            case DIV:
                result = number / conditions->parameter;
                break;
            case MOD:
                result = number % conditions->parameter;
                break;
            default:
                result = NULL;
        }

        switch(conditions->comparator){
            case EQ:
                if(result == conditions->result) {
                    strcpy(strNumber, conditions->message);
                }
                break;

            case NEQ:
                if(result != conditions->result) {
                    strcpy(strNumber, conditions->message);
                }
                break;

            case LES:
                if(result < conditions->result) {
                    strcpy(strNumber, conditions->message);
                }
                break;

            case GRT:
                if(result > conditions->result) {
                    strcpy(strNumber, conditions->message);
                }
                break;
        }
        if(strNumber != NULL){
            strcat(response, strNumber);
        }
        conditions++;
    }

    if(response == NULL){
        sprintf(strNumber, "%d", number);
        strcat(response, strNumber);
    }
    return response;
}

/******* FUNCTIONS *******/
