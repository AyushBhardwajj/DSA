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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if((head == NULL) || (head->next == NULL) || (head->next->next == NULL))return {-1,-1};

        ListNode* prev = head;
        
        ListNode* temp = head->next;

        vector<int> ans;
        int ind = 1;

        while(temp->next!=NULL){
            int p = prev->val;
            int c = temp->val;
            int n = temp->next->val;

            if(c>p && c>n)ans.push_back(ind);
            else if(c<p && c<n)ans.push_back(ind);

            prev = temp;
            temp = temp->next;
            ind++;
        }

        int siz = ans.size();

        if(siz<2)return {-1,-1};

        int mint = 1e9;

        for(int i=1;i<siz;i++){
            mint = min(mint,ans[i]-ans[i-1]);
        }

        int maxt = ans[siz-1]-ans[0];

        return {mint,maxt};
    }
};