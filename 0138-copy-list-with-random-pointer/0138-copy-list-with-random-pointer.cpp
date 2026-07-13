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
        Node* temp=head;

        while(temp){
            Node* newhead=new Node(temp->val);
            newhead->next=temp->next;
          
            temp->next=newhead;
            temp=temp->next->next;
        }

        temp=head;

        while(temp){
            Node* newhead=temp->next;
            newhead->random=temp->random?temp->random->next:temp->random;
            temp=temp->next->next;
        }

        Node* dummy =new Node(-1);
        Node* ans=dummy;

        temp=head;

        while(temp){
            dummy->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            dummy =dummy->next;
        }

        return ans->next;
        
    }
};