#include "SequentialList.h"

#include <gtest/gtest.h>

#include <memory>
#include <string>

class SequentialListTest : public ::testing::Test {
 protected:
  void SetUp() override {
    list_.reset();
    list_ = std::make_unique<SequentialList<std::string>>();
  }
  void TearDown() override { list_.reset(); }

  std::unique_ptr<SequentialList<std::string>> list_;
};

// 增
TEST_F(SequentialListTest, sequential_list_insert) {
  EXPECT_EQ(list_->QueryByValue("a"), -1);
  EXPECT_TRUE(list_->Push(1, "a"));
  EXPECT_EQ(list_->Size(), 1);
  EXPECT_EQ(list_->QueryByValue("a"), 1);

  EXPECT_EQ(list_->QueryByValue("b"), -1);
  EXPECT_TRUE(list_->PushFront("b"));
  EXPECT_EQ(list_->Size(), 2);
  EXPECT_EQ(list_->QueryByIndex(1), "b");

  EXPECT_EQ(list_->QueryByValue("c"), -1);
  EXPECT_TRUE(list_->PushBack("c"));
  EXPECT_EQ(list_->Size(), 3);
  EXPECT_EQ(list_->QueryByIndex(3), "c");
}

// 删
TEST_F(SequentialListTest, sequential_list_delete) {
  EXPECT_TRUE(list_->PushBack("a"));
  EXPECT_TRUE(list_->PushBack("b"));
  EXPECT_TRUE(list_->PushBack("c"));

  EXPECT_EQ(list_->Size(), 3);
  EXPECT_EQ(list_->EraseByIndex(1), "a");
  EXPECT_EQ(list_->Size(), 2);

  EXPECT_EQ(list_->EraseByVale("b"), 1);
  EXPECT_EQ(list_->Size(), 1);
  EXPECT_EQ(list_->QueryByValue("b"), -1);
}

// 改
TEST_F(SequentialListTest, Sequential_list_update) {
  EXPECT_TRUE(list_->PushBack("a"));
  EXPECT_TRUE(list_->PushBack("b"));
  EXPECT_TRUE(list_->PushBack("c"));

  EXPECT_TRUE(list_->UpdateByIndex(1, "d"));
  EXPECT_EQ(list_->QueryByIndex(1), "d");
  EXPECT_TRUE(list_->UpdateByValue("b", "e"));
  EXPECT_EQ(list_->QueryByValue("e"), 2);
}

// 边界条件测试
TEST_F(SequentialListTest, BoundaryConditions) {
  // 1. 空列表操作测试
  EXPECT_EQ(list_->Size(), 0);
  EXPECT_FALSE(list_->EraseByVale("nonexistent"));  // 空列表删除
  EXPECT_FALSE(list_->UpdateByIndex(1, "value"));   // 空列表更新
  EXPECT_EQ(list_->QueryByIndex(1), "");            // 空列表查询
  EXPECT_EQ(list_->EraseByIndex(1), "");            // 空列表删除索引
  EXPECT_EQ(list_->QueryByValue("any"), -1);        // 空列表值查询

  // 2. 非法索引测试
  EXPECT_FALSE(list_->Push(0, "invalid"));   // 索引0无效
  EXPECT_FALSE(list_->Push(-1, "invalid"));  // 负索引无效
  EXPECT_FALSE(list_->Push(2, "invalid"));   // 超过size+1的索引

  // 3. 容量扩张测试
  for (int i = 1; i <= 100; ++i) {  // 强制触发多次扩容
    EXPECT_TRUE(list_->PushBack("elem_" + std::to_string(i)));
  }
  EXPECT_GE(list_->Capacity(), 100);  // 容量应不小于元素数量
  EXPECT_EQ(list_->Size(), 100);

  // 4. 首尾插入删除
  list_->Reset();
  EXPECT_TRUE(list_->PushFront("head"));
  EXPECT_TRUE(list_->PushBack("tail"));
  EXPECT_EQ(list_->QueryByIndex(1), "head");
  EXPECT_EQ(list_->QueryByIndex(list_->Size()), "tail");

  // 5. 相等值操作测试
  list_->Reset();
  EXPECT_TRUE(list_->PushBack("dup"));
  EXPECT_TRUE(list_->PushBack("dup"));
  EXPECT_TRUE(list_->EraseByVale("dup"));    // 应只删除第一个匹配项
  EXPECT_EQ(list_->QueryByValue("dup"), 1);  // 应剩下一个dup
  EXPECT_EQ(list_->Size(), 1);
}

TEST_F(SequentialListTest, TypeSafety) {
  auto intList = std::make_unique<SequentialList<int>>();
  EXPECT_TRUE(intList->PushBack(42));
  EXPECT_EQ(intList->QueryByIndex(1), 42);

  auto structList =
      std::make_unique<SequentialList<std::pair<int, std::string>>>();
  EXPECT_TRUE(structList->PushBack({1, "test"}));
  EXPECT_EQ(structList->QueryByIndex(1).first, 1);
}
