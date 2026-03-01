#pragma once
#include <string>
#include <optional>

std::optional<int> getValidatedInput(
    int lowerBound,
    int upperBound,
    const std::string& prompt,
    const std::string& errorMessage,
    std::optional<int> defaultValue = std::nullopt);