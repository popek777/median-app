#include "App.h"

#include <iostream>
#include <string>

int main() {
  std::string input;
  std::getline(std::cin, input);

  App app;
  app.run(input);

  return 0;
}
