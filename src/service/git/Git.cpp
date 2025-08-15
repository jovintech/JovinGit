#include "Git.hpp"
#include "Commands.hpp"
#include <string>

std::string Git::getBranchCurrent() {
  return Commands::sendCommand("git branch --show-current");
};
