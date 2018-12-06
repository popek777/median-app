#include "SortedNumbersStream.h"

#include <gtest/gtest.h>
#include <iostream>

TEST(SortedNumbersStreamWithNoNumbersShould, add_number) {
  SortedNumbersStream sns;

  EXPECT_EQ(0, sns.numbers().size());
  sns.pushNext(45);

  ASSERT_EQ(1, sns.numbers().size());
  ASSERT_EQ(45, sns.numbers()[0]);
}

class SortedNumbersStreamWithSingleNumberShould : public testing::Test {
 public:
  SortedNumbersStreamWithSingleNumberShould() { sns.pushNext(6); }

  SortedNumbersStream sns;
};

TEST_F(SortedNumbersStreamWithSingleNumberShould, append_when_number_is_equal) {
  sns.pushNext(6);

  ASSERT_EQ(2, sns.numbers().size());
  ASSERT_EQ(6, sns.numbers()[0]);
  ASSERT_EQ(6, sns.numbers()[1]);
}

TEST_F(SortedNumbersStreamWithSingleNumberShould, append_when_number_is_grater) {
  sns.pushNext(7);

  ASSERT_EQ(2, sns.numbers().size());
  ASSERT_EQ(6, sns.numbers()[0]);
  ASSERT_EQ(7, sns.numbers()[1]);
}

TEST_F(SortedNumbersStreamWithSingleNumberShould,
       prepend_when_number_is_smaller) {
  sns.pushNext(5);

  ASSERT_EQ(2, sns.numbers().size());
  ASSERT_EQ(5, sns.numbers()[0]);
  ASSERT_EQ(6, sns.numbers()[1]);
}

class SortedNumbersStreamWithMultipleNumbersShould : public testing::Test {
 public:
  SortedNumbersStreamWithMultipleNumbersShould() {
    for (auto number : {2, 4, 6, 7, 8, 10}) {
      sns.pushNext(number);
      EXPECT_EQ(number, sns.numbers()[sns.numbers().size() - 1]);
    }
  }

  SortedNumbersStream sns;
};

TEST_F(SortedNumbersStreamWithMultipleNumbersShould,
       insert_non_existing_numbers_in_gaps) {
  sns.pushNext(3);
  EXPECT_EQ(7, sns.numbers().size());
  ASSERT_EQ(3, sns.numbers()[1]);

  sns.pushNext(9);
  EXPECT_EQ(8, sns.numbers().size());
  ASSERT_EQ(9, sns.numbers()[6]);

  sns.pushNext(5);
  EXPECT_EQ(9, sns.numbers().size());
  ASSERT_EQ(5, sns.numbers()[3]);
}

TEST_F(SortedNumbersStreamWithMultipleNumbersShould,
       append_number_grater_then_last_one) {
  sns.pushNext(11);
  EXPECT_EQ(7, sns.numbers().size());
  ASSERT_EQ(11, sns.numbers()[6]);
}
TEST_F(SortedNumbersStreamWithMultipleNumbersShould,
       append_number_equal_to_last_one) {
  sns.pushNext(10);
  EXPECT_EQ(7, sns.numbers().size());
  ASSERT_EQ(10, sns.numbers()[6]);
}

TEST_F(SortedNumbersStreamWithMultipleNumbersShould,
       prepend_number_smaller_then_first_one) {
  sns.pushNext(1);
  EXPECT_EQ(7, sns.numbers().size());
  ASSERT_EQ(1, sns.numbers()[0]);
}
TEST_F(SortedNumbersStreamWithMultipleNumbersShould,
       prepend_number_equal_to_first_one) {
  sns.pushNext(2);
  EXPECT_EQ(7, sns.numbers().size());
  ASSERT_EQ(2, sns.numbers()[0]);
}

TEST(SortedNumbersStreamShould, provide_running_median)
{
  SortedNumbersStream sns;

  sns.pushNext(3);
  sns.pushNext(5);
  ASSERT_DOUBLE_EQ(4., sns.getMedian());

  sns.pushNext(8);
  ASSERT_DOUBLE_EQ(5., sns.getMedian());

  sns.pushNext(6);
  ASSERT_DOUBLE_EQ(5.5, sns.getMedian());
}

