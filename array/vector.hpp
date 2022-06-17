#ifndef VECTOR_HPP
#define VECTOR_HPP

template <class T>
class Vector {
 public:
  Vector(int initialCapacity);
  ~Vector();
  void print() const;
  int get_size() const;
  int get_capacity() const;
  bool get_is_empty() const;
  T get_item(int index) const;
  int find_item(T item) const;
  void debug_print() const;
  void push(T item);
  T pop();
  void insert(int index, T item);
  void prepend(T item);
  void remove_by_index(int index);
  void remove_by_value(T item);

 private:
  void resize(int newCapacity);
  std::unique_ptr<T[]> _data;
  int _size;
  int _capacity;
};

#include "vector.tpp"

#endif