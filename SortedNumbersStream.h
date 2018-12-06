#pragma once

#include "Vector.h" 

class SortedNumbersStream {
 public:
  void pushNext(int number);

  const Vector<int>& numbers() const { return numbers_; }

  double getMedian() const;

 private:
  Vector<int> numbers_;
};
