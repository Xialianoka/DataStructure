#include "student.h"

Student::Student(const std::string name, const std::string num, const bool sex,
                 const int age)
    : name_(name), num_(num), sex_(sex), age_(age) {}

std::string Student::Name() { return name_; }

std::string Student::Num() { return num_; }

std::string Student::Sex() { return sex_ ? "男" : "女"; }

int Student::Age() { return age_; }

bool Student::operator==(const Student& stu) {
  return (this->name_ == stu.name_ && this->num_ == stu.num_ &&
          this->sex_ == stu.sex_);
}
