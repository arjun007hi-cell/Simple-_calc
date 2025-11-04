#include <iostream>
#include <limits>   // for std::numeric_limits

int main() {
    std::cout << "Simple Calculator (type 'q' to quit)\n\n";

    while (true) {
        // Show menu
        std::cout << "Choose operation:\n";
        std::cout << "  1) Add (+)\n";
        std::cout << "  2) Subtract (-)\n";
        std::cout << "  3) Multiply (*)\n";
        std::cout << "  4) Divide (/)\n";
        std::cout << "  5) Modulo (%)  (integers only)\n";
        std::cout << "  q) Quit\n";
        std::cout << "Enter choice: ";

        char choice;
        if (!(std::cin >> choice)) break; // handle EOF
        if (choice == 'q' || choice == 'Q') {
            std::cout << "Goodbye!\n";
            break;
        }

        // For modulo we want integers; otherwise use doubles
        if (choice == '5') {
            long long a, b;
            std::cout << "Enter two integers (space separated): ";
            if (!(std::cin >> a >> b)) {
                std::cout << "Invalid input. Try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (b == 0) {
                std::cout << "Error: modulo by zero.\n\n";
                continue;
            }
            std::cout << a << " % " << b << " = " << (a % b) << "\n\n";
            continue;
        }

        double x, y;
        std::cout << "Enter two numbers (space separated): ";
        if (!(std::cin >> x >> y)) {
            std::cout << "Invalid input. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case '1':
                std::cout << x << " + " << y << " = " << (x + y) << "\n\n";
                break;
            case '2':
                std::cout << x << " - " << y << " = " << (x - y) << "\n\n";
                break;
            case '3':
                std::cout << x << " * " << y << " = " << (x * y) << "\n\n";
                break;
            case '4':
                if (y == 0.0) {
                    std::cout << "Error: division by zero.\n\n";
                } else {
                    std::cout << x << " / " << y << " = " << (x / y) << "\n\n";
                }
                break;
            default:
                std::cout << "Unknown option. Please choose 1-5 or q.\n\n";
                break;
        }
    }

    return 0;
}
