#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <memory>
#include <queue>
#include <string>

namespace ads {

template <typename key_t>
class Bst {
 private:
  struct BstNode {
    BstNode(const key_t &val) : key{val}, left{nullptr}, right{nullptr} {}
    key_t key;
    std::unique_ptr<BstNode> left;
    std::unique_ptr<BstNode> right;
  };
  std::unique_ptr<BstNode> _root;

  void print_dfs_recursion(std::unique_ptr<BstNode> const &node) const;
  void print_bfs_queue(std::unique_ptr<BstNode> const &node) const;
  bool is_between(BstNode *node, int const &max, int const &min) const;
  bool search_recursion(std::unique_ptr<BstNode> const &node,
                        key_t const &val) const;
  void insert_recursion(std::unique_ptr<BstNode> &node, key_t const &val);
  void remove_recursion(std::unique_ptr<BstNode> &node, key_t const &val);
  void removeNode(std::unique_ptr<BstNode> &node);

 public:
  Bst() : _root{nullptr} {};
  ~Bst();
  Bst(const Bst &) = delete;
  Bst &operator=(const Bst &) = delete;
  int get_min() const;
  int get_height() const;
  bool get_is_bst() const;  // check if the tree is a binary search tree
  // TODO:: rotate left and right, and get_is_balanced()
  bool search(key_t const &val) const;  // O(log n) search
  void print_dfs() const;               // depth-first traversal(in-order)
  void print_bfs() const;               // breadth-first traversal
  void insert(key_t const &val);        // insert a node
  void remove(key_t const &val);        // delete a node
};

// Public functions

template <typename key_t>
Bst<key_t>::~Bst() {}

template <typename key_t>
int Bst<key_t>::get_height() const {
  BstNode *current = _root.get();
  int size = 0;
  while (current != nullptr) {
    size++;
    current = current->left.get();
  }
  return size;
}

template <typename key_t>
int Bst<key_t>::get_min() const {
  if (!_root) {
    std::cerr << "Error: Tree is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
  BstNode *current = _root.get();
  while (current->left != nullptr) {
    current = current->left.get();
  }
  return current->key;
}

template <typename key_t>
bool Bst<key_t>::get_is_bst() const {
  return is_between(_root.get(), std::numeric_limits<key_t>::min(),
                    std::numeric_limits<key_t>::max());
}

template <typename key_t>
void Bst<key_t>::print_dfs() const {
  print_dfs_recursion(_root);
}

template <typename key_t>
void Bst<key_t>::print_bfs() const {
  print_bfs_queue(_root);
}

template <typename key_t>
bool Bst<key_t>::search(key_t const &val) const {
  return search_recursion(_root, val);
}

template <typename key_t>
void Bst<key_t>::insert(key_t const &key) {
  insert_recursion(_root, key);
}

template <typename key_t>
void Bst<key_t>::remove(key_t const &key) {
  remove_recursion(_root, key);
}

// Private functions

template <typename key_t>
void Bst<key_t>::print_dfs_recursion(
    std::unique_ptr<BstNode> const &node) const {
  if (node.get() == nullptr) return;
  print_dfs_recursion(node->left);
  std::cout << node->key << std::endl;
  print_dfs_recursion(node->right);
}

template <typename key_t>
void Bst<key_t>::print_bfs_queue(std::unique_ptr<BstNode> const &node) const {
  std::queue<BstNode *> q;
  q.push(node.get());
  while (!q.empty()) {
    BstNode *current = q.front();
    q.pop();
    std::cout << current->key << "\n";
    if (current->left != nullptr) q.push(current->left.get());
    if (current->right != nullptr) q.push(current->right.get());
  }
}

template <typename key_t>
bool Bst<key_t>::is_between(BstNode *node, int const &min,
                            int const &max) const {
  if (node == nullptr) return true;

  return (node->key > min && node->key < max &&
          is_between(node->left.get(), min, node->key)) &&
         is_between(node->right.get(), node->key, max);
}

template <typename key_t>
bool Bst<key_t>::search_recursion(std::unique_ptr<BstNode> const &node,
                                  key_t const &val) const {
  if (node.get() == nullptr) {
    return false;
  } else if (node->key == val) {
    return true;
  } else if (node->key > val) {
    return search_recursion(node->left, val);
  } else {
    return search_recursion(node->right, val);
  }
}

template <typename key_t>
void Bst<key_t>::insert_recursion(std::unique_ptr<BstNode> &node,
                                  key_t const &val) {
  if (node.get() == nullptr) {
    node = std::make_unique<BstNode>(val);
  } else if (node->key >= val) {
    insert_recursion(node->left, val);
  } else {
    insert_recursion(node->right, val);
  }
}

template <typename key_t>
void Bst<key_t>::remove_recursion(std::unique_ptr<BstNode> &node,
                                  key_t const &val) {
  if (node.get() == nullptr) {
    std::cerr << "Error: Tree is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
  // if val is found, remove it
  else if (node->key == val) {
    removeNode(node);
  }
  // if val is less than node->key, search left subtree
  else if (val <= node->key) {
    remove_recursion(node->left, val);
  }
  // if val is greater than node->key, search right subtree
  else {
    remove_recursion(node->right, val);
  }
}

template <typename key_t>
void Bst<key_t>::removeNode(std::unique_ptr<BstNode> &node) {
  // Case 1: if node has no child, delete the node
  if (!node->left && !node->right) {
    // delete it
    node.reset();
  }

  // Case 2: if node has one child, delete the node and replace it with its
  // child
  else if (node->left.get() == nullptr) {
    node = std::move(node->right);
  } else if (node->right.get() == nullptr) {
    node = std::move(node->left);
  }

  // Case 3: if node has two children, find the smallest value in the right
  // subtree and replace the node's value with that value and delete the
  // duplicate
  else {
    // find the smallest value in the right subtree
    BstNode *current = node->right.get();
    while (current->left != nullptr) {
      current = current->left.get();
    }
    // replace the node's value with the smallest value in the right subtree
    node->key = current->key;
    // delete the duplicate.
    // Note: if there are same values, this will not work
    remove_recursion(node->right, current->key);
  }
}

}  // namespace ads

#endif  // BST_H