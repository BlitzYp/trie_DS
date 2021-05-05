#include <iostream>
#include <vector>

struct leafNode {
    std::string key;
    std::string value;
    struct leafNode* next;
};

struct trie {
    char value;
    std::vector<trie*> connections;
    leafNode* leaf;
};

void insert(std::string key, std::string value, trie* head) {
    trie* curr = head;
    for (auto i: key) {
        int index = i % 26;
        if (curr->connections[index] == NULL) {
            trie* newTrie = (trie*)malloc(sizeof(trie));
            newTrie->value = i;
            newTrie->connections = std::vector<trie*>(26);
            newTrie->leaf = NULL;
            curr->connections[index] = newTrie;
        }
        curr = curr->connections[index];
    }
    leafNode* newNode = (leafNode*)malloc(sizeof(leafNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = curr->leaf;
    curr->leaf = newNode;
}

std::string get(std::string key, trie* head) {
    trie* curr = head;
    for (auto i: key) {
        int index = i % 26;
        if (curr->connections[index] == NULL) {
            perror("This key doesn't exist");
            exit(0);
        }
        curr = curr->connections[index];
    }
    leafNode* res = curr->leaf;
    while (res->key != key && res->next != NULL) res = res->next;
    return res->value;
}

int main() {
    trie head = {NULL, std::vector<trie*>(26), NULL};
    insert("123", "Blitz", &head);
    insert("1233", "John", &head);
    insert("pizza", "SuperDickHuge", &head);
    std::cout << get("123", &head) << '\n';
    std::cout << get("pizza", &head) << '\n';
    return 0;
}