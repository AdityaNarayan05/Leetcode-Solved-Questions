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
        while(h1){
            ListNode* temp=h2;
            while(temp){
                if(temp==h1)
                    return temp;
                temp=temp->next;
            }
            h1=h1->next;
        }
        return NULL;
    }
};