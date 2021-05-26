#include "doctest.h"
#include <iostream>
#include <string>
#include "sources/BinaryTree.hpp"

using namespace std;
using namespace ariel;


TEST_CASE("tree (char) test")
{
    BinaryTree<char> BtreeChar;
    CHECK_NOTHROW(BtreeChar.add_root('a'));
    CHECK_NOTHROW(BtreeChar.add_right('a', 'i'));
    CHECK_THROWS(BtreeChar.add_left('x', 'g'));
    CHECK_NOTHROW(BtreeChar.add_right('i', 'r'));
    CHECK_NOTHROW(BtreeChar.add_left('i', 't'));
    CHECK_THROWS(BtreeChar.add_left('u', 'v'));
    CHECK_NOTHROW(BtreeChar.add_left('a', 'm'));
    CHECK_THROWS(BtreeChar.add_left('y', 'w'));
    CHECK_NOTHROW(BtreeChar.add_right('m', 'l'));
}

TEST_CASE("tree (string) check")
{
    BinaryTree<string> BtreeStr;
    BtreeStr.add_root("Blah");
    CHECK_NOTHROW(BtreeStr.add_left("Blah", "BlingL"));
    CHECK_NOTHROW(BtreeStr.add_right("Blah", "BlingR"));
    CHECK_THROWS(BtreeStr.add_left("BlahNo", "Blik"));
    CHECK_THROWS(BtreeStr.add_right("BlAS", "Blok"));
    CHECK_NOTHROW(BtreeStr.add_right("BlingR", "BBRight"));
}

TEST_CASE("tree (double) check")
{
    BinaryTree<double> BtreeDbl;
    BtreeDbl.add_root(5.2);
    CHECK_NOTHROW(BtreeDbl.add_left(5.2, 4.5));
    CHECK_NOTHROW(BtreeDbl.add_right(5.2, 3.7));
    CHECK_THROWS(BtreeDbl.add_left(7.5, 5.6));
    CHECK_NOTHROW(BtreeDbl.add_left(3.7, 7.0));
    CHECK_THROWS(BtreeDbl.add_left(8.5, 4.6));
    CHECK_NOTHROW(BtreeDbl.add_right(7.0, 5.6));
    CHECK_THROWS(BtreeDbl.add_left(7.5, 5.6));
}

TEST_CASE("tree (int) + traversal checks")
{
    BinaryTree<int> BtreeInt;
    BtreeInt.add_root(2);
    CHECK_NOTHROW(BtreeInt.add_left(2, 5));
    CHECK_THROWS(BtreeInt.add_right(9,2));
    CHECK_NOTHROW(BtreeInt.add_right(2, 4));
    CHECK_NOTHROW(BtreeInt.add_left(4, 1));
    CHECK_NOTHROW(BtreeInt.add_left(5, 7));
    CHECK_THROWS(BtreeInt.add_right(11,4));
    CHECK_NOTHROW(BtreeInt.add_right(7, 3));
    CHECK_NOTHROW(BtreeInt.add_left(7, 10));

    int i = 0;
    int TestArrPre[7] = {2, 5, 7, 10, 3, 4, 1};
    int TestArrIn[7] = {10, 7, 3, 5, 2, 1, 4};
    int TestArrPost[7] = {10, 3, 7, 5, 1, 4, 2};

    SUBCASE("preorder tree check")
    {
        for (auto it = BtreeInt.begin_preorder(); it != BtreeInt.end_preorder(); ++it)
        {
            CHECK_EQ(*it, TestArrPre[i]);
            i++;
        }
    }

    SUBCASE("inorder tree check")
    {
        for (auto it = BtreeInt.begin_inorder(); it != BtreeInt.end_inorder(); ++it)
        {
            CHECK_EQ(*it, TestArrIn[i]);
            i++;
        }
    }

    SUBCASE("postorder tree check")
    {
        for (auto it = BtreeInt.begin_postorder(); it != BtreeInt.end_postorder(); ++it)
        {
            CHECK_EQ(*it, TestArrPost[i]);
            i++;
        }
    }
}
