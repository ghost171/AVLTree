# AVL Tree
## How to execute?
```
  make -B
  ./bin/set
 ```
## What is the AVLtree?
In computer science, an AVL tree (named after inventors Adelson-Velsky and Landis) is a self-balancing binary search tree. It was the first such data structure to be invented.[2] In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Lookup, insertion, and deletion all take O(log n) time in both the average and worst cases, where n {\displaystyle n} n is the number of nodes in the tree prior to the operation. Insertions and deletions may require the tree to be rebalanced by one or more tree rotations. 
## There are functions in that tree.
  This is rotates of the tree:
  ```
    AVLnode<T>* rotateLeft(AVLnode<T> *node);
    AVLnode<T>* rotateRight(AVLnode<T> *node);
    AVLnode<T>* rotateBigRight(AVLnode<T> *node);
    AVLnode<T>* rotateBigLeft(AVLnode<T> *node);
   ```
   This is functions that can help us to correct the program
   It's get us balance on every node of this tree:
   
    int getBalance(AVLnode<T> *node);                  
    void rebalance(AVLnode<T> *node);
    void setBalance(AVLnode<T> *node);
   This function get us height to get balnce of the tree:
      
    int height(AVLnode<T> *node);
   This functions print keys og the tree and balances: 
   
    void printTree(AVLnode<T> *node);
    void printBalance(AVLnode<T> *node);
