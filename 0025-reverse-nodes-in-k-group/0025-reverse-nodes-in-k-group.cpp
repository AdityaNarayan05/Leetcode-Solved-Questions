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
    int length(ListNode* &head){
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        return n;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head and !head->next)
            return head;
        
        int len=length(head);
        
        ListNode* d=new ListNode(0);
        d->next=head;
        
        ListNode* pptr=d;
        ListNode* cptr,*nptr;
        
        while(len>=k){
            cptr=pptr->next;
            nptr=cptr->next;
            
            for(int i=1;i<k;i++){
                cptr->next=nptr->next;
                nptr->next=pptr->next;
                
                pptr->next=nptr;
                nptr=cptr->next;
            }
            pptr=cptr;
            len-=k;
        }
        return d->next;
    }
};