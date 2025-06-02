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

  std::string filter_name;
  std::smatch match;
  std::regex regex_no_number(R"(([A-Za-z]+))");
  std::regex_search(input_filter_name, match, regex_no_number);
  filter_name = match[0];

  auto it = filtersFactoryRegister.find(filter_name);
  if (it != filtersFactoryRegister.end()) {
    return it->second(input_filter_name);
  } else {
    // std::cerr << "Unknown filter: " << input_filter_name << std::endl;
    return nullptr;
  }
}