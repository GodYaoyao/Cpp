#include <iostream>

template<typename Key, typename Value>
class BST {
private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;
        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            left = right = NULL;
        }
    };
    Node *root;
    int count;

public:
    BST() {
        root = NULL;
        count = 0;
    }
    ~BST() {

    }
    int size() { return count; }
    int isEmpty() { return count == 0; }

    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }
    void insert2(Key key, Value value) {
        if (root == NULL) {
            root = new Node(key, value);
            count++;
        } else {
            Node *cur = root;
            while (cur != NULL) {
                if (cur->key > key) {
                    if (cur->left == NULL) {
                        cur->left = new Node(key, value);
                        count++;
                        break;
                    } else
                        cur = cur->left;
                } else if (cur->key < key) {
                    if (cur->right == NULL) {
                        cur->right = new Node(key, value);
                        count++;
                        break;
                    } else
                        cur = cur->right;
                } else {
                    cur->value = value;
                    break;
                }
            }
        }
    }

    bool contain(Key key) {
        return contain(root, key);
    }
    bool contain2(Key key) {
        Node *cur = root;
        while (cur != NULL) {
            if (cur->key == key)
                return true;
            else if (cur->key > key)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return false;
    }

private:
    Node *insert(Node *node, Key key, Value value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }
        if (key == node->key)
            node->value = value;
        else if (key < node->key)
            node->left = insert(node->left, key, value);
        else
            node->right = insert(node->right, key, value);
        return node;
    }

    bool contain(Node *node, Key key) {
        if (node == NULL)
            return false;
        if (node->key == key)
            return true;
        else if (node->key > key)
            return contain(node->left, key);
        else
            return contain(node->right, key);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}