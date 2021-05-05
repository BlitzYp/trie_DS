#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct trieNode {
    char value;
    struct trieNode** connections;
} trieNode;

trieNode* createNode(char value) {
    trieNode* res = (trieNode*)malloc(sizeof(trieNode));
    res->value = value;
    res->connections = (trieNode**)malloc(sizeof(trieNode*) * 26);
    for (int i = 0; i < 26; i++) {
        res->connections[i] = NULL;
    }
    return res;
}

void insert(trieNode* root, char* value) {
    trieNode* curr = root;
    for (int i = 0; i < strlen(value); i++) {
        int key = value[i] % 26;
        if (curr->connections[key] == NULL) {
            curr->connections[key] = createNode(value[i]);
        }
        curr = curr->connections[key];
    }
}

bool get(trieNode* root, char* value) {
    trieNode* curr = root;
    for (int i = 0; i < strlen(value); i++) {
        int key = value[i] % 26;
        if (curr->connections[key] == NULL) return false;
        curr = curr->connections[key];
    }
    return true;
}

int main(void) {
    trieNode* root = createNode('s');
    insert(root, "Blitz");
    insert(root, "John");
    insert(root, "Bob");
    printf("%d\n", get(root, "Johnathan"));
    printf("%d\n", get(root, "Bob"));
    return 0;
}