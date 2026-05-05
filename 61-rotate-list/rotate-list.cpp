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
    // TreeNode* reverse(TreeNode* head){
    //     if(head->next == NULL)return head;

    //     TreeNode* nhead = reverse(head->next);

    //     head->next->next = head;

    //     head->next = NULL;

    //     return nhead;
    // }
    ListNode* rotateRight(ListNode* head, int k) {
        int dist = 0;
        ListNode* curr = head;

        if(head==NULL)return head;

        ListNode* tail = NULL;

        while(curr!=NULL){
            tail = curr;
            curr = curr->next;
            dist++;
        }

        k = k%dist;

        if(k==0)return head;

        int pos = dist-k;

        ListNode* nxt = NULL;
        ListNode* trav = head;

        cout<<pos<<"\n";

        while(pos>1){
            trav = trav->next;
            pos--;
        }

        nxt = trav->next;
        trav->next = NULL;

        tail->next = head;
        return nxt;




    }
};