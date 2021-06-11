#include <iostream>
#include <vector>

struct Leaf {
    std::string key;
    std::string value;
    Leaf* next;
    Leaf(std::string key, std::string value, Leaf* next) {
        this->key = key;
        this->value = value;
        this->next = next;
    }
};

class Trie {
public:
    std::vector<Trie*> connections;
    Leaf* leaf;
    Trie() {
        connections = std::vector<Trie*>(26);
        for (int i = 0; i < 26; i++) {
            connections[i] = NULL;
        }
        leaf = NULL;
    }

    void add(std::string key, std::string value) {
        Trie* start = this;
        for (char value: key) {
            int index = (int)value % 26;
            if (start->connections[index] == NULL) {
                start->connections[index] = new Trie();
            }
            start = start->connections[index];
        }
        start->leaf = new Leaf(key, value, start->leaf);
    }

    std::string get(std::string key) {
        Trie* start = this;
        for (char value: key) {
            int index = (int)value % 26;
            if (start->connections[index] == NULL) {
                return NULL;
            }
            start = start->connections[index];
        }
        Leaf* currLeaf = start->leaf;
        while (currLeaf->key != key && currLeaf->next != NULL)  {
            currLeaf = currLeaf->next;
        }
        return currLeaf->value;
    }
};

int main(void) {
    Trie trie = Trie();
    trie.add("Apples", "5");
    trie.add("Bob", "Gay");
    std::cout << trie.get("Apples") << std::endl;
    std::cout << trie.get("Bob") << std::endl;
    std::cout << trie.get("Alice") << std::endl;
    return 0;
}
