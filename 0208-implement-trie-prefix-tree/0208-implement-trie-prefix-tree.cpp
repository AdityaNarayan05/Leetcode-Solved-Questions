class Trie {
public:
    map<char,Trie*> next={};
    bool isWord=false;
    
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* node=this;
        for(char w:word){
            if(!node->next.count(w))
                node->next[w]=new Trie();
            node=node->next[w];
        }
        node->isWord=true;
    }
    
    bool search(string word) {
        Trie* node=this;
        for(char w:word){
            if(!node->next.count(w))
                return false;
            node=node->next[w];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* node=this;
        for(char pre:prefix){
            if(!node->next.count(pre))
                return false;
            node=node->next[pre];
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