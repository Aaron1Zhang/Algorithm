class Trie {

public:
    /** Initialize your data structure here. */
    struct Node {
        char c;
        bool isEnd;
        Node* next[26] = {nullptr}; 
        Node(char m): c{m}, isEnd{false} {}
    };
    Node* head;
    Trie() {
        head = new Node('/');

    }   
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto temp = head;
        for(auto& c: word) {
            if(temp->next[c-'a'] == nullptr) {
                temp->next[c-'a'] = new Node(c);
            }
            temp = temp->next[c - 'a'];
        }
        temp->isEnd = true;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto temp = head;
        for(auto& c: word) {
            if(temp->next[c-'a'] == nullptr) {
                return false;
            }
            temp = temp->next[c-'a'];
        }
        if(temp->isEnd) {
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto temp = head;
        for(auto& c: prefix) {
            if(temp->next[c-'a'] == nullptr) {
                return false;
            }
            temp = temp->next[c-'a'];
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