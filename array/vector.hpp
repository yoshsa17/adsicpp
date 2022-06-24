#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <string>

const int DEFAULT_CAPACITY = 5;

namespace ads {
template <typename T>
class Vector {
 public:
  Vector(int initialCapacity = DEFAULT_CAPACITY);
  ~Vector();
  Vector(const Vector &) = delete;             // avoid copy constructor
  Vector &operator=(const Vector &) = delete;  // avoid copy assignment
  void print() const;
  int get_size() const;
  int get_capacity() const;
  bool get_is_empty() const;
  T get_item(int index) const;
  int find_item(T item) const;
  void debug_print() const;
  void push(T item);                // add item to end of vector
  T pop();                          // remove and return the last item
  void insert(int index, T item);   // insert item at index
  void prepend(T item);             // insert at the front
  void remove_by_index(int index);  // remove item at index
  void remove_by_value(T item);     // remove first occurrence of item

 private:
  void resize(int newCapacity);
  std::unique_ptr<T[]> _data;
  int _size;
  int _capacity;
};

template <typename T>
int Vector<T>::get_size() const {
  return _size;
};

template <typename T>
int Vector<T>::get_capacity() const {
  return _capacity;
};

template <typename T>
bool Vector<T>::get_is_empty() const {
  return _size == 0;
};

template <typename T>
T Vector<T>::get_item(int index) const {
  return _data[index];
};

template <typename T>
void Vector<T>::debug_print() const {
  std::cout << "---------" << std::endl;
  std::cout << "Size: " << _size << std::endl;
  std::cout << "Capacity: " << _capacity << std::endl;
  std::cout << "Item: " << std::endl;

  for (int i = 0; i < _capacity; ++i) {
    std::cout << i << ": " << _data[i] << std::endl;
  }
  std::cout << "---------" << std::endl;
}

template <typename T>
int Vector<T>::find_item(T item) const {
  int found_index = -1;

  for (int i = 0; i < _size; ++i) {
    if (_data[i] == item) {
      found_index = i;
      break;
    }
  }

  if (found_index == -1) {
    std::cerr << "Error: Item not found" << std::endl;
    exit(EXIT_FAILURE);
  }
  return found_index;
}

template <typename T>
Vector<T>::Vector(int initialCapacity) {
  if (initialCapacity < 1) {
    std::cerr << "Error: initialCapacity must be greater than 0" << std::endl;
    exit(EXIT_FAILURE);
  }
  _data = std::make_unique<T[]>(initialCapacity);
  _size = 0;
  _capacity = initialCapacity;
}

template <typename T>
Vector<T>::~Vector() {}

template <typename T>
void Vector<T>::push(T item) {
  if (_capacity == _size) resize(_capacity * 2);

  _data[_size] = item;
  _size++;
}

template <typename T>
void Vector<T>::resize(int new_capacity) {
  auto new_data = std::make_unique<T[]>(new_capacity);
  for (int i = 0; i < _size; ++i) new_data[i] = _data[i];

  _data = std::move(new_data);
  _capacity = new_capacity;
}

template <typename T>
T Vector<T>::pop() {
  if (_size == 0) {
    std::cerr << "Error: List is empty" << std::endl;
    exit(EXIT_FAILURE);
  }

  if (_capacity / 4 == _size) resize(_capacity / 2);
  T item = _data[_size - 1];
  _size--;
  return item;
}

template <typename T>
void Vector<T>::insert(int index, T item) {
  if (index < 0 || index > _size - 1) exit(EXIT_FAILURE);
  if (_capacity == _size) resize(_capacity * 2);

  for (int i = _size; i > index; --i) _data[i] = _data[i - 1];
  _data[index] = item;
  _size++;
}

template <typename T>
void Vector<T>::prepend(T item) {
  insert(0, item);
};

template <typename T>
void Vector<T>::remove_by_index(int index) {
  if (index < 0 || index > _size - 1) {
    std::cerr << "Error: Index out of range" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (_capacity / 4 == _size) resize(_capacity / 2);

  for (int i = index; i < _size; ++i) _data[i] = _data[i + 1];
  _size--;
}

template <typename T>
void Vector<T>::remove_by_value(T item) {
  int index = find_item(item);
  remove_by_index(index);
}

}  // namespace ads

#endif