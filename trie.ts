interface trieNode {
    value: string;
    connections: trieNode[];
    leaf?: string;
}

function insert(key: string, value: string, head: trieNode) {
    let curr: trieNode = head;
    for (let i = 0; i < key.length; i++) {
        const index = key.charCodeAt(i) % 26;
        if (curr.connections[index] === undefined) curr.connections[index] = {value: key[i], connections: [], leaf: null};
        curr = curr.connections[index];
    }
    curr.leaf = value;
}

function get(key: string, head: trieNode): string | void {
    let curr = head;
    for (let i = 0; i < key.length; i++) {
        const index = key.charCodeAt(i) % 26;
        if (curr.connections[index] === undefined) return;
        curr = curr.connections[index];
    }
    return curr.leaf;
}

const head: trieNode = {value: '', connections: [], leaf: null};
insert("Pizza", "Blitz", head);
insert("123", "John", head);
console.log(get("123", head), get("Pizza", head));