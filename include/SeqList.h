#ifndef SEQ_LIST_H
#define SEQ_LIST_H

#include <iostream>
#include <string>
#include <vector>

#include "DataStructures.h"

class SeqList : public DataStructure {
 public:
  SeqList();
  ~SeqList();

  void Insert(int value);

  void Remove(int value);

  bool Search(int value) const;

  void Print() const override;

  std::string Name() const override { return "SequentialList"; }

 private:
  std::vector<int> data_;
};

#endif  // SEQ_LIST_H
