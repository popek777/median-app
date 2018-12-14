#include "App.h"

App::App(std::ostream& out) : out_(out) {}

void App::run(const std::string& appInput) {
  int value = 0;
  bool skipPush = false;

  for (auto c : appInput) {
    if (' ' == c) {
      if (not skipPush) consume(value);
      skipPush = false;
      value = 0;

    } else if ('m' == c) {
      skipPush = true;
      out_ << getMedian() << " ";

    } else if ('q' != c) {
      value *= 10;
      value += (c - 48);
    }
  }

}

void App::consume(int number) {
  if (0 == left_.size()) {
    left_.insert(number);
    return;
  }

  if (number < left_.root()) {
    left_.insert(number);
    if (left_.size() > right_.size() + 1) {
      right_.insert(left_.root());
      left_.dropRoot();
    }
  } else {
    right_.insert(number);
    if (right_.size() > left_.size() + 1) {
      left_.insert(right_.root());
      right_.dropRoot();
    }
  }
}

double App::getMedian() const {
  if (left_.size() == right_.size())
    return static_cast<double>(left_.root() + right_.root()) / 2;
  else if (left_.size() > right_.size())
    return left_.root();
  else
    return right_.root();
}
