#include "../hpp/FilterFactory.hpp"

FilterFactory::FilterFactory() = default;

FilterFactory &FilterFactory::get_instance() {
  static FilterFactory instance;
  return instance;
}

void FilterFactory::register_factory(FilterFactoryEntry entry) {
  entries.push_back(std::move(entry));
}

std::unique_ptr<INumberFilter>
FilterFactory::create_filter(const std::string &input_filter_name) const {

  for (const auto &entry : entries) {
    if (entry.matches(input_filter_name)) {
      return entry.create(input_filter_name);
    }
  }

  return std::unique_ptr<INumberFilter>(nullptr);
}