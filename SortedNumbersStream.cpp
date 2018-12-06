#include "SortedNumbersStream.h"

void SortedNumbersStream::pushNext(int value) {
  auto pos = 0u;
  auto step = 0u;
  auto count = numbers_.size();

  while (count > 0) {
    step = count / 2;
    if (value > numbers_[pos + step]) {
      pos += step + 1;
      count -= step + 1;
    } else
      count = step;
  }
  numbers_.insertAt(pos, value);
  return;
}

double SortedNumbersStream::getMedian() const {
  assert(numbers_.size() > 0);

  auto index = numbers_.size() / 2;

  if (numbers_.size() % 2) return numbers_[index];

  return static_cast<double>(numbers_[index] + numbers_[index - 1]) / 2.;
}
