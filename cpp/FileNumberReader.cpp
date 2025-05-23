#include <fstream>
#include <stdexcept>

#include "../hpp/FileNumberReader.hpp"

std::vector<int> FileNumberReader::read_numbers(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file: " + filename);
  }

  std::vector<int> numbers;
  int number;
  while (file >> number) {
    numbers.push_back(number);
  }

  return numbers;
}