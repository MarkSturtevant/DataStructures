#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <stdexcept>

template <typename Comparable>
struct BNode {
    Comparable val;
    BNode* left;
    BNode* right;
};

template <typename Comparable>
class BinarySearchTree {
private:
    BNode<Comparable>* root;

    void clearRecursively(BNode<Comparable>* root);
    void copyTree(BNode<Comparable>* me, BNode<Comparable>* other);
    void print_tree_section(int depth, BNode<Comparable>* section, std::ostream& os = std::cout) const;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<Comparable>& other);
    BinarySearchTree& operator=(const BinarySearchTree<Comparable>& other);

    bool contains(const Comparable& obj) const;
    void insert(const Comparable& obj);
    void remove(const Comparable& obj);
    void make_empty();
    bool is_empty() const;

    const Comparable& find_min() const;
    const Comparable& find_max() const;
    void print_tree(std::ostream& os = std::cout) const;
};

template <typename Comparable>
void BinarySearchTree<Comparable>::clearRecursively(BNode<Comparable> *root) {
    if (root == nullptr)
        return;
    if (root->left != nullptr)
        this->clearRecursively(root->left);
    if (root->right != nullptr)
        this->clearRecursively(root->right);
    delete root;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::copyTree(BNode<Comparable>* me, BNode<Comparable>* other) {
    me->val = other->val;

    if (other->left != nullptr) {
        me->left = new BNode<Comparable>;
        this->copyTree(me->left, other->left);
    }
    else me->left = nullptr;

    if (other->right != nullptr) {
        me->right = new BNode<Comparable>;
        this->copyTree(me->right, other->right);
    }
    else me->right = nullptr;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::make_empty() {
    this->clearRecursively(this->root);
    this->root = nullptr;
}

template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree<Comparable>() {
    this->make_empty();
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree() : root(nullptr) {}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree<Comparable> &other) :
        root(nullptr) {
    if (other.root == nullptr)
        return;
    else {
        this->root = new BNode<Comparable>;
        this->copyTree(this->root, other.root);
    }
}

template <typename Comparable>
BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(const BinarySearchTree<Comparable> &other) {
    if (this == &other)
        return *this;

    this->make_empty();

    if (other.root != nullptr) {
        this->root = new BNode<Comparable>;
        this->copyTree(this->root, other.root);
    }
    return *this;
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &obj) const {
    BNode<Comparable>* temp = this->root;
    while (temp != nullptr) {
        if (temp->val == obj)
            return true;
        else if (temp->val > obj)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &obj) {
    BNode<Comparable>* toAdd = new BNode<Comparable>;
    toAdd->val = obj;
    toAdd->left = nullptr;
    toAdd->right = nullptr;

    if (this->root == nullptr) { // special case; tree is empty
        this->root = toAdd;
        return;
    }

    BNode<Comparable>* temp = this->root;
    while (temp->val != obj) {
        if (temp->val > obj) {
            if (temp->left == nullptr) { // empty insert spot found.
                temp->left = toAdd;
                return;
            }
            temp = temp->left;
        }
        else {
            if (temp->right == nullptr) { // empty insert spot found.
                temp->right = toAdd;
                return;
            }
            temp = temp->right;
        }
    }

    // found the object in the tree.
    delete toAdd;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &obj) {
    bool turnRight = false;
    BNode<Comparable>* parent = nullptr;
    BNode<Comparable>* temp = this->root;
    while (temp != nullptr && temp->val != obj) {
        parent = temp;

        if (temp->val > obj) {
            temp = temp->left;
            turnRight = false;
        }
        else {
            temp = temp->right;
            turnRight = true;
        }

    }

    if (temp == nullptr) // object not in tree.
        return;

    if (temp->left != nullptr && temp->right != nullptr) { // has two children
        BNode<Comparable>* temp2 = temp->right;
        BNode<Comparable>* parent2 = temp;
        while (temp2->left != nullptr) {
            parent2 = temp2;
            temp2 = temp2->left;
        }
        if (parent2 == temp) { // delete right node (temp2) of parent2 aka temp
            if (temp2->right != nullptr)
                parent2->right = temp2->right;
            else parent2->right = nullptr;
        } else { // delete left node (temp2) of parent2
            if (temp2->right != nullptr)
                parent2->left = temp2->right;
            else parent2->left = nullptr;
        }

        temp->val = temp2->val;
        delete temp2;
    }
    else if (temp->left != nullptr) { // has left child
        if (parent == nullptr) { // root node
            temp = temp->left;
            delete this->root;
            this->root = temp;
        } else {
            if (turnRight)
                parent->right = temp->left;
            else parent->left = temp->left;
            delete temp;
        }
    }
    else if (temp->right != nullptr) { // has right child
        if (parent == nullptr) { // root node
            temp = temp->right;
            delete this->root;
            this->root = temp;
        } else {
            if (turnRight)
                parent->right = temp->right;
            else parent->left = temp->right;
            delete temp;
        }

    }
    else { // has no children
        if (parent == nullptr) { // root node
            delete this->root;
            this->root = nullptr;
        }
        else {
            if (turnRight)
                parent->right = nullptr;
            else parent->left = nullptr;
            delete temp;
        }
    }
}

template <typename Comparable>
const Comparable& BinarySearchTree<Comparable>::find_min() const {
    if (this->root == nullptr)
        throw std::invalid_argument("Empty Tree!");

    BNode<Comparable>* temp = this->root;
    while (temp->left != nullptr)
        temp = temp->left;

    return temp->val;
}

template <typename Comparable>
const Comparable& BinarySearchTree<Comparable>::find_max() const {
    if (this->root == nullptr)
        throw std::invalid_argument("Empty Tree!");

    BNode<Comparable>* temp = this->root;
    while (temp->right != nullptr)
        temp = temp->right;

    return temp->val;
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::is_empty() const {
    return this->root == nullptr;
}

template<typename Comparable>
void BinarySearchTree<Comparable>::print_tree_section(int depth, BNode<Comparable> *section, std::ostream &os) const {
    if (section->right != nullptr)
        print_tree_section(depth + 1, section->right, os);

    if (depth > 0)
        os << std::string(depth * 2, ' ');
    os << section->val << "\n";

    if (section->left != nullptr)
        print_tree_section(depth + 1, section->left, os);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::print_tree(std::ostream &os) const {
    if (this->root == nullptr) {
        os << "<empty>\n";
        return;
    }
    this->print_tree_section(0, this->root, os);
}

#endif