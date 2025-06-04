#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <string>

class DataStructure {
 public:
  // 析构函数
  virtual ~DataStructure() = default;

  // 基本操作的接口，由派生类实现
  virtual void Print() const = 0;

  virtual std::string Name() const = 0;
};

#endif  // DATA_STRUCTURES_H