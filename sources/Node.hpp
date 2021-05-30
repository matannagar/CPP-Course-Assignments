#pragma once

namespace ariel
{
    template <typename T>
    struct Node
    {
        T m_value;
        Node *left;
        Node *right;
        Node(const T &v) : m_value(v), left(nullptr), right(nullptr) {}
        Node(const Node &other)
            : m_value(other.m_value)
        {
            if (other.right)
            {
                right = new Node(*other.right);
            }
            else
            {
                right = nullptr;
            }
            if (other.left)
            {
                left = new Node(*other.left);
            }
            else
            {
                left = nullptr;
            }
        }
    };
}
