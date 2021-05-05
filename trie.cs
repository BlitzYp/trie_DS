using System;

class LeafNode {
    public string key;
    public string value;
    public LeafNode next;
    public LeafNode(string key, string value) {
        this.key = key;
        this.value = value;
        next = null;
    }
}

class TrieNode {
    public TrieNode[] connections;
    public char value;
    public LeafNode leaf;
    public TrieNode(char value) {
        connections = new TrieNode[26];
        this.value = value;
        leaf = null;
    } 

    public void insert(string key, string value) {
        TrieNode curr = this;
        for (int i = 0; i < key.Length; i++) {
            int index = key[i] % 26;
            if (curr.connections[index] == null) {
                curr.connections[index] = new TrieNode(key[i]);
            }
            curr = curr.connections[index];
        }

        LeafNode NewNode = new LeafNode(key, value);
        NewNode.next = curr.leaf;
        curr.leaf = NewNode;
    }

    public string get(string key) {
        TrieNode curr = this;
        for (int i = 0; i < key.Length; i++) {
            int index = key[i] % 26;
            if (curr.connections[index] == null) return null;
            curr = curr.connections[index];
        }

        LeafNode res = curr.leaf;
        while (res.key != key && res.next != null) res = res.next;
        return res.value;
    }
}

class trie {
    static void Main(string[] args) {
        TrieNode root = new TrieNode();
        root.insert("Peter parker", "Pizza time");
        root.insert("Big chungus", "Synth");
        Console.WriteLine(root.get("Peter parker"));
        Console.WriteLine(root.get("Big Chungus") == null);
    }
}