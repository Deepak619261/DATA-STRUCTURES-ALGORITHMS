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
        unordered_map<Node*,Node*>mpp;

        // Node* ans=new Node(head->val);
        Node* temp=head;

        Node* dummy=new Node(-1);
        Node* ptr=dummy;

        while(temp){
             Node* curr=new Node(temp->val);
             ptr->next=curr;
             ptr=curr;
             mpp[temp]=curr;
             temp=temp->next;
        }

        temp=head;
        ptr=dummy->next;

        while(temp){
            ptr->random=mpp[temp->random];
            ptr=ptr->next;
            temp=temp->next;
        }

        return dummy->next;
    }
};