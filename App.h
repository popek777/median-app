#pragma once

#include "Heap.h"

#include <iostream>
#include <string>

class App
{
 public:
  App(std::ostream& out = std::cout);
  void run(const std::string& appInput);

 private:
  void consume(int number);

  double getMedian() const;

  std::ostream& out_;

  MaxHeap left_;
  MinHeap right_;
};

