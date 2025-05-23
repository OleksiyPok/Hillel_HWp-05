#include "NumberProcessor.hpp"

NumberProcessor::NumberProcessor(
    INumberReader &r, INumberFilter &f,
    std::vector<std::unique_ptr<INumberObserver>> obs)
    : reader(r), filter(f), observers(std::move(obs)) {}

void NumberProcessor::run(const std::string &filename) {
  std::vector<int> numbers = reader.read_numbers(filename);
  for (int number : numbers) {
    if (filter.keep(number)) {
      for (auto &observer : observers) {
        observer->on_number(number);
      }
    }
  }
  for (auto &observer : observers) {
    observer->on_finished();
  }
}
