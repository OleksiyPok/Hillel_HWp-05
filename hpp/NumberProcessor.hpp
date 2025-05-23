#pragma once

#include <memory>
#include <vector>

#include "Interfaces.hpp"

class NumberProcessor {
  INumberReader &reader;
  INumberFilter &filter;
  std::vector<std::unique_ptr<INumberObserver>> observers;

public:
  NumberProcessor(INumberReader &r, INumberFilter &f,
                  std::vector<std::unique_ptr<INumberObserver>> obs);
  void run(const std::string &filename);
};
