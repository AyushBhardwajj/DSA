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
    void solve(Node* head){
        Node* temp = head;

        while(temp!=NULL){
            if(temp->child){
                Node* ntemp = temp->child;

                while(ntemp->next){
                    ntemp = ntemp->next;
                }

                if(temp->next){
                    ntemp->next = temp->next;
                    temp->next->prev = ntemp;
                    temp->next = temp->child;
                    temp->child->prev = temp;
                    temp->child = NULL;
                }
                else{
                    temp->next = temp->child;
                    temp->child->prev = temp;
                    temp->child = NULL;
                }
            }

            temp = temp->next;
        }
    }
    Node* flatten(Node* head) {
        solve(head);

        return head;
    }
};