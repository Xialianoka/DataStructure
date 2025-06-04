#include "SeqList.h"

#include <gtest/gtest.h>

#include <memory>

class SeqListTest : public ::testing::Test {
 public:
  void SetUp() override {
    list.reset();
    list = std::make_unique<SeqList>();
  }
  void TearDown() override { list.reset(); }

 private:
  std::unique_ptr<SeqList> list;
};

TEST_F(SeqListTest, sequential_list_insert) {
  std::unique_ptr<SeqList> list = std::make_unique<SeqList>();
  list->Insert(10);
  list->Insert(20);
  EXPECT_TRUE(list->Search(10));
  EXPECT_TRUE(list->Search(20));
  EXPECT_FALSE(list->Search(30));
}