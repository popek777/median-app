#include "App.h"

App::App(std::ostream& out) : out_(out) {}

void App::run(const std::string& appInput) {
  int value = 0;
  bool skipPush = false;

  for (auto c : appInput) {
    if (' ' == c) {
      if (not skipPush) sns_.pushNext(value);
      skipPush = false;
      value = 0;

    } else if ('m' == c) {
      skipPush = true;
      out_ << sns_.getMedian() << " ";

    } else if ('q' != c) {
      value *= 10;
      value += (c - 48);
    }
  }
}
