
#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include <iostream>
#include <memory>
#include <string>

namespace ads {

template <typename T>
class ForwardList {
 private:
  struct Node {
    T data;
    std::shared_ptr<Node> next;
  };
  std::shared_ptr<Node> _head;

 public:
  explicit ForwardList() : _head(nullptr) {}
  ~ForwardList();
  ForwardList(const ForwardList &) = delete;
  ForwardList &operator=(const ForwardList &) = delete;
  void print() const;
  T get_front() const;
  T get_back() const;
  T get_value(int const &index) const;
  void push_front(T val);        // add item to front of list
  T pop_front();                 // remove and return the first item
  void push_back(T const &val);  // add item to end of vector
  T pop_back();                  // remove and return the last item
  void insert(int const &index, T const &val);  // insert at index
  void remove_by_index(int const &index);       // remove item at index
  void remove_by_value(T const &val);  // remove first occurrence of item
  void reverse();                      // reverse the list
};

// Public functions

template <typename T>
ForwardList<T>::~ForwardList() {
  std::shared_ptr<Node> current = _head;
  while (current != nullptr) {
    current = current->next;
  }
}

template <typename T>
void ForwardList<T>::print() const {
  std::shared_ptr<Node> current = _head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

template <typename T>
T ForwardList<T>::get_front() const {
  if (_head == nullptr) {
    std::cerr << "Error: List is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
  return _head->data;
};

template <typename T>
T ForwardList<T>::get_back() const {
  if (_head == nullptr) {
    std::cerr << "Error: List is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
  auto current = _head;
  while (current->next != nullptr) {
    current = current->next;
  }
  return current->data;
};

template <typename T>
T ForwardList<T>::get_value(int const &index) const {
  if (_head == nullptr) {
    std::cerr << "Error: List is empty" << std::endl;
    exit(EXIT_FAILURE);
  }

  auto current = _head;
  int i = 0;
  while (i < index) {
    if (current->next == nullptr) {
      std::cerr << "Error: Index out of range" << std::endl;
      exit(EXIT_FAILURE);
    }
    current = current->next;
    i++;
  }
  return current->data;
};

template <typename T>
void ForwardList<T>::push_front(T val) {
  auto new_node = std::make_shared<Node>();
  new_node->data = val;
  if (_head == nullptr) {
    _head = new_node;
  } else {
    new_node->next = _head;
    _head = new_node;
  }
};

template <typename T>
T ForwardList<T>::pop_front() {
  if (_head == nullptr) {
    std::cerr << "Error: List is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
  auto temp = _head;
  _head = _head->next;
  return temp->data;
};

template <typename T>
void ForwardList<T>::push_back(T const &val) {
  auto new_node = std::make_shared<Node>();
  new_node->data = val;
  if (_head == nullptr) {
    _head = new_node;
  } else {
    auto current = _head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new_node;
  }
};

template <typename T>
T ForwardList<T>::pop_back() {
  if (_head == nullptr) {
    std::cerr << "Error: List is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (_head->next == nullptr) {
    auto temp = _head;
    _head = nullptr;
    return temp->data;
  }

  auto current = _head;
  std::shared_ptr<Node> previous = nullptr;
  while (current->next != nullptr) {
    previous = current;
    current = current->next;
  }
  previous->next = nullptr;
  return current->data;
};

template <typename T>
void ForwardList<T>::insert(int const &index, T const &val) {
  if (index < 0) {
    std::cerr << "Error: Index out of range" << std::endl;
    exit(EXIT_FAILURE);
  }

  auto new_node = std::make_shared<Node>();
  new_node->data = val;
  if (index == 0 && _head == nullptr) {
    _head = new_node;
    return;
  } else if (index == 0) {
    new_node->next = _head;
    _head = new_node;
    return;
  }

  auto current = _head;
  std::shared_ptr<Node> previous = nullptr;

  for (int i = 0; i < index; i++) {
    if (current == nullptr) {
      std::cerr << "Error: Index out of range" << std::endl;
      exit(EXIT_FAILURE);
    }
    previous = current;
    current = current->next;
  }
  new_node->next = current;
  previous->next = new_node;
};

template <typename T>
void ForwardList<T>::remove_by_index(int const &index) {
  if (index < 0) {
    std::cerr << "Error: Index out of range" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (_head == nullptr) {
    std::cerr << "Error: List is empty" << std::endl;
    exit(EXIT_FAILURE);
  }

  auto current = _head;
  int i = 0;
  while (i < index - 1) {
    if (current->next == nullptr) {
      std::cerr << "Error: Index out of range" << std::endl;
      exit(EXIT_FAILURE);
    }
    current = current->next;
    i++;
  }
  current->next = current->next->next;
};

template <typename T>
void ForwardList<T>::remove_by_value(T const &val) {
  if (_head == nullptr) {
    std::cerr << "Error: List is empty" << std::endl;
    exit(EXIT_FAILURE);
  }

  auto current = _head;
  std::shared_ptr<Node> previous = nullptr;
  while (current->next != nullptr) {
    if (current->data == val) {
      if (previous == nullptr) {
        _head = current->next;
      } else {
        previous->next = current->next;
      }
    }
    previous = current;
    current = current->next;
  }
}

template <typename T>
void ForwardList<T>::reverse() {
  auto current = _head;
  std::shared_ptr<Node> previous = nullptr;
  std::shared_ptr<Node> next = nullptr;

  while (current != nullptr) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  _head = previous;
}

}  // namespace ads

#endif