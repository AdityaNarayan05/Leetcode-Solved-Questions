const int MAX_CHARS=26;
vector<vector<int>>dir ={{1,0},{-1,0},{0,1},{0,-1}};
class TrieNode{
public:
    string word;
    bool isWord;
    TrieNode* children[MAX_CHARS];
    
    TrieNode(string s) : isWord(false),word(s){
        memset(children,0,sizeof(children));
    }    
};

class TrieTree{
public:
    TrieNode* root;
    
    TrieTree():root(new TrieNode("")) {}
    ~TrieTree(){
        freeTree(root);
    }
    
    TrieNode* getRoot(){
        return root;
    }
    
    void addWord(string& s){
        TrieNode* node=root;
        string t;
        for(int i=0;i<s.size();i++){
            t+=s[i];
            if(node->children[s[i]-'a']==NULL){
                node->children[s[i]-'a']=new TrieNode(t);
            }
            node=node->children[s[i]-'a'];
        }
        node->isWord=true;
    }
    
    void freeTree(TrieNode* node){
        for(int i=0;i<MAX_CHARS;i++){
            if(node->children[i]!=NULL)
                freeTree(node->children[i]);
        }
        delete node;
    }
};
class Solution {
public:
    void dfs(vector<vector<char>> &board,TrieNode* root,int r,int c,vector<string>&res){
        if(r<0 or r>=board.size() or c<0 or c>=board[0].size() or board[r][c]=='*')
            return;
        
        char ch=board[r][c];
        root=root->children[ch-'a'];
        if(!root)
            return;
        if(root->isWord){
            res.push_back(root->word);
            root->isWord=false;
        }
        board[r][c]='*';
        for(int i=0;i<4;i++)
            dfs(board,root,r+dir[i][0],c+dir[i][1],res);
        
        board[r][c]=ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieTree t;
        for(int i=0;i<words.size();i++)
            t.addWord(words[i]);
        
        vector<string> res;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                dfs(board,t.getRoot(),i,j,res);
        
        return res;
    }
};