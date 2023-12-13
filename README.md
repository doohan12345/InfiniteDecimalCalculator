# InfiniteDecimalCalculator
# include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    
     printf("Enter operator (+, -, *, /): ");
    scanf("%c", &operator);

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero.\n");
                return 1; // Exit the program with an error code
            }
            break;
        default:
            printf("%c", "Is not valid operator.\n");
            return 1; // Exit the program with an error code
    }

    printf("Result: %3lf\n", result);

    return 0; // Return 0 to indicate successful execution
}
