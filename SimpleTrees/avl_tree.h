#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <stdexcept>

template <typename Comparable>
struct Node {
    Comparable val;
    int height;
    Node* left;
    Node* right;
};

template <typename Comparable>
class AVLTree {
private:
    Node<Comparable>* root;

    void clearRecursively(Node<Comparable>* current);
    void copyTree(Node<Comparable>* me, Node<Comparable>* other);
    void print_tree_section(int depth, Node<Comparable>* section, std::ostream& os = std::cout) const;

    void updateHeight(Node<Comparable>* node);
    bool isUnbalanced(Node<Comparable>* node);
    bool isRightMore(Node<Comparable>* node);

    void recursiveAdd(Node<Comparable>* current, const Comparable& obj);
    void recursiveRemove(Node<Comparable>* parent, Node<Comparable>* node, bool turnRight, const Comparable& obj);
    void recursiveRemove2(Node<Comparable>* original, Node<Comparable>* parent, Node<Comparable>* node, bool turnRight);
    void rotate(Node<Comparable>* grandparent);

public:
    AVLTree();
    ~AVLTree();
    AVLTree(const AVLTree<Comparable>& other);
    AVLTree& operator=(const AVLTree<Comparable>& other);

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
void AVLTree<Comparable>::clearRecursively(Node<Comparable> *current) {
    if (current == nullptr)
        return;
    if (current->left != nullptr)
        this->clearRecursively(current->left);
    if (current->right != nullptr)
        this->clearRecursively(current->right);
    delete current;
}

template <typename Comparable>
void AVLTree<Comparable>::copyTree(Node<Comparable>* me, Node<Comparable>* other) {
    me->val = other->val;
    me->height = other->height;

    if (other->left != nullptr) {
        me->left = new Node<Comparable>;
        this->copyTree(me->left, other->left);
    }
    else me->left = nullptr;

    if (other->right != nullptr) {
        me->right = new Node<Comparable>;
        this->copyTree(me->right, other->right);
    }
    else me->right = nullptr;
}

template <typename Comparable>
void AVLTree<Comparable>::make_empty() {
    this->clearRecursively(this->root);
    this->root = nullptr;
}

template <typename Comparable>
AVLTree<Comparable>::~AVLTree<Comparable>() {
    this->make_empty();
}

template <typename Comparable>
AVLTree<Comparable>::AVLTree() : root(nullptr) {}

template <typename Comparable>
AVLTree<Comparable>::AVLTree(const AVLTree<Comparable> &other) :
        root(nullptr) {
    if (other.root == nullptr)
        return;
    else {
        this->root = new Node<Comparable>;
        this->copyTree(this->root, other.root);
    }
}

template <typename Comparable>
AVLTree<Comparable>& AVLTree<Comparable>::operator=(const AVLTree<Comparable> &other) {
    if (this == &other)
        return *this;

    this->make_empty();

    if (other.root != nullptr) {
        this->root = new Node<Comparable>;
        this->copyTree(this->root, other.root);
    }
    return *this;
}

template <typename Comparable>
bool AVLTree<Comparable>::contains(const Comparable &obj) const {
    Node<Comparable>* temp = this->root;
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
void AVLTree<Comparable>::updateHeight(Node<Comparable> *node) {
    node->height = 1 + std::max(
            (node->left == nullptr ? -1 : node->left->height),
            (node->right == nullptr ? -1 : node->right->height));
}

template <typename Comparable>
bool AVLTree<Comparable>::isUnbalanced(Node<Comparable> *node) {
    return std::abs(
                (node->left == nullptr ? -1 : node->left->height) -
                (node->right == nullptr ? -1 : node->right->height)
            ) >= 2;
}

template <typename Comparable>
void AVLTree<Comparable>::recursiveAdd(Node<Comparable>* current, const Comparable &obj) {
    if (current->val == obj)
        return;
    else if (current->val < obj) {
        if (current->right == nullptr) {
            Node<Comparable>* toAdd = new Node<Comparable>;
            toAdd->height = 0;
            toAdd->right = nullptr;
            toAdd->left = nullptr;
            toAdd->val = obj;
            current->right = toAdd;
        }
        else {
            this->recursiveAdd(current->right, obj);
        }
    } else {
        if (current->left == nullptr) {
            Node<Comparable>* toAdd = new Node<Comparable>;
            toAdd->height = 0;
            toAdd->right = nullptr;
            toAdd->left = nullptr;
            toAdd->val = obj;
            current->left = toAdd;
        }
        else {
            this->recursiveAdd(current->left, obj);
        }
    }

    this->updateHeight(current);
    if (this->isUnbalanced(current))
        this->rotate(current);
}

template <typename Comparable>
void AVLTree<Comparable>::insert(const Comparable &obj) {
    if (this->root == nullptr) {
        this->root = new Node<Comparable>;
        this->root->height = 0;
        this->root->right = nullptr;
        this->root->left = nullptr;
        this->root->val = obj;
    }
    else this->recursiveAdd(this->root, obj);
}

template <typename Comparable>
void AVLTree<Comparable>::recursiveRemove(Node<Comparable> *parent, Node<Comparable> *node, bool turnRight, const Comparable &obj) {
    if (node == nullptr)
        return;
    else if (node->val < obj) {
        this->recursiveRemove(node, node->right, true, obj);
    }
    else if (node->val > obj) {
        this->recursiveRemove(node, node->left, false, obj);
    }
    else { // found the node to remove.
        if (node->left != nullptr && node->right != nullptr)
            recursiveRemove2(node, node, node->right, true);
        else if (node->left != nullptr) { // left child only
            if (parent == nullptr) { // root node
                node = node->left;
                delete this->root;
                this->root = node;
            } else {
                if (turnRight)
                    parent->right = node->left;
                else parent->left = node->left;
                delete node;
            }
        }
        else if (node->right != nullptr) { // right child only
            if (parent == nullptr) { // root node
                node = node->right;
                delete this->root;
                this->root = node;
            } else {
                if (turnRight)
                    parent->right = node->right;
                else parent->left = node->right;
                delete node;
            }
        }
        else { // no children
            if (parent == nullptr) { // root node
                delete this->root;
                this->root = nullptr;
            }
            else {
                if (turnRight)
                    parent->right = nullptr;
                else parent->left = nullptr;
                delete node;
            }
        }
        return;
    }

    this->updateHeight(node);
    if (this->isUnbalanced(node))
        this->rotate(node);
}

template<typename Comparable>
void AVLTree<Comparable>::recursiveRemove2(Node<Comparable>* original, Node<Comparable> *parent, Node<Comparable> *node, bool turnRight) {
    if (node->left != nullptr)
        this->recursiveRemove2(original, node, node->left, false);
    else {
        if (node->right != nullptr) {
            if (turnRight)
                parent->right = node->right;
            else parent->left = node->right;
        }
        else {
            if (turnRight)
                parent->right = nullptr;
            else parent->left = nullptr;
        }
        original->val = node->val;
        delete node;
    }

    this->updateHeight(parent);
    if (this->isUnbalanced(parent))
        this->rotate(parent);
}

template <typename Comparable>
void AVLTree<Comparable>::remove(const Comparable &obj) {
    this->recursiveRemove(nullptr, this->root, false, obj);
}

template <typename Comparable>
bool AVLTree<Comparable>::isRightMore(Node<Comparable> *node) {
    return (node->right == nullptr ? -1 : node->right->height) > (node->left == nullptr ? -1 : node->left->height);
}

template <typename Comparable>
void AVLTree<Comparable>::rotate(Node<Comparable> *grandparent) {
    bool rightFirst;
    bool rightSecond;
    Node<Comparable>* parent;
    Node<Comparable>* child;

    if (this->isRightMore(grandparent)) {
        parent = grandparent->right;
        rightFirst = true;
    } else {
        parent = grandparent->left;
        rightFirst = false;
    }

    if (this->isRightMore(parent)) {
        child = parent->right;
        rightSecond = true;
    } else {
        child = parent->left;
        rightSecond = false;
    }

    if (rightFirst && rightSecond) { // rightFirst, rightSecond
        parent->right = parent->left;
        parent->left = grandparent->left;
        grandparent->right = child;
        grandparent->left = parent;
        // perform swap
        std::swap(grandparent->val, parent->val);
    }
    else if (! rightFirst && ! rightSecond) { // leftFirst, leftSecond
        parent->left = parent->right;
        parent->right = grandparent->right;
        grandparent->left = child;
        grandparent->right = parent;
        // perform swap
        std::swap(grandparent->val, parent->val);
    }
    else if (rightFirst) { // rightFirst, leftSecond
        parent->left = child->right;
        child->right = child->left;
        child->left = grandparent->left;
        grandparent->left = child;
        // perform swap
        std::swap(grandparent->val, child->val);
    }
    else { // leftFirst, rightSecond
        parent->right = child->left;
        child->left = child->right;
        child->right = grandparent->right;
        grandparent->right = child;
        // perform swap
        std::swap(grandparent->val, child->val);
    }

    this->updateHeight(child);
    this->updateHeight(parent);
    this->updateHeight(grandparent);
}

template <typename Comparable>
const Comparable& AVLTree<Comparable>::find_min() const {
    if (this->root == nullptr)
        throw std::invalid_argument("Empty Tree!");

    Node<Comparable>* temp = this->root;
    while (temp->left != nullptr)
        temp = temp->left;

    return temp->val;
}

template <typename Comparable>
const Comparable& AVLTree<Comparable>::find_max() const {
    if (this->root == nullptr)
        throw std::invalid_argument("Empty Tree!");

    Node<Comparable>* temp = this->root;
    while (temp->right != nullptr)
        temp = temp->right;

    return temp->val;
}

template <typename Comparable>
bool AVLTree<Comparable>::is_empty() const {
    return this->root == nullptr;
}

template<typename Comparable>
void AVLTree<Comparable>::print_tree_section(int depth, Node<Comparable> *section, std::ostream &os) const {
    if (section->right != nullptr)
        print_tree_section(depth + 1, section->right, os);

    if (depth > 0)
        os << std::string(depth * 2, ' ');
    os << section->val << "\n";

    if (section->left != nullptr)
        print_tree_section(depth + 1, section->left, os);
}

template <typename Comparable>
void AVLTree<Comparable>::print_tree(std::ostream &os) const {
    if (this->root == nullptr) {
        os << "<empty>\n";
        return;
    }
    this->print_tree_section(0, this->root, os);
}

#endif