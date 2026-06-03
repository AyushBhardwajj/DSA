class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> adj(26);

        int n = s.length();

        for(int i=0;i<n;i++){
            adj[s[i]-'a'].push_back(i);
        }

        int ans = 0;

        for(int i=0;i<words.size();i++){
            int j = 0;
            int len = words[i].length();
            int last = -1;

            while(j<len){
                auto it = upper_bound(adj[words[i][j]-'a'].begin(),adj[words[i][j]-'a'].end(),last);
                if(it == adj[words[i][j]-'a'].end())break;
                int ind = it-adj[words[i][j]-'a'].begin();
                last = adj[words[i][j]-'a'][ind];
                j++;
            }

            if(j==len)ans++;
        }

        return ans;
    }
};