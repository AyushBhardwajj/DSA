class Solution {
public:
    void bfs(vector<vector<int>> &adj,int node,vector<int> &vis,int ch,string &ans){
        queue<int> q;
        vis[node] = 1;
        q.push(node);
        ans[node] = (char)('a'+ch);

        while(!q.empty()){
            int ndd = q.front();
            q.pop();

            for(auto it:adj[ndd]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] =1;
                    ans[it] = (char)('a'+ch);
                }
            }
        }

    }

    string findTheString(vector<vector<int>>& lcp) {
        
        int n = lcp.size();
        string ans = "";

        for(int i=0;i<n;i++){
            ans.push_back('#');
        }

        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(lcp[i][j]>0 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
                if(lcp[i][j] > min(n-i,n-j))return "";
                if(i == j && lcp[i][j] != (n-i))return "";
            }
        }

        vector<int> vis(n,0);

        int ch = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(ch==26)return "";
                bfs(adj,i,vis,ch,ans);
                ch++;
            }
        }

        vector<vector<int>> ndp(n,vector<int>(n,0));

        ndp[n-1][n-1]=1;

        for(int i=n-2;i>=0;i--){
            if(ans[n-1] == ans[i]){
                ndp[n-1][i]=1;
                ndp[i][n-1] =1;
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(ans[i]==ans[j]){
                    ndp[i][j] = 1+ndp[i+1][j+1];
                }

            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ndp[i][j]!=lcp[i][j])return "";
            }
        }


        return ans;
    }
};