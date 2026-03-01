#include <iostream>
#include "oops.hpp"

int main()
{
    std::cout << "=== Test 1: Basic range [1, 10], no default ===\n";
    auto result1 = getValidatedInput(
        1, 10,
        "Please enter a value between 1 and 10.",
        "Your value is invalid.");

    if (!result1.has_value())
        std::cout << "(User aborted — no value returned.)\n";

    std::cout << "\n=== Test 2: Range [0, 100] with default value of 50 ===\n";
    auto result2 = getValidatedInput(
        0, 100,
        "Please enter a value between 0 and 100.",
        "Your value is invalid.",
        50);

    if (!result2.has_value())
        std::cout << "(User aborted — no value returned.)\n";

    std::cout << "\n=== Test 3: Menu choice [1, 3] ===\n";
    auto result3 = getValidatedInput(
        1, 3,
        "Choose a menu option (1=New Game, 2=Load, 3=Quit).",
        "Please enter 1, 2, or 3.");

    if (!result3.has_value())
        std::cout << "(User aborted — no value returned.)\n";

    return 0;
}