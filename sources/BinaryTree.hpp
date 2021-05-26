#pragma once
#include <iostream>
#include <stdbool.h>
using namespace std;
namespace ariel
{

    template <typename T>
    class BinaryTree
    {

    public:
    
        BinaryTree(){}
        ~BinaryTree(){}
        BinaryTree <T> &add_root(const T &t1){
            return *this;
        }
        BinaryTree <T> &add_left(const T &t1, const T &t2){
            return *this;
        }
        BinaryTree <T> &add_right(const T &t1, const T &t2){
            return *this;
        }
        friend ostream &operator<<(ostream &os, const BinaryTree &Bt){
            return os<<"operator << - unimplemented";
        }

    private:
        struct Bnode
        {
            T node_val;
            Bnode *r_node;
            Bnode *l_node;
            Bnode(const T &n_val, Bnode *r_n, Bnode *l_n)
                : node_val(n_val), r_node(r_n), l_node(l_n){
            }
        };
        Bnode *main_root;


    public:
        class iterator
        {
            private:
                Bnode *p;
            public:
                iterator(Bnode* ptr= nullptr): p(ptr){}
                T& operator*() const{
                    return p->node_val;
                }
                T* operator->() const {
                    return &(p->node_val);
                }
                iterator &operator ++()
                {
                    p=p->r_node;
                    return *this;
                }
                bool operator==(const iterator& Bi) const
                {
                    return p==Bi.p;
                }
                bool operator!=(const iterator& Bi) const
                {
                    return p!=Bi.p;
                }
        };

        iterator begin() {
            return iterator(main_root);
        }
        iterator end() {
            return iterator(main_root);
        }
        iterator begin_preorder() {
            return iterator(main_root);
        }
        iterator end_preorder() {
            return iterator(main_root);
        }
        iterator begin_inorder() {
            return iterator(main_root);
        }
        iterator end_inorder() {
            return iterator(main_root);
        }
        iterator begin_postorder() {
            return iterator(main_root);
        }
        iterator end_postorder() {
            return iterator(main_root);
        }
    };


}