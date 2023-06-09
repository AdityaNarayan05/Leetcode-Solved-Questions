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
    ListNode* reverse(ListNode* head){
        ListNode* pptr=NULL,*nptr=NULL;
        while(head){
            nptr=head->next;
            head->next=pptr;
            
            pptr=head;
            head=nptr;
        }
        return pptr;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return head;
        
        ListNode* slow=head,*fast=head;
        
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next=reverse(slow->next);
        slow=slow->next;
        ListNode* d=head;
        
        while(slow){
            if(d->val!=slow->val)
                return false;
            
            d=d->next;
            slow=slow->next;
        }
        return true;
    }
};