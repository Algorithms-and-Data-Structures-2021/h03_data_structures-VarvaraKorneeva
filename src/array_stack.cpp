#include "array_stack.hpp"

#include <algorithm>  // copy, fill
#include <cassert>    // assert
#include <stdexcept>  // logic_error, invalid_argument

namespace itis {

ArrayStack::ArrayStack(int capacity) {
  if (capacity <= 0) {
    throw std::invalid_argument("initial capacity must be greater than zero");
  }

  std::fill(data_[0], data_[capacity], Element::UNDEFINED);
}

ArrayStack::~ArrayStack() {
  delete [] stack_;
}

void ArrayStack::Push(Element e) {
  if(size_ == capacity){
      data_.resize(capacity + kCapacityGrowthCoefficient);
  }
  data_[size_] = e;
  size_ ++;
}

void ArrayStack::Pop() {
  if (size_ == 0) {
    throw std::logic_error("cannot pop out from empty stack");
  }

  data_[size_ - 1] = Element::UNDEFINED;
  size_ --;
}

void ArrayStack::Clear() {
    std::fill(data_[0], data_[size_], Element::UNDEFINED);
}

void ArrayStack::resize(int new_capacity) {
  assert(new_capacity > size_);

  auto *new_data_ = new Element[new_capacity];
  std::copy(data_[0], data_[size_ - 1], new_data_);
  std::fill(data_[size_], data_[new_capacity], Element::UNDEFINED);
  delete data_;
  data_ = new_data_;
  capacity = new_capacity;
}

// === РЕАЛИЗОВАНО ===

std::optional<Element> ArrayStack::Peek() const {
  // возвращаем вершину стека или ничего (nullopt), если стек пустой
  return size_ == 0 ? std::nullopt : std::make_optional(data_[size_ - 1]);
}

bool ArrayStack::IsEmpty() const {
  return size_ == 0;
}

int ArrayStack::size() const {
  return size_;
}

int ArrayStack::capacity() const {
  return capacity_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const ArrayStack &stack) {
  os << "size: " << stack.size_ << '\n';
  if (stack.data_ != nullptr) {
    // выводим элементы сверху вниз
    for (int index = stack.size_ - 1; index >= 0; index--) {
      if (index == stack.size_ - 1) os << "[TOP] ";
      os << enum2str(stack.data_[index]) << '\n';
    }
  }
  return os;
}

}  // namespace itis