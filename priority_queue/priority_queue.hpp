
#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <iostream>
#include <memory>
#include <utility>

namespace ads {

template <typename T>
class PriorityQueue {
 private:
  struct Node {
    int _key;
    T _val;
  };
  std::unique_ptr<Node[]> _arr;
  int _size;
  int _capacity;
  int get_parent_index(int const &index) const;
  int get_lchild_index(int const &index) const;
  int get_rchild_index(int const &index) const;
  void shift_up(int index);
  void shift_down(int index);

 public:
  PriorityQueue();
  ~PriorityQueue();
  PriorityQueue(const PriorityQueue &) = delete;
  PriorityQueue &operator=(const PriorityQueue &) = delete;
  void print() const;
  int get_size() const;
  int get_capacity() const;
  T get_max() const;  // return the max value
  T extract_max();    // return the max value and remove it from the queue
  void insert(int const &key, T const &val);
  void remove_by_index(int const &index);
  void change_priority(int const &index, int const &priority);
};

// Public methods

int INITIAL_CAPACITY = 20 + 1;
int MAX_INDEX = 1;

template <typename T>
PriorityQueue<T>::PriorityQueue() {
  _arr = std::make_unique<Node[]>(INITIAL_CAPACITY);
  _size = 0;
  _capacity = INITIAL_CAPACITY - 1;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {}

template <typename T>
void PriorityQueue<T>::print() const {
  for (int i = MAX_INDEX; i <= _size; i++) {
    std::cout << "[INDEX]: " << i << " "
              << "[KEY]: " << _arr[i]._key << " "
              << "[VALUE]:" << _arr[i]._val << std::endl;
  }
  std::cout << "==========================" << std::endl;
}

template <typename T>
int PriorityQueue<T>::get_capacity() const {
  return _capacity;
}

template <typename T>
int PriorityQueue<T>::get_size() const {
  return _size;
}

template <typename T>
T PriorityQueue<T>::get_max() const {
  return _arr[MAX_INDEX]._val;
}

template <typename T>
void PriorityQueue<T>::insert(int const &key, T const &val) {
  if (_size == _capacity) {
    std::cerr << "Error: Capacity is full" << std::endl;
    exit(EXIT_FAILURE);
  }

  _size++;
  _arr[_size]._key = key;
  _arr[_size]._val = val;
  shift_up(_size);
}

template <typename T>
T PriorityQueue<T>::extract_max() {
  T max_value = _arr[MAX_INDEX]._val;
  _arr[MAX_INDEX] = _arr[_size];
  _size--;
  shift_down(MAX_INDEX);
  return max_value;
}

template <typename T>
void PriorityQueue<T>::remove_by_index(int const &index) {
  if (_size == 0) {
    std::cerr << "Error: Queue is empty" << std::endl;
    exit(EXIT_FAILURE);
  } else if (index > _size) {
    std::cerr << "Error: Index is out of range" << std::endl;
    exit(EXIT_FAILURE);
  } else if (MAX_INDEX == index) {
    extract_max();
    return;
  }

  _arr[index] = _arr[MAX_INDEX + 1];
  shift_down(index);
  extract_max();
}

template <typename T>
void PriorityQueue<T>::change_priority(int const &index, int const &priority) {
  if (priority < 0) {
    std::cerr << "Error: Priority is out of range" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (index > _size || index < 1) {
    std::cerr << "Error: Index is out of range" << std::endl;
    exit(EXIT_FAILURE);
  }

  _arr[index]._key = priority;
  shift_up(index);
  shift_down(index);
}

// Private methods

template <typename T>
int PriorityQueue<T>::get_parent_index(int const &index) const {
  return index / 2;
}

template <typename T>
int PriorityQueue<T>::get_lchild_index(int const &index) const {
  return 2 * index;
};

template <typename T>
int PriorityQueue<T>::get_rchild_index(int const &index) const {
  return 2 * index + 1;
};

template <typename T>
void PriorityQueue<T>::shift_up(int index) {
  while (index > MAX_INDEX &&
         _arr[index]._key < _arr[get_parent_index(index)]._key) {
    std::swap(_arr[index], _arr[get_parent_index(index)]);
    index = get_parent_index(index);
  }
}

template <typename T>
void PriorityQueue<T>::shift_down(int index) {
  int lchild_index = get_lchild_index(index);
  int rchild_index = get_rchild_index(index);
  int max_index = index;

  if (lchild_index <= _size && _arr[lchild_index]._key < _arr[max_index]._key) {
    max_index = lchild_index;
  }
  if (rchild_index <= _size && _arr[rchild_index]._key < _arr[max_index]._key) {
    max_index = rchild_index;
  }
  if (max_index != index) {
    std::swap(_arr[index], _arr[max_index]);
    shift_down(max_index);
  }
}

}  // namespace ads

#endif  // PRIORITY_QUEUE_HPP