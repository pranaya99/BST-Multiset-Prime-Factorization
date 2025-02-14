#ifndef MULTISET_H_
#define MULTISET_H_

#include <cstddef>
#include <algorithm>
#include <iostream>
#include <memory>
#include <exception>

template <typename K>
class Multiset {
 public:
  // Public API
  Multiset() : root_(nullptr), size_(0) {}

  size_t Size() { return size_; }
  bool Empty() { return size_ == 0; }

  void Insert(const K& key) { root_ = InsertHelper(std::move(root_), key); }
  void Remove(const K& key) {
    if (!Contains(key)) throw std::runtime_error("Key not found");
    root_ = RemoveHelper(std::move(root_), key);
  }

  bool Contains(const K& key) { return ContainsHelper(root_, key); }
  size_t Count(const K& key) {
    Node* node = FindNode(root_, key);
    if (!node) throw std::runtime_error("Key not found");
    return node->count;
  }

  const K& Floor(const K& key) {
    if (Empty()) throw std::runtime_error("Multiset is empty");
    Node* node = FloorHelper(root_, key, nullptr);
    if (!node) throw std::runtime_error("No floor exists for the key");
    return node->key;
  }

  const K& Ceil(const K& key) {
    if (Empty()) throw std::runtime_error("Multiset is empty");
    Node* node = CeilHelper(root_, key, nullptr);
    if (!node) throw std::runtime_error("No ceiling exists for the key");
    return node->key;
  }

  const K& Max() {
    if (Empty()) throw std::runtime_error("Multiset is empty");
    return FindMax(root_)->key;
  }

  const K& Min() {
    if (Empty()) throw std::runtime_error("Multiset is empty");
    return FindMin(root_)->key;
  }

 private:
  struct Node {
    K key;
    size_t count;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(const K& k) : key(k), count(1), left(nullptr), right(nullptr) {}
  };

  std::unique_ptr<Node> root_;
  size_t size_;

  std::unique_ptr<Node> InsertHelper(std::unique_ptr<Node> node, const K& key) {
    if (!node) {
      ++size_;
      return std::make_unique<Node>(key);
    }
    if (key < node->key) {
      node->left = InsertHelper(std::move(node->left), key);
    } else if (key > node->key) {
      node->right = InsertHelper(std::move(node->right), key);
    } else {
      ++node->count;
    }
    return node;
  }

  std::unique_ptr<Node> RemoveHelper(std::unique_ptr<Node> node, const K& key) {
    if (!node) return nullptr;
    if (key < node->key) {
      node->left = RemoveHelper(std::move(node->left), key);
    } else if (key > node->key) {
      node->right = RemoveHelper(std::move(node->right), key);
    } else {
      if (node->count > 1) {
        --node->count;
        --size_;
        return node;
      }
      if (!node->left) return std::move(node->right);
      if (!node->right) return std::move(node->left);
      Node* minNode = FindMin(node->right.get());
      node->key = minNode->key;
      node->count = minNode->count;
      minNode->count = 1;
      node->right = RemoveHelper(std::move(node->right), minNode->key);
    }
    return node;
  }

  Node* FindMin(Node* node) {
    while (node->left) node = node->left.get();
    return node;
  }

  Node* FindMax(Node* node) {
    while (node->right) node = node->right.get();
    return node;
  }

  bool ContainsHelper(Node* node, const K& key) {
    if (!node) return false;
    if (key < node->key) return ContainsHelper(node->left.get(), key);
    if (key > node->key) return ContainsHelper(node->right.get(), key);
    return true;
  }

  Node* FindNode(Node* node, const K& key) {
    if (!node) return nullptr;
    if (key < node->key) return FindNode(node->left.get(), key);
    if (key > node->key) return FindNode(node->right.get(), key);
    return node;
  }

  Node* FloorHelper(Node* node, const K& key, Node* best) {
    if (!node) return best;
    if (node->key == key) return node;
    if (node->key > key) return FloorHelper(node->left.get(), key, best);
    return FloorHelper(node->right.get(), key, node);
  }

  Node* CeilHelper(Node* node, const K& key, Node* best) {
    if (!node) return best;
    if (node->key == key) return node;
    if (node->key < key) return CeilHelper(node->right.get(), key, best);
    return CeilHelper(node->left.get(), key, node);
  }
};

#endif  // MULTISET_H_
