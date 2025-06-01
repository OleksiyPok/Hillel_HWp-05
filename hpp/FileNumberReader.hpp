#pragma once

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "../hpp/Interfaces.hpp"

class FileNumberReader : public INumberReader {
public:
  std::vector<int> read_numbers(const std::string &filename) override;
};