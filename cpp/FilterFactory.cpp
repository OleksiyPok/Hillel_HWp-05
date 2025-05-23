#include <iostream>
#include <regex>

#include "../hpp/FilterFactory.hpp"
#include "../hpp/Filters.hpp"

std::unique_ptr<INumberFilter>
FilterFactory::create_filter(const std::string &filter_name) {
  if (filter_name == "ALL") {
    return std::make_unique<AllFilter>();
  }
  if (filter_name == "EVEN") {
    return std::make_unique<EvenFilter>();
  }
  if (filter_name == "ODD") {
    return std::make_unique<OddFilter>();
  }
  if (filter_name.starts_with("GT")) {
    std::regex rgx("GT(\\d+)");
    std::smatch match;
    if (std::regex_match(filter_name, match, rgx)) {
      int value = std::stoi(match[1]);
      return std::make_unique<GreaterThanFilter>(value);
    }
  }
  if (filter_name.starts_with("LT")) {
    std::regex rgx("LT(\\d+)");
    std::smatch match;
    if (std::regex_match(filter_name, match, rgx)) {
      int value = std::stoi(match[1]);
      return std::make_unique<LessThanFilter>(value);
    }
  }

  std::cerr << "Error: Unknown filter name '" << filter_name << "'."
            << std::endl
            << "Filters: EVEN, ODD, GT<n>, LT<n>" << std::endl
            << std::endl;
  return nullptr;
}
