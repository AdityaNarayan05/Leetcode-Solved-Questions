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
        if (a == NULL) 
            return(b); 
        else if (b == NULL) 
            return(a); 
        
        if (a->val <= b->val){ 
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
  
        /* Base case -- length 0 or 1 */
        if((head == NULL) || (head->next == NULL)) {
            return;
        }
  
        /* Split head into 'a' and 'b' sublists */
        FrontBackSplit(head, &a, &b);
  
        /* Recursively sort the sublists */
        MergeSort(&a);
        MergeSort(&b);
  
        /* answer = merge the two sorted lists together */
        *headRef = SortedMerge(a, b);
    }
  
    /* See https:// www.geeksforgeeks.org/?p=3622 for details of this 
    function */
    ListNode* SortedMerge(ListNode* a,ListNode* b){       
        ListNode* result = NULL;
  
        /* Base cases */
        if(a == NULL)
            return (b);
        else if(b == NULL)
            return (a);
  
        /* Pick either a or b, and recur */
        if(a->val <= b->val) {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else {
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
  
        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != NULL){
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
    }
  
        /* 'slow' is before the midpoint in the list, so split it in two at that point. */
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* curr=NULL;
        for(int i=0;i<lists.size();i++){
            curr=merge(curr,lists[i]);
        }
        MergeSort(&curr);
        return curr;        
    }
};