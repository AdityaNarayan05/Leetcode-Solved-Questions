/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        unordered_set<ListNode*> st;
        while(h1){
            st.insert(h1);
            h1=h1->next;
        }
        while(h2){
            if(st.find(h2)!=st.end())
                return h2;
            h2=h2->next;
        }
        return NULL;
    }
};