#include "Vector.h" 

#include <gtest/gtest.h>

TEST(VectorShould, push_back_on_insert_on_size_plus_one_pos)
{
  Vector<int> v;

  v.insertAt(0, 53);

  ASSERT_EQ(1, v.size());
  ASSERT_EQ(53, v[0]);
}

TEST(VectorShould, add_element_appropriate_position_on_insert)
{
  Vector<int> v;
  for(auto e : {0, 10, 20, 30, 40, 50})
    v.insertAt(v.size(), e);

  v.insertAt(3, 433);

  ASSERT_EQ(7, v.size());
  auto index = 0u;
  for (auto e : {0, 10, 20, 433, 30, 40, 50}) ASSERT_EQ(e, v[index++]);
}

TEST(
    VectorShould,
    preserve_content_and_increase_capacity_when_current_one_is_overflown_on_insert) {
  auto initialCapacity{10};
  Vector<int> v(initialCapacity);

  for (auto i = 0; i < initialCapacity; ++i)
    v.insertAt(v.size(), i*5);

  EXPECT_EQ(initialCapacity, v.capacity());

  v.insertAt(2, 9433);

  ASSERT_EQ(1.3*initialCapacity, v.capacity());

  auto index = 0u;
  for (auto e : {0, 5, 9433, 10, 15, 20, 25, 30, 35, 40, 45}) ASSERT_EQ(e, v[index++]);
}
