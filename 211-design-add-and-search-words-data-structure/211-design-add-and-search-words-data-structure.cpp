class WordDictionary {
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
    WordDictionary() {
        start = new Node('S');
    }
    
    void addWord(string word) {
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
        return search(start, word, 0, word.size());
    }
    
    bool search(Node* node, string word, int i, int n) {
        if (!node)
            return false;
        for (; i < n; i++) {
            char ch = word[i];
            if (ch == '.') {
                for (int j = 0; j < 26; j++) 
                    if (search(node->next[j], word, i+1, n))
                        return true;
                return false;
                break;
            }
            else {
                if (node->next[ch-'a'])
                    node = node->next[ch-'a'];
                else 
                    return false;
            }
        }
        return node->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */