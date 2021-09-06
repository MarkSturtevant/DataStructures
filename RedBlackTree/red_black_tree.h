#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>
#include <stdexcept>


template <typename Comparable>
class RedBlackTree {
public:
    enum Color {RED, BLACK};

    struct Node {
        Comparable value;
        Node* parent;
        Node* left;
        Node* right;
        int color;

        Node() : value(), parent(nullptr), left(nullptr), right(nullptr), color(RED) {}
    };


    RedBlackTree();
    ~RedBlackTree();
    RedBlackTree(const RedBlackTree<Comparable>& other);
    RedBlackTree& operator=(const RedBlackTree<Comparable>& other);

    bool contains(const Comparable& obj) const;
    void insert(const Comparable& obj);
    void remove(const Comparable& obj);
    void make_empty();
    bool is_empty() const;

    int color(const Node* node) const;
    const Node* get_root() const;

    const Comparable& find_min() const;
    const Comparable& find_max() const;
    void print_tree(std::ostream& os = std::cout) const;
private:
    Node* root;

    void clearRecursively(Node* current);
    void copyTree(Node* me, Node* other);
    void print_tree_section(int depth, Node* section, std::ostream& os = std::cout) const;

    void recursiveAdd(Node* current, const Comparable& obj);
    void recursiveRemove(Node *node, Node* toReplace, bool onlyLeft, const Comparable &obj);

    bool getIsRightChild(Node *node, Node* parent);
    void simpleDeleteNode(Node *node);
    Node* getSibling(Node *node);
    void rotate(Node* grandparent, Node* parent, Node* child);
    void rotate(Node* grandparent, int swapType);
};

template<typename Comparable>
const typename RedBlackTree<Comparable>::Node* RedBlackTree<Comparable>::get_root() const {
    return this->root;
}

template<typename Comparable>
int RedBlackTree<Comparable>::color(const Node *node) const {
    if (node == nullptr)
        return RedBlackTree<Comparable>::BLACK;
    else return node->color;
}

template <typename Comparable>
void RedBlackTree<Comparable>::clearRecursively(Node *current) {
    if (current == nullptr)
        return;
    if (current->left != nullptr)
        this->clearRecursively(current->left);
    if (current->right != nullptr)
        this->clearRecursively(current->right);
    delete current;
}

template <typename Comparable>
void RedBlackTree<Comparable>::copyTree(Node* me, Node* other) {
    me->value = other->value;
    me->color = other->color;

    if (other->left != nullptr) {
        me->left = new Node();
        me->left->parent = me;
        this->copyTree(me->left, other->left);
    }
    else me->left = nullptr;

    if (other->right != nullptr) {
        me->right = new Node();
        me->right->parent = me;
        this->copyTree(me->right, other->right);
    }
    else me->right = nullptr;
}

template <typename Comparable>
void RedBlackTree<Comparable>::make_empty() {
    this->clearRecursively(this->root);
    this->root = nullptr;
}

template <typename Comparable>
RedBlackTree<Comparable>::~RedBlackTree<Comparable>() {
    this->make_empty();
}

template <typename Comparable>
RedBlackTree<Comparable>::RedBlackTree() : root(nullptr) {}

template <typename Comparable>
RedBlackTree<Comparable>::RedBlackTree(const RedBlackTree<Comparable> &other) :
        root(nullptr) {
    if (other.root == nullptr)
        return;
    else {
        this->root = new Node();
        this->root->parent = nullptr;
        this->copyTree(this->root, other.root);
    }
}

template <typename Comparable>
RedBlackTree<Comparable>& RedBlackTree<Comparable>::operator=(const RedBlackTree<Comparable> &other) {
    if (this == &other)
        return *this;

    this->make_empty();

    if (other.root != nullptr) {
        this->root = new Node();
        this->root->parent = nullptr;
        this->copyTree(this->root, other.root);
    }
    return *this;
}

