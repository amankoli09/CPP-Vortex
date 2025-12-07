#include <iostream>
using namespace std;

// Define a class named Calsi for basic calculator operations
class Calsi {
private:
    int num1; // First number
    int num2; // Second number

public:
    // Method to set the values of num1 and num2
    void setdata(int a, int b) {
        num1 = a;
        num2 = b;
    }

    // Method to add num1 and num2
    int add() {
        return num1 + num2;
    }

    // Method to subtract num2 from num1
    int sub() {
        return num1 - num2;
    }

    // Method to multiply num1 and num2
    int mul() {
        return num1 * num2;
    }

    // Method to find the modulus of num1 and num2
    int mod() {
        return num1 % num2;
    }

    // Method to divide num1 by num2
    int div() {
        if (num2 != 0) {
            return num1 / num2;
        } else {
            cout << "OOPS, sorry, result is not defined" << endl;
            return 0; // Return 0 if division by zero
        }
    }
};

int main() {
    Calsi calculator; // Create an object of class Calsi
    int a, b; // Variables to store user input numbers
    char oper; // Variable to store the operator

    // Prompt the user to enter the first number
    cout << "Enter the first number: " << endl;
    cin >> a;

    // Prompt the user to enter the second number
    cout << "Enter the second number: " << endl;
    cin >> b;

    // Prompt the user to enter the operator
    cout << "Enter the operator to perform operation (+, -, *, %, /):" << endl;
    cin >> oper;

    // Set the numbers in the calculator object
    calculator.setdata(a, b);

    // Perform the operation based on the entered operator
    switch (oper) {
        case '+':
            cout << "Addition of the entered numbers is = " << calculator.add();
            break;
        case '-':
            cout << "Subtraction of the entered numbers is = " << calculator.sub();
            break;
        case '*':
            cout << "Multiplication of the entered numbers is = " << calculator.mul();
            break;
        case '%':
            cout << "Modulus of the entered numbers is = " << calculator.mod();
            break;
        case '/':
            cout << "Division of the entered numbers is = " << calculator.div();
            break;
        default:
            cout << "Oops, invalid operator" << endl;
            break;
    }

    return 0;
}