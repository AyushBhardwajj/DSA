class TrieNode{
public:
    vector<TrieNode*> vec;
    bool end;

    TrieNode(){
        vec.push_back(NULL);
        vec.push_back(NULL);
        end = false;
    }
};

int find(TrieNode* root,int num){
    TrieNode* trav = root;
    vector<int> arr(32,0);

    int dup = num;
    int ind = 0;

    while(dup>0){
        arr[ind] = dup&1;
        dup = dup/2;
        ind++;
    }

    ind = 31;

    int ans = 0;

    while(ind>=0){
        if(trav == NULL){
            ans += pow(2,ind);
            ind--;
            continue;
        }
        if(arr[ind]==1){
            if(trav->vec[0]){
                trav = trav->vec[0];
                ans += pow(2,ind);
            }
            else trav = trav->vec[1];
        }
        else{
            if(trav->vec[1]){
                trav = trav->vec[1];
                ans += pow(2,ind);
            }
            else trav = trav->vec[0];
        }
        ind--;
    }

    return ans;
}

void make(TrieNode* root,int num){
    TrieNode* trav = root;
    vector<int> arr(32,0);

    int dup = num;
    int ind = 0;

    while(dup>0){
        arr[ind] = dup&1;
        dup = dup/2;
        ind++;
    }

    for(int i=31;i>=0;i--){

        if(trav->vec[arr[i]]==NULL){
            trav->vec[arr[i]] = new TrieNode();
        }

        trav = trav->vec[arr[i]];
    }
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();

        for(int i=0;i<nums.size();i++){
            make(root,nums[i]);
        }

        int ans = 0;

        for(int i=0;i<nums.size();i++){
            ans = max(ans,find(root,nums[i]));
        }

        return ans;
    }
};