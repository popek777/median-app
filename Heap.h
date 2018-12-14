#pragma once

#include "Vector.h"

template<typename Pred>
class Heap
{
 public:
  unsigned size() const { return vector_.size(); }

  int root() const { return vector_[0]; };

  void insert(int elem) {
    vector_.pushBack(elem);
    siftUp(vector_.size() - 1);

    assert(validateHeapInvariant());
  }

  void dropRoot() {
    vector_.popFront();

    if (0 == vector_.size()) return;

    auto toGo = vector_.size();
    while (toGo) siftDown(--toGo);

    assert(validateHeapInvariant());
  }

 private:
  void siftUp(unsigned childIndex) {
    if (0 == childIndex) return;

    Pred pred;

    auto parentIndex = getParentIndex(childIndex);
    while (not pred(vector_[parentIndex], vector_[childIndex])) {
      vector_.swap(childIndex, parentIndex);

      if (0 == parentIndex) return;

      childIndex = parentIndex;
      parentIndex = getParentIndex(childIndex);
    }
  }

  void siftDown(unsigned parentIndex) {
    if (parentIndex >= vector_.size()) return;

    Pred pred;

    auto lci = getLeftChildIndex(parentIndex);
    auto rci = getRightChildIndex(parentIndex);

    while (lci < vector_.size() or rci < vector_.size()) {
      auto childIndex =
          (rci == vector_.size() or pred(vector_[lci], vector_[rci])) ? lci
                                                                      : rci;

      if (not pred(vector_[childIndex], vector_[parentIndex])) break;

      vector_.swap(childIndex, parentIndex);

      parentIndex = childIndex;
      lci = getLeftChildIndex(parentIndex);
      rci = getRightChildIndex(parentIndex);
    }
  }

  bool validateHeapInvariant() const {
    Pred pred;
    for (auto parentIndex = 0u; parentIndex < vector_.size() / 2;
         ++parentIndex) {
      auto lci = getLeftChildIndex(parentIndex);
      auto rci = getRightChildIndex(parentIndex);
      if (lci >= vector_.size()) break;

      if (pred(vector_[lci], vector_[parentIndex])) return false;

      if (rci >= vector_.size()) break;
      if (pred(vector_[rci], vector_[parentIndex])) return false;
    }
    return true;
  }

  unsigned getParentIndex(unsigned childIndex) const {
    return childIndex % 2 ? (childIndex - 1) / 2 : childIndex / 2 - 1;
  }
  unsigned getLeftChildIndex(unsigned parentIndex) const {
    return 2 * parentIndex + 1;
  }
  unsigned getRightChildIndex(unsigned parentIndex) const {
    return 2 * parentIndex + 2;
  }

  Vector<int> vector_;
};

struct grater_then {
  bool operator()(int l, int r) const { return l > r; };
};
struct less_then {
  bool operator()(int l, int r) const { return l < r; };
};

using MaxHeap = Heap<grater_then>;
using MinHeap = Heap<less_then>;
