#include <stdio.h>
#include <float.h>
#include <stdbool.h>

void getOperands(double* firstOperand, double* secondOperand)
{
    printf("Please enter the first operand: ");
    scanf("%lf", firstOperand);
    printf("Please enter the second operand: ");
    scanf("%lf", secondOperand);
}

bool checkCalculation(double operationResult, double* resultStorage)
{
    if (operationResult > DBL_MAX)
    {
        printf("Number overflow\n\n");
        return false;
    }
    else if (operationResult < DBL_MIN)
    {
        printf("Number underflow\n\n");
        return false;
    }

    *resultStorage = operationResult;
    return true;
}

void Calculation(double *firstOperand, double* secondOperand, double* result)
{
    *result = 1;
    for (int i = 0; i < *secondOperand; i++)
    {
        *result *= *firstOperand;
    }
}

void Operation(int* operation, double* firstOperand, double* secondOperand)
{
    double result;
    switch (*operation)
    {
        case 1:
            checkCalculation(*firstOperand + *secondOperand, &result);
            break;
        case 2:
            checkCalculation(*firstOperand - *secondOperand, &result);
            break;
        case 3:
            checkCalculation(*firstOperand * *secondOperand, &result);
            break;
        case 4:
            checkCalculation(*firstOperand / *secondOperand, &result);
            break;
        case 5:
            Calculation(firstOperand, secondOperand, &result);
            break;
    }
    printf("\nResult: %lf\n\n", result);
}

bool isInputValid(int* input)
{
    return ((*input) >= -1 && (*input) <= 5);
}

void UserInput(int* input)
{
    printf("Choose one of the following operations:\n");
    printf("Add (1)\n");
    printf("Subtract (2)\n");
    printf("Multiply (3)\n");
    printf("Divide (4)\n");
    printf("Power (5)\n");
    printf("Stop program (-1)\n");
    do
    {
        if (!isInputValid(input))
        {
            printf("Input not allowed, please try again\n\n");
        }

        printf("Enter your choice: ");
        scanf("%d", input);
    } while (!isInputValid(input));
}


int main(int argc, const char *argv[])
{
    int input;
    double firstNumber;
    double secondNumber;
    do
    {
        UserInput(&input);
        if (input != -1)
        {
            getOperands(&firstNumber, &secondNumber);
            Operation(&input, &firstNumber, &secondNumber);
        }
    }
    while(input != -1);

    return 0;
}
