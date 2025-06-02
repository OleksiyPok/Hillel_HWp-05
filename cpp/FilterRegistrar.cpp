#include "../hpp/FilterRegistrar.hpp"

void FilterRegistrar::register_all_filters(FilterFactory &factory) {
  factory.register_factory({[](const std::string &fkey) { return fkey == "ALL"; },
                            [](const std::string &) { return std::make_unique<AllFilter>(); }});

  factory.register_factory({[](const std::string &fkey) { return fkey == "EVEN"; },
                            [](const std::string &) { return std::make_unique<EvenFilter>(); }});

  factory.register_factory({[](const std::string &fkey) { return fkey == "ODD"; },
                            [](const std::string &) { return std::make_unique<OddFilter>(); }});

  factory.register_factory(
      {[](const std::string &fkey) { return std::regex_match(fkey, std::regex("GT\\d+")); },
       [](const std::string &fkey) {
         int n = std::stoi(fkey.substr(2));
         return std::make_unique<GreaterThanFilter>(n);
       }});

  factory.register_factory(
      {[](const std::string &fkey) { return std::regex_match(fkey, std::regex("LT\\d+")); },
       [](const std::string &fkey) {
         int n = std::stoi(fkey.substr(2));
         return std::make_unique<LessThanFilter>(n);
       }});
}
