#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>

class Calculator {
private:
    // Constants for formatting
    static constexpr int PRECISION = 6;
    static constexpr char SEPARATOR[] = "----------------------------------------";

    // Helper functions
    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool isValidNumber(double& number) {
        if (!(std::cin >> number)) {
            clearInputBuffer();
            std::cout << "Error: Invalid number. Please enter a valid number.\n";
            return false;
        }
        return true;
    }

    void displayMenu() {
        std::cout << "\nAvailable Operations:\n"
                  << "1. Addition (+)\n"
                  << "2. Subtraction (-)\n"
                  << "3. Multiplication (*)\n"
                  << "4. Division (/)\n"
                  << "5. Power (^)\n"
                  << "6. Square Root (√)\n"
                  << "7. Percentage (%)\n"
                  << "8. Exit\n";
    }

public:
    void run() {
        std::cout << "\n=== Professional Calculator ===\n";
        
        while (true) {
            displayMenu();
            std::cout << SEPARATOR << '\n';

            char operation;
            std::cout << "Select operation (1-8): ";
            std::cin >> operation;
            clearInputBuffer();

            // Exit condition
            if (operation == '8') {
                std::cout << "\nThank you for using the Professional Calculator!\n";
                break;
            }

            // Handle single operand operations first
            if (operation == '6') {  // Square Root
                double number;
                std::cout << "Enter number: ";
                if (!isValidNumber(number)) continue;

                if (number < 0) {
                    std::cout << "Error: Cannot calculate square root of a negative number.\n";
                    continue;
                }

                std::cout << "√" << number << " = " 
                          << std::fixed << std::setprecision(PRECISION) 
                          << std::sqrt(number) << '\n';
                continue;
            }

            // Handle two operand operations
            double num1, num2;
            std::cout << "Enter first number: ";
            if (!isValidNumber(num1)) continue;

            std::cout << "Enter second number: ";
            if (!isValidNumber(num2)) continue;

            std::cout << std::fixed << std::setprecision(PRECISION);

            switch (operation) {
                case '1': // Addition
                    std::cout << num1 << " + " << num2 << " = " << num1 + num2 << '\n';
                    break;

                case '2': // Subtraction
                    std::cout << num1 << " - " << num2 << " = " << num1 - num2 << '\n';
                    break;

                case '3': // Multiplication
                    std::cout << num1 << " × " << num2 << " = " << num1 * num2 << '\n';
                    break;

                case '4': // Division
                    if (num2 == 0) {
                        std::cout << "Error: Division by zero is undefined.\n";
                    } else {
                        std::cout << num1 << " ÷ " << num2 << " = " << num1 / num2 << '\n';
                    }
                    break;

                case '5': // Power
                    std::cout << num1 << " ^ " << num2 << " = " << std::pow(num1, num2) << '\n';
                    break;

                case '7': // Percentage
                    std::cout << num1 << " % of " << num2 << " = " << (num1 * num2) / 100.0 << '\n';
                    break;

                default:
                    std::cout << "Error: Invalid operation selected.\n";
            }

            std::cout << SEPARATOR << '\n';
        }
    }
};

int main() {
    Calculator calc;
    calc.run();
    return 0;
}