#include "linked_stack.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedStack::Push(Element e) {
  SinglyNode *node = new SinglyNode(e, &top_);
  top_ = node;
  size_++;
}

void LinkedStack::Pop() {
  if (top_ == nullptr) {
    throw std::logic_error("cannot pop out from empty stack");
  }

  auto curr = top_->next;
  top_->next = nullptr;
  top_ = curr;
  size_--;
}

void LinkedStack::Clear() {
  auto curr1 = stack.top_;
  for(auto curr2 = stack.top_->next; curr2 != nullptr; curr2 = curr2->next){
      curr1->next = nullptr;
      curr1->curr2;
  }
}

// === РЕАЛИЗОВАНО ===

LinkedStack::~LinkedStack() {
  Clear();
}

std::optional<Element> LinkedStack::Peek() const {
  return top_ == nullptr ? std::nullopt : std::make_optional(top_->data);
}

bool LinkedStack::IsEmpty() const {
  return size_ == 0;
}

int LinkedStack::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedStack &stack) {
  os << "size: " << stack.size_ << '\n';
  for (auto current_node = stack.top_; current_node != nullptr; current_node = current_node->next) {
    if (current_node == stack.top_) os << "[TOP] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis