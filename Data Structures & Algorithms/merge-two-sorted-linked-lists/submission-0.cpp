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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1=list1;
        ListNode* l2=list2;
        ListNode* l3=nullptr;
        ListNode* temp=nullptr;
        while (l1!=nullptr && l2!=nullptr){
            if (l1->val<l2->val){
                if (l3==nullptr){
                    l3=l1;
                    temp=l1;
                }
                else{
                    temp->next=l1;
                    temp=temp->next;
                }
                l1=l1->next;
            }
            else{
                if (l3==nullptr){
                    l3=l2;
                    temp=l2;
                }
                else{
                    temp->next=l2;
                    temp=temp->next;
                }
                l2=l2->next;
            }
        }
        while (l1!=nullptr){
            if (l3==nullptr){
                l3=l1;
                temp=l1;
            }
            else{
                temp->next=l1;
                temp=temp->next;
            }
            l1=l1->next;
        }
        while (l2!=nullptr){
            if (l3==nullptr){
                l3=l2;
                temp=l2;
            }
            else{
                temp->next=l2;
                temp=temp->next;
            }
            l2=l2->next;
        }
        return l3;
    }
};
