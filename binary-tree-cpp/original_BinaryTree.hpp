#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
using namespace std;
#define COUNT 10

namespace ariel {

template <typename T> class BinaryTree {

public:
  BinaryTree() : root(nullptr) {}

  ~BinaryTree() {
    // while (!isEmpty())
    // pop();
  }

  // inner class
  struct Node {
    T m_value;
    Node *left;
    Node *right;
    Node(const T &v) : m_value(v), left(NULL), right(NULL) {}
  };

  void search(struct Node *node, T key) {
    if (node == NULL) {
      return;
    }

    if (node->m_value == key)
      existing_element = node;

    /* then recur on left sutree */
    search(node->left, key);
    // node found, no need to look further
    // if (res1)
    //     return search(res1->left, key);

    /* node is not found in left,
so recur on right subtree */
    search(node->right, key);
  }

  BinaryTree<T> &add_root(T s) {
    cout << "Added root" << endl;
    root = new Node(s);
    return *this;
  }

  bool isEmpty() const { return root == nullptr; }

  BinaryTree<T> &add_left(T exists, T add_this) {
    search(root, exists);
    if (existing_element == NULL)
      throw std::runtime_error("No item found");

    if (existing_element->left != NULL) {
      existing_element->left->m_value = add_this;
    } else {
      existing_element->left = new Node(add_this);
    }
    existing_element = NULL;
    return *this;
  }
  BinaryTree<T> &add_right(T exists, T add_this) {
    search(root, exists);
    if (existing_element == NULL)
      throw std::runtime_error("No item found");
    existing_element->right = new Node(add_this);
    existing_element = NULL;
    return *this;
  }

private:
  // Avoid copying
  BinaryTree(const BinaryTree &rhs);
  BinaryTree &operator=(const BinaryTree &rhs);

  // fields
  Node *root;
  Node *existing_element;

public:
  Node *getRoot() { return root; }

  //-------------------------------------------------------------------
  // iterator related code:
  // inner class and methods that return instances of it)
  //-------------------------------------------------------------------
  class iterator {
  private:
    Node *pointer_to_current_node;
    Node *curr;
    Node *temp = NULL;
    stack<Node *> s;
    int flag = 0;

  public:
    iterator(Node *ptr = nullptr) : pointer_to_current_node(ptr), curr(ptr) {}
    T &operator*() const {
      if (!pointer_to_current_node)
        cout << "No value in node" << endl;
      return pointer_to_current_node->m_value;
    }

    T *operator->() const { return &(pointer_to_current_node->m_value); }

    // ++i;
    iterator &operator++() {
      // if ((s.empty()))
      //   pointer_to_current_node = NULL;
      // Node *temp = NULL;
      if (curr != NULL || s.empty() == false) {

        while (curr != NULL) {

          s.push(curr);
          curr = curr->left;
        }

        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
        if (!temp) {
          pointer_to_current_node = curr;
        } else {
          pointer_to_current_node = temp;
        }
        curr = curr->right;
        temp = curr;
      } else {
        pointer_to_current_node = NULL;
      }

      return *this;
    }

    // i++;
    // Usually iterators are passed by value and not by const& as they are
    // small.
    const iterator operator++(int) {
      iterator_inorder tmp = *this;

      return tmp;
    }

    bool operator==(const iterator &rhs) const {
      return pointer_to_current_node == rhs.pointer_to_current_node;
    }

    bool operator!=(const iterator &rhs) const {
      return pointer_to_current_node != rhs.pointer_to_current_node;
    }
  }; // END OF CLASS ITERATOR

  iterator begin() {
    // return &(m_first->m_value);
    return ++iterator{root};
  }

  iterator end() {
    // return nullptr;
    return iterator{nullptr};
  }
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  class iterator_preorder {
  private:
    Node *pointer_to_current_node;
    stack<Node *> nodeStack;

  public:
    iterator_preorder(Node *ptr = nullptr) : pointer_to_current_node(ptr) {
      nodeStack.push(ptr);
      // operator++();
    }
    T &operator*() const {
      // return *pointer_to_current_node;
      return pointer_to_current_node->m_value;
    }

    T *operator->() const { return &(pointer_to_current_node->m_value); }

    // ++i;
    iterator_preorder &operator++() {
      if (!nodeStack.empty()) {
        pointer_to_current_node = nodeStack.top();
        nodeStack.pop();

        if (pointer_to_current_node->right)
          nodeStack.push(pointer_to_current_node->right);
        if (pointer_to_current_node->left)
          nodeStack.push(pointer_to_current_node->left);
      } else
        pointer_to_current_node = NULL;

      return *this;
    }
    // i++;
    // Usually iterators are passed by value and not by const& as they are
    // small.
    const iterator_preorder operator++(int) {
      iterator_preorder tmp = *this;
      if (!nodeStack.empty()) {
        pointer_to_current_node = nodeStack.top();
        nodeStack.pop();

        if (pointer_to_current_node->right)
          nodeStack.push(pointer_to_current_node->right);
        if (pointer_to_current_node->left)
          nodeStack.push(pointer_to_current_node->left);
      } else
        pointer_to_current_node = NULL;

      return tmp;
    }

    bool operator==(const iterator_preorder &rhs) const {
      return pointer_to_current_node == rhs.pointer_to_current_node;
    }

    bool operator!=(const iterator_preorder &rhs) const {
      return pointer_to_current_node != rhs.pointer_to_current_node;
    }
  }; // END OF CLASS ITERATOR

  iterator_preorder begin_preorder() { return ++iterator_preorder{root}; }

  iterator_preorder end_preorder() { return iterator_preorder{nullptr}; }
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  class iterator_postorder {
  private:
    Node *pointer_to_current_node;
    stack<Node *> s1, s2;

  public:
    iterator_postorder(Node *ptr = nullptr) : pointer_to_current_node(ptr) {
      s1.push(ptr);
    }
    T &operator*() const {
      // return *pointer_to_current_node;
      return pointer_to_current_node->m_value;
    }

    T *operator->() const { return &(pointer_to_current_node->m_value); }

    // ++i;
    iterator_postorder &operator++() {
      if ((s1.empty()))
        pointer_to_current_node = NULL;

      while (!s1.empty()) {
        pointer_to_current_node = s1.top();
        s1.pop();
        s2.push(pointer_to_current_node);

        if (pointer_to_current_node->left)
          s1.push(pointer_to_current_node->left);
        if (pointer_to_current_node->right)
          s1.push(pointer_to_current_node->right);
      }

      if (s1.empty()) {
        // Print all elements of second stack
        if (!s2.empty()) {
          pointer_to_current_node = s2.top();
          s2.pop();
        }
      }

      return *this;
    }

    const iterator_postorder operator++(int) {
      iterator_postorder tmp = *this;

      if (!s1.empty()) {
        pointer_to_current_node = s1.top();
        s1.pop();
        s2.push(pointer_to_current_node);

        if (pointer_to_current_node->left)
          s1.push(pointer_to_current_node->left);
        if (pointer_to_current_node->right)
          s1.push(pointer_to_current_node->right);
      }
      // Print all elements of second stack
      if (!s2.empty()) {
        pointer_to_current_node = s2.top();
        s2.pop();
      }

      if ((!s1.empty()) && (!s2.empty()))
        pointer_to_current_node = NULL;

      return tmp;
    }

    bool operator==(const iterator_postorder &rhs) const {
      return pointer_to_current_node == rhs.pointer_to_current_node;
    }

    bool operator!=(const iterator_postorder &rhs) const {
      return pointer_to_current_node != rhs.pointer_to_current_node;
    }
  }; // END OF CLASS ITERATOR

  iterator_postorder begin_postorder() {
    // return &(m_first->m_value);
    return ++iterator_postorder{root};
  }

  iterator_postorder end_postorder() {
    // return nullptr;
    return iterator_postorder{nullptr};
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////////
  class iterator_inorder {
  private:
    Node *pointer_to_current_node;
    Node *curr;
    Node *temp = NULL;
    stack<Node *> s;
    int flag = 0;

  public:
    iterator_inorder(Node *ptr = nullptr)
        : pointer_to_current_node(ptr), curr(ptr) {}
    T &operator*() const {
      if (!pointer_to_current_node)
        cout << "No value in node" << endl;
      return pointer_to_current_node->m_value;
    }

    T *operator->() const { return &(pointer_to_current_node->m_value); }

    // ++i;
    iterator_inorder &operator++() {
      // if ((s.empty()))
      //   pointer_to_current_node = NULL;
      // Node *temp = NULL;
      if (curr != NULL || s.empty() == false) {

        while (curr != NULL) {

          s.push(curr);
          curr = curr->left;
        }

        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
        if (!temp) {
          pointer_to_current_node = curr;
        } else {
          pointer_to_current_node = temp;
        }
        curr = curr->right;
        temp = curr;
      } else {
        pointer_to_current_node = NULL;
      }

      return *this;
    }

    // i++;
    // Usually iterators are passed by value and not by const& as they are
    // small.
    const iterator_inorder operator++(int) {
      iterator_inorder tmp = *this;

      return tmp;
    }

    bool operator==(const iterator_inorder &rhs) const {
      return pointer_to_current_node == rhs.pointer_to_current_node;
    }

    bool operator!=(const iterator_inorder &rhs) const {
      return pointer_to_current_node != rhs.pointer_to_current_node;
    }
  }; // END OF CLASS ITERATOR

  iterator_inorder begin_inorder() {
    // return &(m_first->m_value);
    return ++iterator_inorder{root};
  }

  iterator_inorder end_inorder() {
    // return nullptr;
    return iterator_inorder{nullptr};
  }

  friend ostream &operator<<(ostream &os, BinaryTree &bt) {
    bt.print2D();
    return os;
  }
  void print2DUtil(Node *root, int space) {
    // Base case
    if (root == NULL)
      return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
      cout << " ";
    cout << root->m_value << "\n";

    // Process left child
    print2DUtil(root->left, space);
  }

  // Wrapper over print2DUtil()
  void print2D() {
    // Pass initial space count as 0
    print2DUtil(root, 0);
  }
};
} // namespace ariel

#endif
