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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummy=new ListNode();
        ListNode* curr=dummy;
        while (l1!=nullptr || l2!=nullptr || carry!=0){
            int l1val,l2val;
            if (l1==nullptr){
                l1val=0;
            }
            else{
                l1val=l1->val;
            }
            if (l2==nullptr){
                l2val=0;
            }
            else{
                l2val=l2->val;
            }
            int ans=l1val+l2val+carry;
            carry=ans/10;
            ans=ans%10;
            ListNode* newnode=new ListNode(ans);
            curr->next=newnode;
            curr=newnode;
            if (l1!=nullptr) l1=l1->next;
            if (l2!=nullptr) l2=l2->next;
        }
        ListNode* head=dummy->next;
        dummy->next=nullptr;
        delete(dummy);
        return head;

    }
};
