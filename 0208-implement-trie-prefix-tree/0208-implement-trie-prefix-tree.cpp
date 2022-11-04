class Trie {
public:
    Trie* next[26]={};
    bool isWord=false;
    
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* node=this;
        for(char w:word){
            w-='a';
            if(!node->next[w])
                node->next[w]=new Trie();
            node=node->next[w];
        }
        node->isWord=true;
    }
    
    bool search(string word) {
        Trie* node=this;
        for(char w:word){
            w-='a';
            if(!node->next[w])
                return false;
            node=node->next[w];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* node=this;
        for(char pre:prefix){
            pre-='a';
            if(!node->next[pre])
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