#ifndef _BINARYTREENODE_H
#define _BINARYTREENODE_H

#include <memory>

template <class T>
class binary_tree_node
{
public:
    typedef binary_tree_node<T> node;

    T                     data;
    std::weak_ptr<node>   parent;
    std::shared_ptr<node> left_child;
    std::shared_ptr<node> right_child;

    explicit binary_tree_node(T const &value = T{})
        : data(value)
        , parent(std::weak_ptr<node>{})
        , left_child(std::shared_ptr<node>{})
        , right_child(std::shared_ptr<node>{})
    {
    }

    bool
    is_left_child()
    {
        if (auto sp = parent.lock()) {
            if (this == sp->left_child.get())
                return true;
        }
        return false;
    }

    bool
    is_right_child()
    {
        if (auto sp = parent.lock()) {
            if (this == sp->right_child.get())
                return true;
        }
        return false;
    }
};

#endif  // _BINARYTREENODE_H