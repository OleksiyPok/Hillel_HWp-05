#pragma once

#include <iostream>

#include "../hpp/Interfaces.hpp"

class PrintObserver : public INumberObserver {
public:
  void on_number(int number) override;
  void on_finished() override;
};

class CountObserver : public INumberObserver {
  int count = 0;

public:
  void on_number(int number) override;
  void on_finished() override;
};
