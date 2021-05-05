class trie_node:
    def __init__(self, key: chr):
        self.key = key
        self.connections = [None for _ in range(26)]
        self.leaf = None

class trie:
    def __init__(self):
        self.root = trie_node('')

    def insert(self, key: str, value: str):
        curr = self.root
        for letter in key:
            index = ord(letter) % 26
            if not curr.connections[index]:
                curr.connections[index] = trie_node(letter)
            curr = curr.connections[index]
        tmp = curr.leaf
        curr.leaf = {"value": value, "next": tmp}

    def get_value(self, key: str):
        curr = self.root
        for letter in key:
            index = ord(letter) % 26
            if not curr.connections[index]: return -1
            curr = curr.connections[index]
        return curr.leaf["value"]


if __name__ == "__main__":
    t = trie()
    t.insert("123", "Blitz")
    t.insert("324", "johnathan")
    t.insert("234", "john")
    t.insert("Justing bieber", "Suck my hamburger cheese")
    print(t.get_value("Justing bieber"))