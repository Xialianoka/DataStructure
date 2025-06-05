#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <string>

class DataStructure {
 public:
  virtual ~DataStructure() = default;

  // 输出所有元素
  virtual void Print() const = 0;

  // 数据结构的名称
  virtual std::string Name() const = 0;
};

#endif  // DATA_STRUCTURES_H