template <typename Comparable>
bool RedBlackTree<Comparable>::contains(const Comparable &obj) const {
    Node* temp = this->root;
    while (temp != nullptr) {
        if (temp->value == obj)
            return true;
        else if (temp->value > obj)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

template <typename Comparable>
void RedBlackTree<Comparable>::recursiveAdd(Node* current, const Comparable &obj) {

    if (current->right != nullptr && current->left != nullptr && current->right->color == RED &&
            current->left->color == RED && current->color == BLACK) {
        current->color = RED;
        current->right->color = BLACK;
        current->left->color = BLACK;

        if (current->parent == nullptr)
            current->color = BLACK;

        else if (current->parent->color == RED) {
            // TODO: rotate
            Node* grandparent = current->parent->parent;
            Node* parent = current->parent;
            rotate(grandparent, parent, current);
            if (grandparent->parent == current) { // current is the new root of this subtree.
                grandparent->color = RED;
                parent->color = RED;
                current->color = BLACK;
            } else { // parent is the new root of this subtree.
                parent->color = BLACK;
                grandparent->color = RED;
                current->color = RED;
            }

        }

    }
    if (current->value == obj)
        return;
    else if (current->value < obj) {
        if (current->right == nullptr) {
            Node* toAdd = new Node();
            toAdd->color = RED;
            toAdd->parent = current;
            toAdd->right = nullptr;
            toAdd->left = nullptr;
            toAdd->value = obj;
            current->right = toAdd;
            if (current->color == RED) {
                // TODO: rotate
                Node* parent = current->parent;
                rotate(parent, current, toAdd);

                if (parent->parent == current) { // current is the new root of this subtree.
                    toAdd->color = RED;
                    parent->color = RED;
                    current->color = BLACK;
                } else { // toAdd is the new root of this subtree.
                    toAdd->color = BLACK;
                    parent->color = RED;
                    current->color = RED;
                }
            }
        }
        else {
            this->recursiveAdd(current->right, obj);
        }
    } else {
        if (current->left == nullptr) {
            Node* toAdd = new Node();
            //toAdd->color = RED;
            toAdd->parent = current;
            //toAdd->right = nullptr;
            //toAdd->left = nullptr;
            toAdd->value = obj;
            current->left = toAdd;
            if (current->color == RED) {
                // TODO: rotate
                Node* parent = current->parent;
                rotate(parent, current, toAdd);
                if (parent->parent == current) { // current is the new root of this subtree.
                    toAdd->color = RED;
                    parent->color = RED;
                    current->color = BLACK;
                } else { // toAdd is the new root of this subtree.
                    toAdd->color = BLACK;
                    parent->color = RED;
                    current->color = RED;
                }
            }
        }
        else {
            this->recursiveAdd(current->left, obj);
        }
    }
}

template <typename Comparable>
void RedBlackTree<Comparable>::insert(const Comparable &obj) {



    if (this->root == nullptr) {
        this->root = new Node();
        this->root->color = BLACK;
        //this->root->parent = nullptr;
        //this->root->right = nullptr;
        //this->root->left = nullptr;
        this->root->value = obj;
    }
    else this->recursiveAdd(this->root, obj);
}

template <typename Comparable>
void RedBlackTree<Comparable>::simpleDeleteNode(Node *node) {
    bool isRoot = node == this->root;
    bool isRight = isRoot ? true : getIsRightChild(node, node->parent);

    if (node->left != nullptr) { // left child only
        Node* output = node->left;
        if (isRoot) {
            this->root = output;
            output->parent = nullptr;
        }
        else if (isRight) {
            node->parent->right = output;
            output->parent = node->parent;
        }
        else {
            node->parent->left = output;
            output->parent = node->parent;
        }
        output->color = BLACK;

        delete node;

    } else if (node->right != nullptr) { // right child only
        Node* output = node->right;
        if (isRoot) {
            this->root = output;
            output->parent = nullptr;
        }
        else if (isRight) {
            node->parent->right = output;
            output->parent = node->parent;
        }
        else {
            node->parent->left = output;
            output->parent = node->parent;
        }
        output->color = BLACK;

        delete node;

    } else {
        if (isRoot)
            this->root = nullptr;
        else if (isRight)
            node->parent->right = nullptr;
        else
            node->parent->left = nullptr;
        delete node;
    }
}

template <typename Comparable>
typename RedBlackTree<Comparable>::Node* RedBlackTree<Comparable>::getSibling(Node *node) {
    if (node->parent == nullptr)
        return nullptr;
    int sonRight = getIsRightChild(node, node->parent);
    if (sonRight)
        return node->parent->left;
    else return node->parent->right;
}

template <typename Comparable>
bool RedBlackTree<Comparable>::getIsRightChild(Node *node, Node* parent) { // assumes parent + node exists
    if (parent != nullptr && parent->left != nullptr && parent->left->value == node->value)
        return false; // left child
    else return true; // right child / null
}

template <typename Comparable>
void RedBlackTree<Comparable>::recursiveRemove(Node *node, Node* toReplace, bool onlyLeft, const Comparable &obj) {

    //std::cout << "Currently at " << (node == nullptr ? -1 : node->value) << std::endl;
    //this->print_tree();
    //std::cout << "------------------------------------------------" << std::endl;

    if (node == nullptr)
        return;

    Node* parent = node->parent;
    Node* sibling = getSibling(node);
    bool isRight = getIsRightChild(node, parent);

    if (node->color == RED); // special case 4a; fall through
    else if (color(node->left) == RED || color(node->right) == RED) { // special case 4
        Node* nextNode;
        Node* nextNodeSibling;
        if ((! onlyLeft) && node->value <= obj) {
            nextNode = node->right;
            nextNodeSibling = node->left;
        }
        else if (onlyLeft || node->value > obj) {
            nextNode = node->left;
            nextNodeSibling = node->right;
        }

        if (nextNode == nullptr || nextNode->color == RED); // end | lucky!
        else { // unlucky!
            // TODO: Rotate
            rotate(node, nextNode, nextNodeSibling);
            nextNodeSibling->color = BLACK;
            node->color = RED;
        }

    } else {
        if (sibling == nullptr) { // 1
            parent->color = BLACK;
            node->color = RED;
        } else if (color(sibling->left) == BLACK && color(sibling->right) == BLACK) { // 1
            parent->color = BLACK;
            node->color = RED;
            sibling->color = RED;
        } else if (isRight && color(sibling->right) == RED) { // 2
            // TODO: Double Rotation
            rotate(parent, sibling, sibling->right);
            parent->color = BLACK;
            sibling->color = BLACK;
            node->color = RED;

        } else if (! isRight && color(sibling->left) == RED) { // 2
            // TODO: Double Rotation
            rotate(parent, sibling, sibling->left);
            parent->color = BLACK;
            sibling->color = BLACK;
            node->color = RED;

        } else if (isRight && color(sibling->left) == RED) { // 3
            // TODO: Double Rotation
            sibling->left->color = BLACK;
            rotate(parent, sibling, sibling->left);
            parent->color = BLACK;
            sibling->color = RED;
            node->color = RED;

        } else if (! isRight && color(sibling->right) == RED) { // 3
            // TODO: Double Rotation
            sibling->right->color = BLACK;
            rotate(parent, sibling, sibling->right);
            parent->color = BLACK;
            sibling->color = RED;
            node->color = RED;

        }
    }

    if (node->value == obj || (onlyLeft && node->left == nullptr)) { // found the node to remove

        if (onlyLeft)
            toReplace->value = node->value;
        if (node->left == nullptr || node->right == nullptr) {
            simpleDeleteNode(node);
            return;
        }
        else {
            toReplace = node;
            onlyLeft = true;
        }

    }

    if ((onlyLeft && node->value == obj) || node->value < obj)
        this->recursiveRemove(node->right, toReplace, onlyLeft, obj);
    else if (onlyLeft || node->value > obj)
        this->recursiveRemove(node->left, toReplace, onlyLeft, obj);
}

template <typename Comparable>
void RedBlackTree<Comparable>::remove(const Comparable &obj) {
    if (this->root == nullptr)
        return;
    Node* temp = new Node();
    temp->parent = nullptr;
    temp->right = this->root;
    temp->left = nullptr;
    temp->color = RED;
    this->root->parent = temp;

    this->recursiveRemove(this->root, nullptr, false, obj);

    if (this->root != nullptr) {
        this->root->color = BLACK;
        this->root->parent = nullptr;
    }

    delete temp;
}

template <typename Comparable>
void RedBlackTree<Comparable>::rotate(Node *grandparent, Node* parent, Node* child) {
    // rotates away from child for triangle structures.
    if (grandparent->right == parent && parent->right == child)
        rotate(grandparent, 0);
    else if (grandparent->left == parent && parent->left == child)
        rotate(grandparent, 1);
    else if (grandparent->right == parent && parent->left == child)
        rotate(grandparent, 2);
    else if (grandparent->left == parent && parent->right == child)
        rotate(grandparent, 3);
    else if (grandparent->left == parent && grandparent->right == child) // rotate left, triangle
        rotate(grandparent, 4);
    else if (grandparent->left == child && grandparent->right == parent) // rotate right, triangle
        rotate(grandparent, 5);
}

template <typename Comparable>
void RedBlackTree<Comparable>::rotate(Node *grandparent, int swapType) {
    bool isRoot = grandparent == this->root;
    bool isRight = isRoot ? true : getIsRightChild(grandparent, grandparent->parent);

    if (swapType == 0) { // rightFirst, rightSecond
        Node* parent = grandparent->right;
        //Node* child = parent->right;

        parent->parent = grandparent->parent;
        grandparent->parent = parent;
        if (parent->left != nullptr)
            parent->left->parent = grandparent;

        grandparent->right = parent->left;
        parent->left = grandparent;

        if (isRoot)
            this->root = parent;
        else {
            if (isRight)
                parent->parent->right = parent;
            else parent->parent->left = parent;
        }
    }
    else if (swapType == 1) { // leftFirst, leftSecond
        Node* parent = grandparent->left;
        //Node* child = parent->left;

        parent->parent = grandparent->parent;
        grandparent->parent = parent;
        if (parent->right != nullptr)
            parent->right->parent = grandparent;

        grandparent->left = parent->right;
        parent->right = grandparent;

        if (isRoot)
            this->root = parent;
        else {
            if (isRight)
                parent->parent->right = parent;
            else parent->parent->left = parent;
        }
    }
    else if (swapType == 2) { // rightFirst, leftSecond
        Node* parent = grandparent->right;
        Node* child = parent->left;

        child->parent = grandparent->parent;
        grandparent->parent = child;
        parent->parent = child;
        if (child->left != nullptr)
            child->left->parent = grandparent;
        if (child->right != nullptr)
            child->right->parent = parent;

        grandparent->right = child->left;
        parent->left = child->right;
        child->left = grandparent;
        child->right = parent;
        if (isRoot)
            this->root = child;
        else {
            if (isRight)
                child->parent->right = child;
            else child->parent->left = child;
        }
    }
    else if (swapType == 3) { // leftFirst, rightSecond
        Node* parent = grandparent->left;
        Node* child = parent->right;

        child->parent = grandparent->parent;
        grandparent->parent = child;
        parent->parent = child;
        if (child->right != nullptr)
            child->right->parent = grandparent;
        if (child->left != nullptr)
            child->left->parent = parent;

        grandparent->left = child->right;
        parent->right = child->left;
        child->right = grandparent;
        child->left = parent;

        if (isRoot)
            this->root = child;
        else {
            if (isRight)
                child->parent->right = child;
            else child->parent->left = child;
        }
    }
    else {
        Node* left = grandparent->left;
        Node* right = grandparent->right;

        if (swapType == 4) { // rotate left, triangle structure
            right->parent = grandparent->parent;
            grandparent->parent = right;
            if (right->left != nullptr)
                right->left->parent = grandparent;

            grandparent->right = right->left;
            right->left = grandparent;
            if (isRoot)
                this->root = right;
            else {
                if (isRight)
                    right->parent->right = right;
                else right->parent->left = right;
            }
        }
        else { // rotate right, triangle structure
            left->parent = grandparent->parent;
            grandparent->parent = left;
            grandparent->left = left->right;
            if (left->right != nullptr)
                left->right->parent = grandparent;

            left->right = grandparent;
            if (isRoot)
                this->root = left;
            else {
                if (isRight)
                    left->parent->right = left;
                else left->parent->left = left;
            }
        }
    }
}

template <typename Comparable>
const Comparable& RedBlackTree<Comparable>::find_min() const {
    if (this->root == nullptr)
        throw std::invalid_argument("Empty Tree!");

    Node* temp = this->root;
    while (temp->left != nullptr)
        temp = temp->left;

    return temp->value;
}

template <typename Comparable>
const Comparable& RedBlackTree<Comparable>::find_max() const {
    if (this->root == nullptr)
        throw std::invalid_argument("Empty Tree!");

    Node* temp = this->root;
    while (temp->right != nullptr)
        temp = temp->right;

    return temp->value;
}

template <typename Comparable>
bool RedBlackTree<Comparable>::is_empty() const {
    return this->root == nullptr;
}

template<typename Comparable>
void RedBlackTree<Comparable>::print_tree_section(int depth, Node *section, std::ostream &os) const {
    if (section->right != nullptr)
        print_tree_section(depth + 1, section->right, os);

    if (depth > 0)
        os << std::string(depth * 4, ' ');
    os << section->value << " (" << (section->color == BLACK ? 'B' : 'R') << ")\n";

    if (section->left != nullptr)
        print_tree_section(depth + 1, section->left, os);
}

template <typename Comparable>
void RedBlackTree<Comparable>::print_tree(std::ostream &os) const {
    if (this->root == nullptr) {
        os << "<empty>\n";
        return;
    }
    this->print_tree_section(0, this->root, os);
}

#endif  // RED_BLACK_TREE_H