import java.util.ArrayList;

class Leaf {
    public String key;
    public String value;
    public Leaf next;
    public Leaf(String key, String value) {
        this.key = key;
        this.value = value;
        this.next = null;
    }
}

class Trie {
    public char value;
    public ArrayList<Trie> values;
    public Leaf leaf;
    public Trie(char value) {
        this.value = value;
        this.values = new ArrayList<Trie>();
        for (int i = 0; i < 26; i++) {
            this.values.add(i, null);
        }
    }

    public void add(String key, String value) {
        Trie curr = this;
        for (int i = 0; i < key.length(); i++) {
            int index = (int)key.charAt(i) % 26;
            if (curr.values.get(index) == null) {
                curr.values.add(index, new Trie(key.charAt(i)));
            }
            curr = curr.values.get(index);
        }
        Leaf tmp = curr.leaf;
        curr.leaf = new Leaf(key, value);
        curr.leaf.next= tmp;
    }

    public String get(String key) {
        Trie curr = this;
        for (int i = 0; i < key.length(); i++) {
            int index = (int)key.charAt(i) % 26;
            if (curr.values.get(index) == null) {
                return null;
            }
            curr = curr.values.get(index);
        };
        Leaf tmp = curr.leaf;
        while (tmp.key != key && tmp.next != null) {
            tmp = tmp.next;
        }
        return tmp.value;
    }
}

public class Main {
    public static void main(String[] args) {
        Trie root = new Trie(' ');
        root.add("Apples", "Epic");
        root.add("Blitz", "cheese");
        System.out.println(root.get("Apples"));
        System.out.println(root.get("John"));
        System.out.println(root.get("Blitz"));
    }
}
