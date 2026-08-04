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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        ListNode *temp=head;
        while(temp){
            sz++;
            temp=temp->next;
        }
        int x=sz-n;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        int i=0;
        ListNode* prev=dummy;
        ListNode* curr=head;
        while(curr){
            if(i==x){
                prev->next=curr->next;
            }
            else{
                prev=curr;
            }
            curr=curr->next;
            i++;
        }
        return dummy->next;
    }
};