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
    int length(ListNode* head){
        ListNode* temp=head;
        int l=0;
        while(temp){
            temp=temp->next;
            l++;
        }
        return l;
    }
    ListNode* middleNode(ListNode* head) {
        int m=length(head)/2;
        while(m>0){
            head=head->next;
            m--;
        }
        return head;
    }
};