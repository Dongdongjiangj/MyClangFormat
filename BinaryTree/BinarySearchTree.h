//
// Created by Dong on 2021/2/3.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTreeNode.h"
#include <iostream>
#include <initializer_list>

template <class T>
class binary_search_tree
{
public:
    typedef binary_tree_node<T> node;
    binary_search_tree()  = default;
    ~binary_search_tree() = default;
    binary_search_tree(std::initializer_list<T> il)
    {
        for (auto const &value : il)
            this->insert(value);
    }

private:
    std::shared_ptr<node> root;

    void
    insert_(std::shared_ptr<node> &target, T const &value)
    {
        if (!target) {
            target = std::make_shared<node>(value);
            return;
        }
        if (value < target->data)
            insert_(target->left_child, value);
        else
            insert_(target->right_child, value);
    }

    void
    traverse_(std::shared_ptr<node> sp) const
    {
        if (sp) {
            if (sp->left_child)
                traverse_(sp->left_child);
            std::cout << sp->data << " ";
            if (sp->right_child)
                traverse_(sp->right_child);
        }
    }

public:
    void
    insert(T const &value)
    {
        insert_(root, value);
    }
    void
    traverse() const
    {
        traverse_(root);
        endl(std::cout);
    }
    void
    clear()
    {
        root.reset();
    }
};

#endif  // BINARYSEARCHTREE_H
