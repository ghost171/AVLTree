#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

template <class T> class AVLnode {
public:
    T key;
    int balance;
    AVLnode *left, *right, *parent;
    AVLnode(T k, AVLnode *p){
        key = k;
        balance = 0;
        parent = p;
        left = NULL;
        right = NULL;
    } 
    ~AVLnode() {
        delete left;
        delete right;
    }
};

template <class T> class AVLtree {
public:
    AVLtree(void);
    ~AVLtree(void);
    bool insert(T key);
    void deleteKey(const T key);
    void printBalance();
    void printTree();
private:
    AVLnode<T>* root;
    AVLnode<T>* rotateLeft(AVLnode<T> *node);
    AVLnode<T>* rotateRight(AVLnode<T> *node);
    AVLnode<T>* rotateBigRight(AVLnode<T> *node);
    AVLnode<T>* rotateBigLeft(AVLnode<T> *node);
    int getBalance(AVLnode<T> *node);                  
    void rebalance(AVLnode<T> *node);
    int height(AVLnode<T> *node);
    void setBalance(AVLnode<T> *node);
    void printTree(AVLnode<T> *node);
    void printBalance(AVLnode<T> *node);
    void clearNode(AVLnode<T> *node);
};
 
/* rebalance of AVL tree*/
template <class T> void AVLtree<T>::rebalance(AVLnode<T> *node) {
    setBalance(node);
    if (node->balance < -1) {
        if (height(node->left->left) >= height(node->left->right)){
            node = rotateRight(node);
        }
        else{
            node = rotateBigRight(node);
        }
    }else if(node->balance > 1){
        if(height(node->right->right) >= height(node->right->left)){
            node = rotateLeft(node);
        }
        else{
            node = rotateBigLeft(node);
        }
    }
    if(node->parent != NULL){
        rebalance(node->parent);
    }
    else{
        root = node;
    }
}
 
template <class T> AVLnode<T>* AVLtree<T>::rotateLeft(AVLnode<T> *a){
    AVLnode<T> *b = a->right;
    b->parent = a->parent;
    a->right = b->left;
    if (a->right != NULL)
        a->right->parent = a;
    b->left = a;
    a->parent = b;
    if(b->parent != NULL){
        if(b->parent->right == a){
            b->parent->right = b;
        }
        else{
            b->parent->left = b;
        }
    }
    setBalance(a);
    setBalance(b);
    return b;
}
 
template <class T> AVLnode<T>* AVLtree<T>::rotateRight(AVLnode<T> *a) {
    AVLnode<T> *b = a->left;
    b->parent = a->parent;
    a->left = b->right;
    if (a->left != NULL)
        a->left->parent = a;
    b->right = a;
    a->parent = b;
    if (b->parent != NULL) {
        if (b->parent->right == a) {
            b->parent->right = b;
        }
        else {
            b->parent->left = b;
        }
    }
    setBalance(a);
    setBalance(b);
    return b;
}
 
 //make big right rotate
template <class T> AVLnode<T>* AVLtree<T>::rotateBigRight(AVLnode<T> *node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

//make big left rotate
template <class T> AVLnode<T>* AVLtree<T>::rotateBigLeft(AVLnode<T> *node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

//make height of this level
template <class T> int AVLtree<T>::height(AVLnode<T> *node){
    if (node == NULL)
        return -1;
    return 1 + max(height(node->left), height(node->right));
}

template <class T> void AVLtree<T>::setBalance(AVLnode<T> *node){
    node->balance = height(node->right) - height(node->left);
}

//print balnce to check correct of the program
template <class T> void AVLtree<T>::printBalance(AVLnode<T> *node){
    if(node != NULL){
        printBalance(node->left);
        cout << node->balance << " ";
        printBalance(node->right);
    }
}

template <class T> void AVLtree<T>::printTree(AVLnode<T> *node){
    if(node != NULL){
        printTree(node->left);
        cout << node->key << " ";
        printTree(node->right);
    }
}

//constructor
template <class T> AVLtree<T>::AVLtree(void){
    root = NULL;
}

//destructor
template <class T> AVLtree<T>::~AVLtree(void) {
    delete root;
}

//inserting object
template <class T> bool AVLtree<T>::insert(T key) {
    if (root == NULL) {
        root = new AVLnode<T>(key, NULL);
    }
    else{
        AVLnode<T> *n = root, *parent;
        while(true){
            if(n->key == key){
                return false;
            }
            parent = n;
            if(n->key > key){
                n = n->left;
            }
            else{
                n = n->right;
            }
            if (n == NULL) {
                if (parent->key > key){
                    parent->left = new AVLnode<T>(key, parent);
                }
                else{
                    parent->right = new AVLnode<T>(key, parent);
                } 
                rebalance(parent);
                break;
            }
        }
    }
    return true;
}

template <class T> void AVLtree<T>::printBalance(){
    cout << "Printing balance: ";
    printBalance(root);
    cout << endl;
}

template <class T> void AVLtree<T>::printTree(){
    cout << "Printing tree: ";
    printTree(root);
    cout << endl;
}

int main(void){
    AVLtree<int> t;
    for (int i = 1; i <= 10; i++){
        t.insert(i);
    }
    t.printBalance();
    t.printTree();
}
 
