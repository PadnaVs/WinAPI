#include <iostream>
#include <string>
// Определяем структуру узла дерева
struct Node {
    int data;  // Значение узла
    std::shared_ptr<Node> left;  // Левый потомок
    std::shared_ptr<Node> right;  // Правый потомок

    // Конструктор по умолчанию
    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    // Конструктор с параметрами
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    std::shared_ptr<Node> root;  // Корень дерева

    // Рекурсивная функция для вставки узла в дерево
    std::shared_ptr<Node> insertNode(int val, std::shared_ptr<Node> node) {
        // Если дерево пустое, создаем новый узел и делаем его корнем
        if (node == nullptr) {
            return std::shared_ptr<Node>(std::make_shared<Node>(val));
        }

        // Ищем место для вставки узла
        if (val < node->data) {
            node->left = insertNode(val, node->left);
        }
        else if (val > node->data) {
            node->right = insertNode(val, node->right);
        }

        return node;
    }

    // Рекурсивная функция для поиска узла в дереве
    std::shared_ptr<Node> findNode(int val, std::shared_ptr<Node> node) {
        // Если узел пустой или его значение равно искомому значению, возвращаем его
        if (node == nullptr || node->data == val) {
            return node;
        }

        // Если искомое значение меньше значения узла, ищем в левом поддереве
        if (val < node->data) {
            return findNode(val, node->left);
        }

        // Если искомое значение больше значения узла, ищем в правом поддереве
        return findNode(val, node->right);
    }

    void printTree(std::shared_ptr<Node> node, int indent = 0) {
        if (node != nullptr) {
            printTree(node->right, indent + 4);
            std::cout << std::string(indent, ' ') << node->data << std::endl;
            printTree(node->left, indent + 4);
        }
    }
public:
    void insert(int val) {
        root = insertNode(val, root);
    }

    void print() {
        printTree(root);
    }

    std::shared_ptr<Node> getRoot() {
        return root;
    };
};

void preOrder(BinaryTree* tree, std::shared_ptr<Node> node) {
    if (tree == nullptr || node == nullptr) return;
    std::cout << node->data << '\n';
    
    preOrder(tree,node->left);
    preOrder(tree,node->right);
};

void inOrder(BinaryTree* tree, std::shared_ptr<Node> node) {
    if (tree == nullptr || node == nullptr) return;
    
    inOrder(tree, node->left);
    std::cout << node->data << '\n';
    inOrder(tree, node->right);
};

void postOrder(BinaryTree* tree, std::shared_ptr<Node> node) {
    if (tree == nullptr || node == nullptr) return;

    postOrder(tree, node->left);
    postOrder(tree, node->right);
    std::cout << node->data << '\n';
};

int main() {
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    tree.insert(80);
    tree.insert(85);
    tree.insert(10);
    tree.insert(25);
    tree.insert(35);
    tree.insert(90);
    tree.insert(100);
    tree.insert(75);
    tree.print();

    std::cout  << "\nPre Order****************\n" << '\n';

    preOrder(&tree, tree.getRoot());

    std::cout << "\nIn Order****************\n" << '\n';

    inOrder(&tree, tree.getRoot());

    std::cout << "\nPost Order****************\n" << '\n';

    postOrder(&tree, tree.getRoot());
    return 0;
};