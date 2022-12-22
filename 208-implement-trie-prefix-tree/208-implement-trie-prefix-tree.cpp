class Trie {
    class Node {
    public:
        char c;
        vector<Node*> next;
        bool end;
        Node(char c) {
            this->c = c;
            this->end = false;
            next = vector<Node*> (26, nullptr);
        }
    };
    Node* start;
public:
    Trie() {
        start = new Node('S');
    }
    
    void insert(string word) {
        int n = word.size();
        auto node = start;
        for (int i = 0; i < n; i++) {
            char ch = word[i];
            if (!node->next[ch-'a'])
                node->next[ch-'a'] = new Node(ch);
            node = node->next[ch-'a'];
        }
        node->end = true;
    }
    
    bool search(string word) {
        int n = word.size();
        auto node = start;
        for (int i = 0; i < n; i++) {
            char ch = word[i];
            if (node->next[ch-'a'])
                node = node->next[ch-'a'];
            else 
                return false;
        }
        if (node->end)
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        auto node = start;
        for (int i = 0; i < n; i++) {
            char ch = prefix[i];
            if (node->next[ch-'a'])
                node = node->next[ch-'a'];
            else 
                return false;
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