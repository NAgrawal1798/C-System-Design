#include <iostream>
#include <string>

class TreeNode {
public:
    std::string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const std::string& val) : value(val), left(nullptr), right(nullptr) {}
};

class LexicographicalBinaryTree {
private:
    TreeNode* root;
    int count; // Number of nodes in the binary tree.

    // Insert a string into the binary tree.
    TreeNode* insertString(TreeNode* node, const std::string& word) {
        if (node == nullptr) {
            count++;
            return new TreeNode(word);
        }

        if (word < node->value) {
            node->left = insertString(node->left, word);
        } else if (word > node->value) {
            node->right = insertString(node->right, word);
        }

        return node;
    }

    // In-order traversal to find the k'th lexicographically smallest string.
    void findKthSmallest(TreeNode* node, int& k, std::string& result) {
        if (node == nullptr || k <= 0) {
            return;
        }

        findKthSmallest(node->left, k, result);

        k--;
        if (k == 0) {
            result = node->value;
            return;
        }

        findKthSmallest(node->right, k, result);
    }

public:
    LexicographicalBinaryTree() : root(nullptr), count(0) {}

    // Insert a string into the binary tree.
    void insert(const std::string& word) {
        root = insertString(root, word);
    }

    // Find the k'th lexicographically smallest string.
    std::string findKthLexicographicallySmallest(int k) {
        std::string result;
        findKthSmallest(root, k, result);
        return result;
    }
};

int main() {
    LexicographicalBinaryTree tree;

    // Simulate inserting strings into the binary tree.
    tree.insert("apple");
    tree.insert("banana");
    tree.insert("cherry");

    int k = 2;
    std::string result = tree.findKthLexicographicallySmallest(k);
    if (!result.empty()) {
        std::cout << "The " << k << "'th lexicographically smallest string is: " << result << std::endl;
    } else {
        std::cout << "No string found for k = " << k << std::endl;
    }

    return 0;
}
