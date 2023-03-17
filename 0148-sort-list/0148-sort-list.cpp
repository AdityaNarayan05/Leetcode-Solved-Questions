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
    ListNode* merge(ListNode* a,ListNode* b){
        ListNode* result = NULL;
        if(a == NULL)
            return(b);
        else if(b == NULL)
            return(a);
        if(a->val <= b->val){ 
            result = a; 
            result->next = merge(a->next, b); 
        } 
        else{
            result = b; 
            result->next = merge(a, b->next); 
        } 
        return(result); 
    }
    void MergeSort(ListNode** headRef){
        ListNode* head = *headRef;
        ListNode* a;
        ListNode* b;
        if((head == NULL) || (head->next == NULL))
            return;
        FrontBackSplit(head, &a, &b);
    
        MergeSort(&a);
        MergeSort(&b);
        
        *headRef = SortedMerge(a, b);
    }
    ListNode* SortedMerge(ListNode* a,ListNode* b){
        ListNode* result = NULL;
        if(a == NULL)
            return (b);
        else if(b == NULL)
            return (a);
        if(a->val <= b->val) {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else{
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        return (result);
    }
    void FrontBackSplit(ListNode* source,ListNode** frontRef, ListNode** backRef){
        ListNode* fast;
        ListNode* slow;
        slow = source;
        fast = source->next;
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
    ListNode* sortList(ListNode* head) {
        MergeSort(&head);
        return head;
    }
};