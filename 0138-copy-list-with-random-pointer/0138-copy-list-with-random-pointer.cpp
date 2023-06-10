/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node* temp=head;
        
        while(temp){
            mp[temp]=new Node(temp->val);
            temp=temp->next;
        }
        
        temp=head;
        
        while(temp){
            Node* node = mp[temp];
            node->next=temp->next ? mp[temp->next] : NULL;
            node->random=temp->random ? mp[temp->random] : NULL;
            temp=temp->next;
        }
    
        return mp[head];
    }
};