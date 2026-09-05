/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==nullptr) return nullptr;
        unordered_map<Node*,Node*>mp;
        Node* curr=head->next;
        Node* newnode=new Node(head->val);
        mp[head]=newnode;
        Node*prev=newnode;
        while (curr!=nullptr){
            Node* newnode1=new Node(curr->val);
            mp[curr]=newnode1;
            prev->next=newnode1;
            prev=newnode1;
            curr=curr->next;
        }
        curr=head;
        Node*head1=newnode;
        while (curr!=nullptr){
            if (curr->random!=nullptr){
                newnode->random=mp[curr->random];
            }
            else{
                newnode->random=nullptr;
            }
            curr=curr->next;
            newnode=newnode->next;
        }
        return head1;
    }
};
