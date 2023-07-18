class LRUCache {
public:
    class Node{
        public: 
        int key,val;
        Node* next,*prev;
        
        Node(int k,int v){
            key=k;
            val=v;
        }
    };
    
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    
    int cap;
    unordered_map<int, Node*> mp;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(Node* newNode){
        Node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    
    void deleteNode(Node* delNode){
        Node* delprev=delNode->prev;
        Node* delnext=delNode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            int res=node->val;
            mp.erase(key);
            
            deleteNode(node);
            addNode(node);
            
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* root=mp[key];
            mp.erase(key);
            deleteNode(root);
        }
        
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */