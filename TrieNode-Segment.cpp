#include <iostream>
#include <string>
#include <unordered_map>

// Trie Node for segments
struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isBlocked;
    TrieNode() : isBlocked(false) {}
};

class SegmentTrie {
public:
    SegmentTrie() {
        root = new TrieNode();
    }

    void insert(const std::string& segment) {
        TrieNode* current = root;
        for (char c : segment) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isBlocked = true;
    }

    bool search(const std::string& segment) {
        TrieNode* current = root;
        for (char c : segment) {
            if (current->children.find(c) == current->children.end()) {
                return false; // Segment not found
            }
            current = current->children[c];
        }
        return current->isBlocked;
    }

private:
    TrieNode* root;
};

int main() {
    SegmentTrie blockedSegments;

    // Insert blocked segments
    blockedSegments.insert("example");
    blockedSegments.insert("blocked");
    blockedSegments.insert("malicious");

    // URL to check
    std::string urlToCheck;

    // Input the URL to check
    std::cout << "Enter the URL to check: ";
    std::cin >> urlToCheck;

    // Split the URL into segments and check each segment
    std::string currentSegment = "";
    for (char c : urlToCheck) {
        currentSegment += c;
        if (blockedSegments.search(currentSegment)) {
            std::cout << "The URL is blocked." << std::endl;
            return 0;
        }
    }

    std::cout << "The URL is not blocked." << std::endl;

    return 0;
}
