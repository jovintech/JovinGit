#include "Utils.hpp"
#include <filesystem>
#include <string>

std::string Utils::getPathCurrent() { return std::filesystem::current_path(); }
