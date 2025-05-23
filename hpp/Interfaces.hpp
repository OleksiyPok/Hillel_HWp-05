#pragma once

#include <string>
#include <vector>

class INumberReader {
public:
  virtual std::vector<int> read_numbers(const std::string &filename) = 0;
  virtual ~INumberReader() = default;
};

class INumberFilter {
public:
  virtual bool keep(int number) const = 0;
  virtual ~INumberFilter() = default;
};

class INumberObserver {
public:
  virtual void on_number(int) = 0;
  virtual void on_finished() = 0;
  virtual ~INumberObserver() = default;
};