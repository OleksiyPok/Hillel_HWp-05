#pragma once

#include "Interfaces.hpp"

class EvenFilter : public INumberFilter {
public:
  bool keep(int number) const override;
};

class OddFilter : public INumberFilter {
public:
  bool keep(int number) const override;
};

class GreaterThanFilter : public INumberFilter {
  int threshold;

public:
  explicit GreaterThanFilter(int t);
  bool keep(int number) const override;
};

class LessThanFilter : public INumberFilter {
  int threshold;

public:
  explicit LessThanFilter(int t);
  bool keep(int number) const override;
};