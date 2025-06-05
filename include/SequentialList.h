#ifndef SEQUENTIAL_H_
#define SEQUENTIAL_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "LinearList.h"

template <typename ElemType>
class SequentialList : public LinearList<ElemType> {
 public:
  SequentialList()
      : list_(std::make_unique<ElemType[]>(1)), capacity_(1), cur_size_(0) {}

  ~SequentialList() {}

  void Print() const override {
    for (int i = 0; i < cur_size_; i++) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }

  std::string Name() const override { return "SequentialList"; }

  bool Push(int index, const ElemType& elem) override {
    if (index < 1 || index > cur_size_ + 1) {
      return false;
    }
    if (cur_size_ >= capacity_) {
      capacity_ = 2 * capacity_;
      auto new_list = std::make_unique<ElemType[]>(capacity_);
      if (!new_list) {
        return false;
      }
      for (int i = 0; i < cur_size_; ++i) {
        new_list[i] = list_[i];
      }
      list_ = std::move(new_list);
    }
    if (index != cur_size_ + 1) {
      for (int i = cur_size_; i > index - 1; --i) {
        list_[i] = list_[i - 1];
      }
    }
    list_[index - 1] = elem;
    ++cur_size_;

    return true;
  }

  bool PushBack(const ElemType& elem) override {
    return Push(cur_size_ + 1, elem);
  }

  bool PushFront(const ElemType& elem) override { return Push(1, elem); }

  ElemType EraseByIndex(const int index) override {
    if (cur_size_ == 0 || index < 1 || index > cur_size_) {
      return {};
    }
    ElemType item = list_[index - 1];
    if (index != cur_size_) {
      for (int i = index - 1; i < cur_size_; ++i) {
        list_[i] = list_[i + 1];
      }
    }
    --cur_size_;
    return item;
  }

  bool EraseByVale(const ElemType& src_elem) override {
    if (cur_size_ == 0) {
      return false;
    }
    int index = -1;
    for (int i = 0; i < cur_size_; i++) {
      if (list_[i] == src_elem) {
        index = i;
        break;
      }
    }
    if (index == -1) {
      return false;
    }
    EraseByIndex(index + 1);
    return true;
  }

  bool UpdateByIndex(const int index, const ElemType& elem) override {
    if (cur_size_ == 0 || index < 1 || index > cur_size_) {
      return false;
    }
    list_[index - 1] = elem;
    return true;
  }

  bool UpdateByValue(const ElemType& src_elem,
                     const ElemType& dest_elem) override {
    if (cur_size_ == 0) {
      return false;
    }
    int index = -1;
    for (int i = 0; i < cur_size_; i++) {
      if (list_[i] == src_elem) {
        index = i;
        break;
      }
    }
    if (index == -1) {
      return false;
    }
    return UpdateByIndex(index + 1, dest_elem);
  }

  ElemType QueryByIndex(const int index) override {
    if (cur_size_ == 0 || index < 1 || index > cur_size_) {
      return {};
    }
    return list_[index - 1];
  }

  int QueryByValue(const ElemType& elem) override {
    for (int i = 0; i < cur_size_; ++i) {
      if (list_[i] == elem) {
        return i + 1;
      }
    }
    return -1;
  }

  size_t Size() override { return cur_size_; }

  size_t Capacity() override { return capacity_; }

  void Reset() override { cur_size_ = 0; }

 private:
  std::unique_ptr<ElemType[]> list_;
  int capacity_;
  int cur_size_;
};

#endif  // SEQUENTIAL_H_
