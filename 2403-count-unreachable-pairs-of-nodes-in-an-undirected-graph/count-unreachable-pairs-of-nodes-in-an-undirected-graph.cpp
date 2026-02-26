class dsu{
public:
    vector<int> siz,par;

    dsu(int n){
        siz.resize(n+1,1);
        par.resize(n+1,0);

        for(int i=0;i<=n;i++){
            par[i] = i;
        }
    }

    int findpar(int u){
        if(par[u] == u)return u;

        return par[u] = findpar(par[u]);
    }

    void merge(int u,int v){
        int paru = findpar(u);
        int parv = findpar(v);

        if(paru == parv)return;

        if(siz[paru]>siz[parv]){
            siz[paru]+=siz[parv];
            par[parv] = paru;
        }
        else{
            siz[parv]+=siz[paru];
            par[paru] = parv;
        }
    }

};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        dsu *obj = new dsu(n);

        long long ans = 0;

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            if(vis[i]==1)continue;

            queue<int> q;
            vis[i]=1;
            q.push(i);

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it:adj[node]){
                    obj->merge(obj->findpar(it),obj->findpar(node));
                }
            }
        }

        for(int i=0;i<n;i++){
            int part = obj->findpar(i);

            ans += n-obj->siz[part];
        }

        return ans/2;
    }
};