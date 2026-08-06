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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }

        k%=n;
        if (k == 0)
            return head;

        ListNode* temp1=head;
        for(int i=0;i<n-k-1;i++){
            temp1=temp1->next;
        }
        ListNode* temp2=temp1->next;
        temp1->next=NULL;

        ListNode *temp3=temp2;
        while(temp2->next){
            temp2=temp2->next;
        }
        temp2->next=head;
        return temp3;
    }
};