#include "../hpp/FilterFactory.hpp"

FilterFactory::FilterFactory() = default;

FilterFactory &FilterFactory::get_instance() {
  static FilterFactory instance;
  return instance;
}

void FilterFactory::register_factory(const std::string &registered_filter_name,
                                     FilterFactoryMethod factory_method) {
  filtersFactoryRegister[registered_filter_name] = factory_method;
}

std::unique_ptr<INumberFilter>
FilterFactory::create_filter(const std::string &input_filter_name) const {
  std::regex regex_with_number(R"(([A-Za-z]+)(\d+))");
  std::regex regex_no_number(R"(([A-Za-z]+))");
  std::smatch match;

  std::string filter_name;

  if (std::regex_match(input_filter_name, match, regex_with_number)) {
    filter_name = match[1]; // GT or LT
  } else if (std::regex_match(input_filter_name, match, regex_no_number)) {
    filter_name = match[1]; // EVEN, ODD
  } else {
    std::cerr << "Invalid filter format: " << input_filter_name << std::endl;
    return nullptr;
  }

  auto it = filtersFactoryRegister.find(filter_name);
  if (it != filtersFactoryRegister.end()) {
    return it->second(input_filter_name);
  } else {
    std::cerr << "Unknown filter: " << filter_name << std::endl;
    return nullptr;
  }
}