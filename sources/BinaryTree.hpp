#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <stdexcept>
#include "Node.hpp"
using namespace std;
constexpr int COUNT = 10;

namespace ariel
{

  template <typename T>
  class BinaryTree
  {

  public:
    // inner class

    BinaryTree() : root(nullptr) {}

    ~BinaryTree()
    {
      remove(root);
    }

    void remove(Node<T> *root)
    {
      if (!root)
      {
        return;
      }
      remove(root->left);
      remove(root->right);
      delete root;
    }

    void search(struct Node<T> *node, T key)
    {
      if (!node)
      {
        return;
      }

      if (node->m_value == key)
      {
        this->existing_element = node;
        return;
      }

      /* then recur on left sutree */
      search(node->right, key);

      search(node->left, key);
    }

    BinaryTree<T> &add_root(T s)
    {
      if (root)
      {
        root->m_value = s;
      }
      else
      {
        root = new Node<T>(s);
      }
      return *this;
    }

    bool isEmpty() const { return root == nullptr; }

    BinaryTree<T> &add_left(T exists, T add_this)
    {
      search(root, exists);
      if (!existing_element)
      {
        throw std::runtime_error("No item found");
      }

      if (existing_element->left)
      {
        existing_element->left->m_value = add_this;
      }
      else
      {
        existing_element->left = new Node<T>(add_this);
      }

      existing_element = NULL;
      return *this;
    }
    BinaryTree<T> &add_right(T exists, T add_this)
    {
      search(root, exists);
      if (!existing_element)
      {
        throw std::runtime_error("No item found");
      }

      if (existing_element->right)
      {
        existing_element->right->m_value = add_this;
      }
      else
      {
        existing_element->right = new Node<T>(add_this);
      }

      existing_element = NULL;
      return *this;
    }

    // private:
    // Avoid copying
    //MOVE ASSIGNMENT
    BinaryTree &operator=(BinaryTree &&other) noexcept
    {
      if (root)
      {
        remove(root);
      }
      root = other.root;
      other.root = nullptr;
      return *this;
    }
    //
    BinaryTree(const BinaryTree &&other) noexcept
        : root(other.root)
    {
    }
    //MOVE CONSTRUCTOR
    BinaryTree(BinaryTree &&other) noexcept
    {
      root = other.root;
      other.root = nullptr;
    }
    //COPY CONSTRUCTOR
    BinaryTree(BinaryTree const &other) : root(nullptr)
    {
      std::vector<Node<T> const *> remaining;
      Node<T> const *cur = other.root;
      this->add_root(cur->m_value);
    }
    void swap(BinaryTree &rhs) noexcept
    {
      using std::swap;
      swap(root, rhs.root);
    }
    BinaryTree<T> &operator=(const BinaryTree<T> &other)
    {
      if (this != &other)
      {
        remove(root);
        root = new Node<T>(*other.root);
      }
      return *this;
    }

    // fields
    Node<T> *root;
    Node<T> *existing_element = NULL;
    Node<T> *getRoot() { return root; }

    //-------------------------------------------------------------------
    // iterator related code:
    // inner class and methods that return instances of it)
    //-------------------------------------------------------------------
    class iterator
    {
    private:
      Node<T> *pointer_to_current_node;
      Node<T> *temp = NULL;
      vector<Node<T> *> nodeStack;
      int flag;

