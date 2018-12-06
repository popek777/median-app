#pragma once

#include "SortedNumbersStream.h"

#include <iostream>
#include <string>

class App
{
 public:
  App(std::ostream& out = std::cout);
  void run(const std::string& appInput);

 private:
  std::ostream& out_;

  SortedNumbersStream sns_;
};

