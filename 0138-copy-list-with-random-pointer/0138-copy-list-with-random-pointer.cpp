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
        //  
        map<Node* ,Node*>mpp;

        Node* temp=head;

        while(temp){
            Node* store= new Node(temp->val);
            mpp[temp]=store;
            temp=temp->next;
        }

        temp=head;

        while(temp){
             Node* store=mpp[temp];

             store->next=mpp[temp->next];

             store->random=mpp[temp->random];

             temp=temp->next;
        }

        return mpp[head];
    }
};