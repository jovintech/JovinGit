#include "Commands.hpp"
#include <array>
#include <memory>
#include <stdexcept>
#include <string>

std::string Commands::sendCommand(const std::string &command) {
  std::array<char, 128> buffer;
  std::string result;

  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"),
                                                pclose);

  if (!pipe) {
    throw std::runtime_error("command error");
  }

  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }

  return result;
}
