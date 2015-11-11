//////////////////////////////////////////////////////////////////////////
//       Name: Jeremy Nims
// Assignment: Binary Trees Homework #10
//      Class: CPS 272, Wed 5:30
//    Comment: Unused functions are omitted from the BST class for
//             less printing.
//////////////////////////////////////////////////////////////////////////

#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct nodeType
{
    T info;
    nodeType<T> *lLink;
    nodeType<T> *rLink;
};

template <typename T>
class BinaryTreeType
{
protected:
    nodeType<T> *root;
public:
    BinaryTreeType();
    ~BinaryTreeType();
    virtual void insert(const T& item) = 0;
    void inOrderTraversal() const;
    void postOrderTraversal() const;
private:
    void inOrder(nodeType<T> *p) const;
    void postOrder(nodeType<T> *p) const;
    void destroy(nodeType<T> * &p);
};

template <typename T>
class BST : public BinaryTreeType<T>
{
public:
    void insert(const T& item);
};

template <typename T>
void BST<T>::insert(const T& item)
{
    nodeType<T> *newNode;
    nodeType<T> *current;
    nodeType<T> *trail;

    newNode = new nodeType<T>;
    newNode->info = item;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    if (root == nullptr)
        root = newNode;
    else
    {
        current = root;
        trail = nullptr;
        while (current != nullptr)
        {
            trail = current;

            if (current->info == item)
                return;
            else if (current->info > item)
                current = current->lLink;
            else
                current = current->rLink;
        }
        if (trail->info > item)
            trail->lLink = newNode;
        else
            trail->rLink = newNode;
    }
}

template <typename T>
BinaryTreeType<T>::~BinaryTreeType()
{
    destroy(root);
}

template <typename T>
void BinaryTreeType<T>::destroy(nodeType<T> * &p)
{
    if (p == nullptr)
        return;
    destroy(p->lLink);
    destroy(p->rLink);
    delete p;
    p = nullptr;
}

template <typename T>
void BinaryTreeType<T>::postOrderTraversal() const
{
    postOrder(root);
}

template <typename T>
void BinaryTreeType<T>::postOrder(nodeType<T> *p) const
{
    if (p != nullptr)
    {
        postOrder(p->lLink);
        postOrder(p->rLink);
        cout << p->info << " ";
    }
}

template <typename T>
void BinaryTreeType<T>::inOrderTraversal() const
{
    inOrder(root);
}

template <typename T>
void BinaryTreeType<T>::inOrder(nodeType<T> *p) const
{
    if (p != nullptr)
    {
        inOrder(p->lLink);
        cout << p->info << " ";
        inOrder(p->rLink);
    }
}

template <typename T>
BinaryTreeType<T>::BinaryTreeType()
{
    root = nullptr;
}
