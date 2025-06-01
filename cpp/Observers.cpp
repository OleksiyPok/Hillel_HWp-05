#include "../hpp/Observers.hpp"

void PrintObserver::on_number(int number) { std::cout << "Number: " << number << std::endl; }

void PrintObserver::on_finished() { std::cout << "Processor finished." << std::endl; }

void CountObserver::on_number(int number) { ++count; }

void CountObserver::on_finished() { std::cout << "Quantity of numbers: " << count << std::endl; }
