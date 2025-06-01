
// HW-05. Відпрацювання патернів Observer, Strategy, Factory, та принципів SOLID
//-----------------------------------------------

#include "main.hpp"

int main(int argc, char **argv) {
  try {
    if (argc != 3) {
      std::cerr << ">> Usage: \"" << std::filesystem::path(argv[0]).filename().string()
                << " <filter> <filename>\"\n";
      std::cerr << ">> Filters: ALL, EVEN, ODD, GT<n>, LT<n>\n";
      return 1;
    }

    std::string input_filterName = argv[1];
    std::string filename = argv[2];

    FilterFactory &filterFactory = FilterFactory::get_instance();
    FilterRegistrar::register_all_filters(filterFactory);

    std::unique_ptr<INumberFilter> filter = filterFactory.create_filter(input_filterName);

    if (!filter) {
      std::cerr << "Unknown filter name: " << input_filterName << std::endl;
      return 1;
    }

    FileNumberReader reader;
    std::vector<std::unique_ptr<INumberObserver>> observers;

    observers.push_back(std::make_unique<PrintObserver>());
    observers.push_back(std::make_unique<CountObserver>());

    NumberProcessor processor(reader, *filter, std::move(observers));
    processor.run(filename);
    return 0;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "Unknown error" << std::endl;
    return 1;
  }
}