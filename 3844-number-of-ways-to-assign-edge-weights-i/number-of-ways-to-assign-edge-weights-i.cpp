class Solution {
public:
    long long modpow(long long base,long long pow,long long mod){
        long long ans = 1;
        base = base%mod;

        while(pow){
            if(pow&1){
                ans  = (ans*base)%mod;
            }

            base = (base*base)%mod;

            pow = pow>>1;
        }

        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(1e5+1);

        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(1e5+1,0);

        int cnt = 0;

        queue<int> q;
        q.push(1);
        vis[1] = 1;

        long long mod = 1e9+7;

        while(!q.empty()){
            int n = q.size();

            for(int i=0;i<n;i++){
                int node = q.front();
                q.pop();

                for(auto it:adj[node]){
                    if(!vis[it])q.push(it);
                    vis[it]=1;
                }
            }
            cnt++;
        }

        cnt--;

        vector<long long> fact(cnt+1);

        fact[0]=1;

        for(int i=1;i<=cnt;i++){
            fact[i] = (fact[i-1]*i)%mod;
        }

        long long revFacn = modpow(fact[cnt],mod-2,mod);

        vector<long long> revFactorial(cnt+1);

        revFactorial[cnt] = revFacn;

        for(int i=cnt-1;i>=0;i--){
            revFactorial[i] = (revFactorial[i+1]*(i+1))%mod;
        }

        long long ans = 0;

        cout<<cnt<<"\n";

        for(int i=1;i<=cnt;i+=2){
            long long curr = (revFactorial[i]*revFactorial[cnt-i])%mod;
            curr = (curr*fact[cnt])%mod;
            ans =  (ans +curr)%mod;
        }

        long long tot = modpow(2ll,cnt,mod);

        return ans;


    }
};