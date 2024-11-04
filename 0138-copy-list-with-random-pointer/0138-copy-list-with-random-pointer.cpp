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
        if(head==NULL) return NULL;

        Node* temp=head;

        while(temp){
            Node* store=new Node(temp->val);
            Node* next=temp->next;
            temp->next=store;
            temp=store;
            temp->next=next;
            temp=next;
        }

        temp=head;
        Node* temp2=head->next;

        while(temp){
            if(temp->random){
                temp2->random=temp->random->next;
            }
            temp=temp->next;
            if(temp){
                temp=temp->next;
            }
            if(temp){
                temp2=temp->next;
            }
        }

        Node* dummy=new Node(-1);
        temp=head;

        temp2=dummy;

        while(temp){
            temp2->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            temp2=temp2->next;
        }

        return dummy->next;
    }
};