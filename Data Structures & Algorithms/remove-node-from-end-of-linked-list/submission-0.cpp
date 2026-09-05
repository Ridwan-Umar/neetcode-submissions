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
        ListNode* fast=head;
        ListNode* slow=head;
        while (n>0){
            fast=fast->next;
            n--;
        }
        if (fast==nullptr){
            ListNode* ans=head->next;
            head->next=nullptr;
            delete(head);
            return ans;
        }
        while (fast!=nullptr &&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* del=slow->next;
        slow->next=slow->next->next;
        del->next=nullptr;
        delete(del);
        return head;
    }
};
