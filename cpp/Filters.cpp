#include "Filters.hpp"

bool EvenFilter::keep(int number) const { return number % 2 == 0; }

bool OddFilter::keep(int number) const { return number % 2 != 0; }

GreaterThanFilter::GreaterThanFilter(int t) : threshold(t) {}
bool GreaterThanFilter::keep(int number) const { return number > threshold; }

LessThanFilter::LessThanFilter(int t) : threshold(t) {}
bool LessThanFilter::keep(int number) const { return number < threshold; }
