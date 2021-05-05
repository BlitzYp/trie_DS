#include <iostream>
#include <vector>

struct trieNode {
public:
    char value;
    std::vector<trieNode*> connections;
    std::string leaf;
    trieNode(char v) {
        value = v;
        connections = std::vector<trieNode*>(26);
        for (int i = 0; i < 26; i++) {
            connections.at(i) = NULL;
        }
    }
};

class Trie {
public:
    trieNode* root = new trieNode('.');
    std::vector<std::string> keys;
    void addNode(std::string key, std::string value) {
        trieNode* curr = root;
        for (char i: key) {
            int index = i % 26;
            if (curr->connections[index] == NULL) curr->connections[index] = new trieNode(i);
            curr = curr->connections[index];
        }
        curr->leaf = value;
        keys.push_back(key);
    }

    std::string getNode(std::string key) {
        trieNode* curr = root;
        for (char i: key) {
            if (curr->connections[i % 26] == NULL) {
                perror("Invalid key");
                std::exit(1);
            };
            curr = curr->connections[i%26];
        }
        return curr->leaf;
    }

    void printKeys() {
        for (std::string key: keys) {
            std::cout << key << '\n';
        }
    }
};

int main() {
    Trie trie = Trie();
    trie.addNode("Epic cheese", "Blitz");
    trie.addNode("Epic cheese2", "John");
    std::cout << trie.getNode("Epic cheese2") << '\n';
    trie.printKeys();
    return 0;
}
