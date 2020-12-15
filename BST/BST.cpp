#include "BST.h"

BST::BST() {
    root = NULL;
}

BST::~BST() {
    root = makeEmpty(root);
}

void BST::preorder(node* t) {
    if (t == NULL)
        return;

    cout << t->data << " ";
    preorder(t->left);
    preorder(t->right);
}

void BST::postorder(node* t) {
    if (t == NULL)
        return;

    postorder(t->left);
    postorder(t->right);
    cout << t->data << " ";
}

void BST::inorder(node* t) {
    if (t == NULL)
        return;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}

void BST::levelOrder(node* t) {

    queue<node* > qu;

    qu.push(root);

    while (!qu.empty())
    {
        node* temp_node = qu.front();
        cout << temp_node->data << " ";

        qu.pop();

        if (temp_node->left != NULL)
            qu.push(temp_node->left);
        if (temp_node->right != NULL)
            qu.push(temp_node->right);

    }

}

int BST::height(node* t) {

    if (t == NULL)
        return 0;
    else {
        int lHeight = height(t->left);
        int rHeight = height(t->right);

        if (lHeight > rHeight)
            return lHeight + 1;
        else
            return rHeight + 1;
    }
}

bool BST::ancestors(node* t, int data1) {

    if (t == NULL)
        return false;

    if (t->data == data1)
        return true;

    bool right = ancestors(t->right, data1);
    bool left = false;

    if (!right)
        left = ancestors(t->left, data1);

    if (left || right)
        cout << t->data << " ";

    return left || right;
}

int BST::whatLevelAmI(node* t, int data1) {

    if (t == NULL)
        return 0;

    if (t->data == data1)
        return 1;

    int right = whatLevelAmI(t->right, data1);
    int left = 0;

    if (right < 1)
        left = whatLevelAmI(t->left, data1);

    if (right > left)
        return right + 1;
    else if (left > right)
        return left + 1;

    return 0;
}

void BST::find(int x) {
        cout << find(root, x)->data;
    }

void BST::insert(int x) {
        root = insert(x, root);
    }

void BST::height() {

    int height1 = height(root);

    if (height1 == 0) 
        cout << "No hay nodos en el arbol" << endl;
    else
        cout << "La altura del arbol es: " << height1 << endl;
}

void BST::display() {
        inorder(root);
        cout << endl;
    }

void BST::ancestors(int data) {

    if (root->data == data)
        cout << "El nodo elegido es el raiz, no tiene antecesores " << endl;
    else {
        bool found = ancestors(root, data);
        if (!found)
            cout << "Dato no encontrado " << endl;
        cout << endl;
    }
}

void BST::whatLevelAmI(int data) {
        int level = whatLevelAmI(root, data);

        if (level == 0)
            cout << "Dato " << data << " no encontrado" << endl;
        else
            cout << "El dato " << data << " se encuentra en el nivel " << level << endl;
    }
    
void BST::search(int x) {
        root = find(root, x);
    }

void BST::visit(int x) {

    if (x == 1) {
        cout << " Preorder: ";
        preorder(root);
        cout << endl;
    }
    else if (x == 2) {
        cout << " Inorder: ";
        inorder(root);
        cout << endl;
    }
    else if (x == 3) {
        cout << " Postorder: ";
        postorder(root);
        cout << endl;
    }
    else if (x == 4) {
        cout << " Level by level: ";
        levelOrder(root);
        cout << endl;
    }
    else {
        cout << "Opcion no existente " << endl;
    }
}
    
