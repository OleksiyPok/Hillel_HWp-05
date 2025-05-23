
// HW-05. Відпрацювання патернів Observer, Strategy, Factory, та принципів SOLID
//-----------------------------------------------

#include "main.hpp"

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Usage: \""
              << std::filesystem::path(argv[0]).filename().string()
              << " <filter> <filename>\"\n";
    std::cerr << "Filters: EVEN, ODD, GT<n>, LT<n>\n";
    return 1;
  }

  std::string filter_arg = argv[1];
  std::string filename = argv[2];

  try {
    auto filter = FilterFactory::create_filter(filter_arg);
    if (!filter) {
      return 1;
    }

    FileNumberReader reader;
    {
      // std::vector<int> raw_numbers = reader.read_numbers(filename);

      // for (int n : raw_numbers) {
      //   std::cout << n << std::endl;
      // };
    }
    std::vector<std::unique_ptr<INumberObserver>> observers;
    observers.push_back(std::make_unique<PrintObserver>());
    observers.push_back(std::make_unique<CountObserver>());

    NumberProcessor processor(reader, *filter, std::move(observers));
    processor.run(filename);

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}