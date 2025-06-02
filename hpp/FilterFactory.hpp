#pragma once

#include <functional>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <unordered_map>

#include "../hpp/Filters.hpp"
#include "../hpp/Interfaces.hpp"

struct FilterFactoryEntry {
  std::function<bool(const std::string &)> matches;
  std::function<std::unique_ptr<INumberFilter>(const std::string &)> create;
};

class FilterFactory {
private:
  FilterFactory();
  FilterFactory(const FilterFactory &) = delete;
  FilterFactory &operator=(const FilterFactory &) = delete;

  std::vector<FilterFactoryEntry> entries;

public:
  static FilterFactory &get_instance();

  void register_factory(FilterFactoryEntry entry);

  std::unique_ptr<INumberFilter> create_filter(const std::string &input_filter_name) const;
};
