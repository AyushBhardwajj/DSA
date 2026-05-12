/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void solve(Node* &head){
        if(head == NULL)return ;

        Node* temp = head;
        Node* prev = NULL;

        while(temp!=NULL){
            if(temp->child){
                Node* ntemp = temp->child;
                while(ntemp->next!=NULL){
                    ntemp = ntemp->next;
                }

                if(temp->next){
                    ntemp->next = temp->next;
                    temp->next->prev = ntemp;
                }

                temp->next = temp->child;
                temp->next->prev = temp;
                temp->child = NULL;
            }

            temp = temp->next;
        }
    }
    Node* flatten(Node* head) {

        solve(head);

        return head;

    }
};