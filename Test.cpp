#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
#include "BinaryTree.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("BASIC TESTS")
{
    CHECK_NOTHROW(BinaryTree<int> tree_of_ints);
    BinaryTree<int> tree_of_ints;
    SUBCASE("PRE-ADDED ROOT")
    {
        // make an iterator before add root.
        CHECK(tree_of_ints.begin_inorder() == nullptr);
        CHECK_FALSE(tree_of_ints.begin_preorder() == nullptr);
        CHECK_FALSE(tree_of_ints.begin_postorder() == nullptr);

        //can't add left/right child before add root.
        for (int i = 0; i < 5; i++)
        {
            CHECK_THROWS(tree_of_ints.add_left(i, i * 2));
            CHECK_THROWS(tree_of_ints.add_right(i, i * 2));
        }
    }
    SUBCASE("add root")
    {

        for (int i = 0; i <= 10; i++)
        {
            CHECK_NOTHROW(tree_of_ints.add_root(i));
        }
    }
    SUBCASE("add left")
    {
        tree_of_ints.add_root(10);

        for (int i = 0; i < 5; i++)
        {
            CHECK_NOTHROW(tree_of_ints.add_left(10, i));
        }

        CHECK_NOTHROW(tree_of_ints.add_left(9, 8));

        for (int i = 8; i > 0; i--)
        {
            CHECK_NOTHROW(tree_of_ints.add_left(i, i - 1));
        }
    }

    SUBCASE("add right")
    {
        tree_of_ints.add_root(10);

        for (int i = 0; i < 5; i++)
        {
            CHECK_NOTHROW(tree_of_ints.add_right(10, i));
        }

        CHECK_NOTHROW(tree_of_ints.add_right(9, 8));

        for (int i = 8; i > 0; i--)
        {
            CHECK_NOTHROW(tree_of_ints.add_right(i, i - 1));
        }
    }
}
