#include "linked_dequeue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedDequeue::Enqueue(Element e) {
  SinglyNode *node = new SinglyNode(e, nullptr);
  back_->next = node;
  back_ = node;
  size_++;
}

void LinkedDequeue::EnqueueFront(Element e) {
  SinglyNode *node = new SinglyNode(e, &front_);
  front_ = node;
  size_++;
}

void LinkedDequeue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }

  auto curr = front_->next;
  front_->next = nullptr;
  front_ = curr;
  size_--;
}

void LinkedDequeue::DequeueBack() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }

  auto node = queue.front_;
  for(auto curr = queue.front_; curr != back_; curr = curr->next){
      node = curr;
  }
  curr->next = nullptr;
  back_ = node;
  size_--;
}

void LinkedDequeue::Clear() {
  auto curr1 = queue.front_;
  for(auto curr2 = queue.front_->next; curr2 != nullptr; curr2 = curr2->next){
      urr1->next = nullptr;
      curr1->curr2;
  }
}

// === РЕАЛИЗОВАНО ===

LinkedDequeue::~LinkedDequeue() {
  Clear();
}

std::optional<Element> LinkedDequeue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedDequeue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedDequeue::IsEmpty() const {
  return size_ == 0;
}

int LinkedDequeue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedDequeue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->previous) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis
