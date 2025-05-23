#pragma once

#include <memory>
#include <string>

#include "../hpp/Interfaces.hpp"

class FilterFactory {
public:
  static std::unique_ptr<INumberFilter>
  create_filter(const std::string &filter_name);
};
