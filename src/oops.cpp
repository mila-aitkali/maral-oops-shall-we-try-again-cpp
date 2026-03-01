#include "oops.hpp"
#include <iostream>

std::optional<int> getValidatedInput(
    int lowerBound,
    int upperBound,
    const std::string& prompt,
    const std::string& errorMessage,
    std::optional<int> defaultValue)
{
    while (true)
    {
        std::cout << prompt;
        if (defaultValue.has_value())
            std::cout << " Enter \"default\" to use the default value of "
                      << defaultValue.value() << ".";
        std::cout << " Enter \"exit\" to leave the menu." << std::endl;

        std::string input;
        std::getline(std::cin, input);

        if (input == "exit")
            return std::nullopt;

        if (input == "default")
        {
            if (defaultValue.has_value())
            {
                std::cout << "\nThe value chosen by the user is "
                          << defaultValue.value() << std::endl;
                return defaultValue;
            }
            else
            {
                std::cout << "\nNo default value was provided. " << errorMessage << "\n\n";
                continue;
            }
        }

        try
        {
            size_t pos;
            int value = std::stoi(input, &pos);

            if (pos != input.size())
                throw std::invalid_argument("trailing characters");

            if (value >= lowerBound && value <= upperBound)
            {
                std::cout << "\nThe value chosen by the user is " << value << std::endl;
                return value;
            }
            else
            {
                std::cout << "\n" << errorMessage << "\n\n";
            }
        }
        catch (const std::exception&)
        {
            std::cout << "\n" << errorMessage << "\n\n";
        }
    }
}