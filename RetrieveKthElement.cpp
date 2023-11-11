#include <iostream>
#include <vector>
#include <string>

class TrieNode {
public:
    TrieNode* children[26];  // Assuming lowercase English letters only
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class LexicographicalTrie {
private:
    TrieNode* root;
    std::vector<std::string> strings;

    // Insert a string into the trie in lexicographically sorted order.
    void insertString(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Perform an in-order traversal of the trie to collect lexicographically sorted strings.
    void traverseTrie(TrieNode* node, std::string current) {
        if (node == nullptr) {
            return;
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                current.push_back('a' + i);
                if (node->children[i]->isEndOfWord) {
                    strings.push_back(current);
                }
                traverseTrie(node->children[i], current);
                current.pop_back();
            }
        }
    }

public:
    LexicographicalTrie() {
        root = new TrieNode();
    }

    // Insert a string into the trie.
    void insert(const std::string& word) {
        insertString(word);
    }

    // Find the k'th lexicographically smallest string.
    std::string findKthLexicographicallySmallest(int k) {
        strings.clear();
        traverseTrie(root, "");

        if (k > 0 && k <= strings.size()) {
            return strings[k - 1];
        } else {
            return "";
        }
    }
};

int main() {
    LexicographicalTrie trie;
    trie.insert("bbbbbb");
    trie.insert("banana");
    trie.insert("cherry");

    int k = 1;
    std::string result = trie.findKthLexicographicallySmallest(k);
    if (!result.empty()) {
        std::cout << "The " << k << "'th lexicographically smallest string is: " << result << std::endl;
    } else {
        std::cout << "No string found for k = " << k << std::endl;
    }

    return 0;
}
