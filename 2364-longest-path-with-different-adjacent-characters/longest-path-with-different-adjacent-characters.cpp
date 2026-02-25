class Solution {
public:
    
    int dfs(vector<vector<int>> &adj,int node,char ch,string &s,int &ans,vector<int> &vis){
        vis[node]=1;
        int curr = 1;
        vector<int> vec;

        for(auto it:adj[node]){
            if(!vis[it]){
                int stt = dfs(adj,it,s[it],s,ans,vis);
                if(s[it]!=ch){
                    vec.push_back(stt);
                }
            }
        }

        sort(vec.begin(),vec.end());
        int n = vec.size();

        if(n>0){
            ans = max(ans,1+vec[n-1]);
            curr = vec[n-1]+1;
        }

        if(n>1)ans = max(ans,curr+vec[n-2]);


        return curr;
    }

    int longestPath(vector<int>& parent, string s) {

        int n = parent.size();
        
        vector<vector<int>> adj(n);

        for(int i=1;i<parent.size();i++){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        int ans = 1;

        vector<int> vis(n,0);

        dfs(adj,0,s[0],s,ans,vis);

        return ans;
    }
};