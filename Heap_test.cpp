#include "Heap.h"

#include <gtest/gtest.h>

#include <cmath>

class MaxHeapTest : public testing::Test {
 public:
  MaxHeapTest() {
    for (auto elem : {3, 1, 17, 25, 19, 2, 100, 19, 36, 2}) heap.insert(elem);
  }

  MaxHeap heap;
};

TEST_F(MaxHeapTest, root_is_max) { ASSERT_EQ(100, heap.root()); }

TEST_F(MaxHeapTest, drop_root_establish_new_max) {

  heap.dropRoot();
  ASSERT_EQ(36, heap.root());

  heap.dropRoot();
  ASSERT_EQ(25, heap.root());

  heap.dropRoot();
  ASSERT_EQ(19, heap.root());

  heap.dropRoot();
  ASSERT_EQ(19, heap.root());

  heap.dropRoot();
  ASSERT_EQ(17, heap.root());

  heap.dropRoot();
  ASSERT_EQ(3, heap.root());

  heap.dropRoot();
  ASSERT_EQ(2, heap.root());

  heap.dropRoot();
  ASSERT_EQ(2, heap.root());

  heap.dropRoot();
  ASSERT_EQ(1, heap.root());
}

class MinHeapTest : public testing::Test {
 public:
  MinHeapTest() {
    for (auto elem : {13, 101, 12, 17, 45, 25, 43, 100, 25, 19, 36, 4})
      heap.insert(elem);
  }

  MinHeap heap;
};

TEST_F(MinHeapTest, root_is_min) { ASSERT_EQ(4, heap.root()); }

TEST_F(MinHeapTest, drop_root_establish_new_min) {
  heap.dropRoot();
  ASSERT_EQ(12, heap.root());
  heap.dropRoot();
  ASSERT_EQ(13, heap.root());
  heap.dropRoot();
  ASSERT_EQ(17, heap.root());
  heap.dropRoot();
  ASSERT_EQ(19, heap.root());
  heap.dropRoot();
  ASSERT_EQ(25, heap.root());
  heap.dropRoot();
  ASSERT_EQ(25, heap.root());
  heap.dropRoot();
  ASSERT_EQ(36, heap.root());
  heap.dropRoot();
  ASSERT_EQ(43, heap.root());
  heap.dropRoot();
  ASSERT_EQ(45, heap.root());
  heap.dropRoot();
  ASSERT_EQ(100, heap.root());
  heap.dropRoot();
  ASSERT_EQ(101, heap.root());
}

