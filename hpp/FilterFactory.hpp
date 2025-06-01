#pragma once

#include <functional>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <unordered_map>

#include "../hpp/Filters.hpp"
#include "../hpp/Interfaces.hpp"

class FilterFactory {
private:
  FilterFactory();
  FilterFactory(const FilterFactory &) = delete;
  FilterFactory &operator=(const FilterFactory &) = delete;

  using FilterFactoryMethod = std::function<std::unique_ptr<INumberFilter>(const std::string &)>;

  std::unordered_map<std::string, FilterFactoryMethod> filtersFactoryRegister;

public:
  static FilterFactory &get_instance();

  void register_factory(const std::string &registered_filter_name,
                        FilterFactoryMethod factory_method);

  std::unique_ptr<INumberFilter> create_filter(const std::string &input_filter_name) const;
};
