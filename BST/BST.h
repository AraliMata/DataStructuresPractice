#pragma once
#include <queue>
#include<iostream>

using namespace std;

class BST {

    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t) {
        if (t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t){
        if (t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if (x < t->data)
            t->left = insert(x, t->left);
        else if (x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* find(node* t, int x) {
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            return find(t->left, x);
        else if (x > t->data)
            return find(t->right, x);
        else
            return t;
    }

    void preorder(node* t);

    void postorder(node* t);

    void inorder(node* t);

    void levelOrder(node* t);

    int height(node* t);

    bool ancestors(node* t, int data1);

    int whatLevelAmI(node* t, int data1);
    

public:
    BST();

    ~BST();

    void find(int x);

    void insert(int x);

    void height();

    void display();

    void ancestors(int data);

    void whatLevelAmI(int data);

    void search(int x);

    void visit(int);
};



