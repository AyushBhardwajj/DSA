class TrieNode{
public:
    TrieNode* vec[26];
    int cnt;

    TrieNode(){
        for(int i=0;i<26;i++){
            vec[i] = NULL;
        }
        cnt = 0;
    }
};

void make(TrieNode* root,string str){
    TrieNode* trav = root;
    for(int i=0;i<str.length();i++){
        if(trav->vec[str[i]-'a']==NULL){
            trav->vec[str[i]-'a'] = new TrieNode();
        }

        trav = trav->vec[str[i]-'a'];
        trav->cnt+=1;
    }
}

int total(TrieNode* root,string str){
    int ans = 0;
    int maxt = 1e9;
    TrieNode* trav = root;

    for(int i=0;i<str.length();i++){
        maxt = min(trav->vec[str[i]-'a']->cnt,maxt);
        ans += maxt;
        trav = trav->vec[str[i]-'a'];
    }

    return ans;
}

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(int i=0;i<words.size();i++){
            make(root,words[i]);
        }

        int n = words.size();

        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            ans[i] = total(root,words[i]);
        }

        return ans;
    }
};