      void preorder_stack()
      {
        if (!pointer_to_current_node)
        {
          return;
        }

        stack<Node<T> *> s1;
        s1.push(pointer_to_current_node);
        Node<T> *node = nullptr;

        // Run while first stack is not empty
        while (!s1.empty())
        {
          // Pop an item from s1 and push it to s2
          node = s1.top();
          s1.pop();
          nodeStack.push_back(node);

          // Push left and right children
          // of removed item to s1
          if (node->right)
          {
            s1.push(node->right);
          }
          if (node->left)
          {
            s1.push(node->left);
          }
        }
      }
      void inorder_stack()
      {
        if (!pointer_to_current_node)
        {
          return;
        }

        stack<Node<T> *> s1;
        Node<T> *curr = pointer_to_current_node;
        while (curr || s1.empty() == false)
        {

          while (curr)
          {
            s1.push(curr);
            curr = curr->left;
          }
          curr = s1.top();
          nodeStack.push_back(curr);
          s1.pop();
          curr = curr->right;
        }
      }
      void postorder_stack()
      {
        if (!pointer_to_current_node)
        {
          return;
        }

        stack<Node<T> *> temp;
        temp.push(pointer_to_current_node);
        Node<T> *node = nullptr;

        while (!temp.empty())
        {
          node = temp.top();
          temp.pop();
          nodeStack.push_back(node);

          if (node->left)
          {
            temp.push(node->left);
          }
          if (node->right)
          {
            temp.push(node->right);
          }
        }
        reverse(nodeStack.begin(), nodeStack.end());
      }

    public:
      iterator(Node<T> *ptr = nullptr, int type = 0)
          : pointer_to_current_node(ptr), flag(type)
      {
        if (flag == 0)
        {
          inorder_stack();
        }
        else if (flag == 1)
        {
          preorder_stack();
        }
        else
        {
          postorder_stack();
        }
      }
      T &operator*() const
      {
        if (!pointer_to_current_node)
        {
          cout << "No value in node" << endl;
        }
        return pointer_to_current_node->m_value;
      }

      T *operator->() const { return &(pointer_to_current_node->m_value); }

      // ++i;
      iterator &operator++()
      {
        if (!nodeStack.empty())
        {
          pointer_to_current_node = nodeStack.at(0);
          nodeStack.erase(nodeStack.begin());
        }
        else
        {
          pointer_to_current_node = NULL;
        }
        return *this;
      }

      iterator operator++(int)
      {
        iterator tmp = *this;
        if (!nodeStack.empty())
        {
          pointer_to_current_node = nodeStack.at(0);
          nodeStack.erase(nodeStack.begin());
        }
        else
        {
          pointer_to_current_node = NULL;
        }
        return tmp;
      }

      bool operator==(const iterator &rhs) const
      {
        return pointer_to_current_node == rhs.pointer_to_current_node;
      }

      bool operator!=(const iterator &rhs) const
      {
        return pointer_to_current_node != rhs.pointer_to_current_node;
      }
    }; // END OF CLASS ITERATOR

    iterator begin()
    {
      return ++iterator{root, 0};
    }

    iterator end()
    {
      // return nullptr;
      return iterator{nullptr, 0};
    }

    iterator begin_preorder() { return ++iterator{root, 1}; }

    iterator end_preorder() { return iterator{nullptr, 1}; }

    iterator begin_postorder()
    {
      return ++iterator{root, 2};
    }

    iterator end_postorder()
    {
      return iterator{nullptr, 2};
    }

    iterator begin_inorder()
    {
      return ++iterator{root, 0};
    }

    iterator end_inorder()
    {
      return iterator{nullptr, 0};
    }

    friend ostream &operator<<(ostream &os, BinaryTree &bt)
    {
      bt.print2D();
      return os;
    }
    void print2DUtil(Node<T> *root, int space)
    {
      // Base case
      if (!root)
      {
        return;
      }

      // Increase distance between levels
      space += COUNT;

      // Process right child first
      print2DUtil(root->right, space);

      // Print current node after space
      // count
      cout << endl;
      for (int i = COUNT; i < space; i++)
      {
        cout << " ";
      }
      cout << root->m_value << "\n";

      // Process left child
      print2DUtil(root->left, space);
    }

    // Wrapper over print2DUtil()
    void print2D()
    {
      // Pass initial space count as 0
      print2DUtil(root, 0);
    }
  };
} // namespace ariel

#endif
