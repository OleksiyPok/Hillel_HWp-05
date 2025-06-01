#include "../hpp/FilterRegistrar.hpp"

void FilterRegistrar::register_all_filters(FilterFactory &factory) {
  factory.register_factory("ALL",
                           [](const std::string &) { return std::make_unique<AllFilter>(); });

  factory.register_factory("EVEN",
                           [](const std::string &) { return std::make_unique<EvenFilter>(); });

  factory.register_factory("ODD",
                           [](const std::string &) { return std::make_unique<OddFilter>(); });

  factory.register_factory(
      "GT", [](const std::string &input_filterName) -> std::unique_ptr<INumberFilter> {
        std::regex rgx("GT(\\d+)");
        std::smatch match;
        if (std::regex_match(input_filterName, match, rgx)) {
          int threshold = std::stoi(match[1]);
          return std::make_unique<GreaterThanFilter>(threshold);
        }
        return std::unique_ptr<INumberFilter>(nullptr);
      });

  factory.register_factory(
      "LT", [](const std::string &input_filterName) -> std::unique_ptr<INumberFilter> {
        std::regex rgx("LT(\\d+)");
        std::smatch match;
        if (std::regex_match(input_filterName, match, rgx)) {
          int threshold = std::stoi(match[1]);
          return std::make_unique<LessThanFilter>(threshold);
        }
        return std::unique_ptr<INumberFilter>(nullptr);
      });
}
