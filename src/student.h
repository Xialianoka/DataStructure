#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student {
 public:
  Student(const std::string name, const std::string num, const bool sex,
          const int age);

  std::string Name();

  std::string Num();

  std::string Sex();

  int Age();

  bool operator==(const Student& stu);

 private:
  std::string name_;
  std::string num_;
  bool sex_;
  int age_;
};

#endif
