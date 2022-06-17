#include "vector.hpp"

const int INITIAL_CAPACITY{5};

template <typename T>
void test_constructor() {
  Vector<T> v(INITIAL_CAPACITY);
  assert(v.get_capacity() == INITIAL_CAPACITY);
  assert(v.get_is_empty() == true);
  assert(v.get_size() == 0);
}

template <typename T>
void test_push(T *items) {
  Vector<T> v(INITIAL_CAPACITY);
  v.push(items[0]);
  v.push(items[1]);
  v.push(items[2]);
  assert(v.get_size() == 3);
  assert(v.get_is_empty() == false);
  assert(v.get_item(0) == items[0]);
  assert(v.get_item(1) == items[1]);
  assert(v.get_item(2) == items[2]);
}

template <typename T>
void test_pop(T *items) {
  Vector<T> v(INITIAL_CAPACITY);
  v.push(items[0]);
  v.push(items[1]);
  v.push(items[2]);
  assert(v.pop() == items[2]);
}

template <typename T>
void test_resize(T *items) {
  Vector<T> v(INITIAL_CAPACITY);
  int cap_before_size_up = v.get_capacity();
  for (int i = 0; i < 6; ++i) v.push(items[i]);
  int cap_after_size_up = v.get_capacity();
  assert(cap_after_size_up == cap_before_size_up * 2);

  for (int i = 0; i < 5; ++i) v.pop();
  int cap_after_size_down = v.get_capacity();
  assert(cap_after_size_down == cap_after_size_up / 2);
}

template <typename T>
void test_insert(T *items) {
  Vector<T> v(INITIAL_CAPACITY);
  v.push(items[0]);
  v.push(items[1]);
  v.push(items[2]);
  v.insert(2, items[3]);
  assert(v.get_item(2) == items[3]);
  assert(v.find_item(items[3]) == 2);
}

template <typename T>
void test_remove(T *items) {
  Vector<T> v1(INITIAL_CAPACITY);
  for (int i = 0; i < 5; ++i) v1.push(items[i]);
  v1.debug_print();
  v1.remove_by_index(2);
  v1.debug_print();
  assert(v1.find_item(items[2]) == -1);
  assert(v1.get_item(2) == items[3]);

  Vector<T> v2(INITIAL_CAPACITY);
  for (int i = 0; i < 5; ++i) v2.push(items[i]);
  v2.remove_by_value(items[3]);
  assert(v2.find_item(items[3]) == -1);
  assert(v2.get_item(3) == items[4]);
}

void run_tests() {
  int i_items[]{23, 24, 545, 2, 57, 74, 33, 47, 82, 90};
  double d_items[]{32.55, 343.4, 54.223, 54.74, 6.4,
                   43.46, 6.2,   43.1,   43.54, 2323.2};
  char c_items[]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  std::string s_items[]{"strawberry", "kiwi",  "orange", "apple",  "melon",
                        "lemon",      "grape", "banana", "cherry", "coconut"};

  test_constructor<int>();
  test_constructor<double>();
  test_constructor<char>();
  test_constructor<std::string>();

  test_push<int>(i_items);
  test_push<double>(d_items);
  test_push<char>(c_items);
  test_push<std::string>(s_items);

  test_pop<int>(i_items);
  test_pop<double>(d_items);
  test_pop<char>(c_items);
  test_pop<std::string>(s_items);

  test_resize<int>(i_items);
  test_resize<double>(d_items);
  test_resize<char>(c_items);
  test_resize<std::string>(s_items);

  test_insert<int>(i_items);
  test_insert<double>(d_items);
  test_insert<char>(c_items);
  test_insert<std::string>(s_items);

  test_remove<int>(i_items);
  test_remove<double>(d_items);
  test_remove<char>(c_items);
  test_remove<std::string>(s_items);

  std::cout << "OK" << std::endl;
}