class Trie;

class Node {
    char data;
    unordered_map<char, Node*> childrens;
    bool isTerminal;

public:
    Node(char data) {
        data = data;
        isTerminal = false;
    }

    friend class Trie;
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node *temp = root;
        for(char ch: word) {
            if(temp -> childrens.count(ch) == 0) {
                Node *newNode = new Node(ch);
                temp -> childrens[ch] = newNode;
            }
            temp = temp -> childrens[ch];
        }
        temp -> isTerminal = true;
    }
    
    bool search(string word) {
        Node *temp = root;
        for(char ch: word) {
            if(temp -> childrens.count(ch) == 0) {
                return false;
            }
            temp = temp -> childrens[ch];
        }
        if(temp -> isTerminal) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        Node *temp = root;
        for(char ch: prefix) {
            if(temp -> childrens.count(ch) != 0) {
                temp = temp -> childrens[ch];
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */