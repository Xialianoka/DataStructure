#ifndef LINEARLIST_H_
#define LINEARLIST_H_

#include "DataStructures.h"

template <typename ElemType>
class LinearList : public DataStructure {
 public:
  virtual ~LinearList() = default;

  // 在index处插入元素
  virtual bool Push(const int index, const ElemType& elem) = 0;

  // 在尾部插入元素
  virtual bool PushBack(const ElemType& elem) = 0;

  // 在头部插入元素
  virtual bool PushFront(const ElemType& elem) = 0;

  // 删除index处的元素，返回删除的元素
  virtual ElemType EraseByIndex(const int index) = 0;

  // 删除第一个遇到的elemt元素
  virtual bool EraseByVale(const ElemType& elem) = 0;

  // 更新index处的元素为elemt
  virtual bool UpdateByIndex(const int index, const ElemType& elem) = 0;

  // 更新第一个遇到的src_elemt为dest_elemt
  virtual bool UpdateByValue(const ElemType& src_elem, const ElemType& dest_elem) = 0;

  // 查询index处的元素，返回该元素
  virtual ElemType QueryByIndex(const int index) = 0;

  // 查询elemt元素，返回其位置，若不存在返回-1
  virtual int QueryByValue(const ElemType& elem) = 0;

  // 获取元素个数
  virtual size_t Size() = 0;

  // 获取总容量大小
  virtual size_t Capacity() = 0;

  // 清空元素
  virtual void Reset() = 0;
};

#endif  // LINEARLIST_H_
