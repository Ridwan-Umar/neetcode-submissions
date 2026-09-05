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
    ListNode* merge(ListNode* L1,ListNode* L2){
        if (L1==nullptr) return L2;
        if (L2==nullptr) return L1;
        if (L1->val<=L2->val){
            L1->next=merge(L1->next,L2);
            return L1;
        }
        else{
            L2->next=merge(L1,L2->next);
            return L2;
        }
    }
    ListNode* ans(int s,int e,vector<ListNode*>& lists){
        if (s>e){
            return nullptr;
        }
        if (s==e){
            return lists[s];
        }
        int mid=(e-s)/2+s;
        ListNode* l1=ans(s,mid,lists);
        ListNode* l2=ans(mid+1,e,lists);
        return merge(l1,l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if (k==0){
            return nullptr;
        }
        return ans(0,k-1,lists);
    }
};