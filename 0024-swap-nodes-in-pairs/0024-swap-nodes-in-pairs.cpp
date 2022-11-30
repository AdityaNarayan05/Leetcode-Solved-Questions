/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next)
            return head;
        
        ListNode* prevPtr=NULL;
        ListNode* currPtr=head;
        ListNode* nextPtr;
        
        int cnt=0;
        while(currPtr and cnt<2){
            nextPtr=currPtr->next;
            currPtr->next=prevPtr;
            
            prevPtr=currPtr;
            currPtr=nextPtr;
            cnt++;
        }
        if(nextPtr)
            head->next=swapPairs(nextPtr);
        
        return prevPtr;
    }
};