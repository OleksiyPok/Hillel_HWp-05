#pragma once

#include <string>
#include <vector>

#include "Interfaces.hpp"

class FileNumberReader : public INumberReader {
public:
  std::vector<int> read_numbers(const std::string &filename) override;
};