#pragma once

#include <memory>
#include <regex>

#include "../hpp/FilterFactory.hpp"
#include "../hpp/Filters.hpp"

class FilterRegistrar {
public:
  static void register_all_filters(FilterFactory &factory);
};
