
template <class T>
int Vector<T>::get_size() const {
  return _size;
};

template <class T>
int Vector<T>::get_capacity() const {
  return _capacity;
};

template <class T>
bool Vector<T>::get_is_empty() const {
  return _size == 0;
};

template <class T>
T Vector<T>::get_item(int index) const {
  return _data[index];
};

template <class T>
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

template <class T>
int Vector<T>::find_item(T item) const {
  int found_index = -1;

  for (int i = 0; i < _size; ++i) {
    if (_data[i] == item) {
      found_index = i;
      break;
    }
  }
  return found_index;
}

template <class T>
Vector<T>::Vector(int initialCapacity) {
  if (initialCapacity < 1) {
    std::cout << "'initialCapacity' must be more than 1" << std::endl;
    exit(EXIT_FAILURE);
  }

  _data = std::unique_ptr<T[]>(new T[initialCapacity]);
  _size = 0;
  _capacity = initialCapacity;
}

template <class T>
Vector<T>::~Vector() {}

template <class T>
void Vector<T>::push(T item) {
  if (_capacity == _size) {
    resize(_capacity * 2);
  }

  _data[_size] = item;
  ++_size;
}

template <class T>
void Vector<T>::resize(int new_capacity) {
  std::unique_ptr<T[]> new_data(new T[new_capacity]);
  for (int i = 0; i < _size; ++i) {
    new_data[i] = _data[i];
  }

  _data = std::move(new_data);
  _capacity = new_capacity;
}

template <class T>
T Vector<T>::pop() {
  if (_size == 0) {
    exit(EXIT_FAILURE);
  }

  if (_capacity / 4 == _size) {
    resize(_capacity / 2);
  }

  T item = _data[_size - 1];
  --_size;
  return item;
}

template <class T>
void Vector<T>::insert(int index, T item) {
  if (index < 0 || index > _size - 1) {
    exit(EXIT_FAILURE);
  }

  if (_capacity == _size) {
    resize(_capacity * 2);
  }

  for (int i = _size; i > index; --i) {
    _data[i] = _data[i - 1];
  }
  _data[index] = item;
  ++_size;
}

template <class T>
void Vector<T>::prepend(T item) {
  insert(0, item);
};

template <class T>
void Vector<T>::remove_by_index(int index) {
  if (index < 0 || index > _size - 1) {
    exit(EXIT_FAILURE);
  }

  if (_capacity / 4 == _size) {
    resize(_capacity / 2);
  }

  for (int i = index; i < _size; ++i) {
    _data[i] = _data[i + 1];
  }
  --_size;
}

template <class T>
void Vector<T>::remove_by_value(T item) {
  int index = find_item(item);
  if (index == -1) {
    exit(EXIT_FAILURE);
  }

  remove_by_index(index);
}