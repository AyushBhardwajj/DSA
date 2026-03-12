class dsu{
public:
    vector<int> par,siz;

    dsu(int n){
        par.resize(n,0);
        siz.resize(n,1);

        for(int i=0;i<n;i++){
            par[i]  =i;
        }
    }

    int findpar(int u){
        if(par[u] == u)return u;

        return par[u] = findpar(par[u]);
    }

    void merge(int u,int v){
        int pu = findpar(u);
        int pv = findpar(v);

        if(pu == pv)return;

        if(siz[pu]>siz[pv]){
            par[pv] = pu;
            siz[pu]+=siz[pv];
        }
        else{
            par[pu] = pv;
            siz[pv]+=siz[pu];
        }
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int start = 1,end = 1e6;

        vector<vector<vector<int>>> adj(n);
        vector<vector<int>> adj2(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2],edges[i][3]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2],edges[i][3]});
        }

        vector<int> vis(n,0);

        queue<int> q;
        vis[0]=1;
        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                if(!vis[adj[node][i][0]]){
                    vis[adj[node][i][0]] = 1;
                    q.push(adj[node][i][0]);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(vis[i]==0)return -1;
        }

        dsu *obj = new dsu(n);
        int mint = 1e9;
        int cnt = 0;

        for(int i=0;i<edges.size();i++){
            if(edges[i][3]==1){
                mint = min(mint,edges[i][2]);
                obj->merge(edges[i][0],edges[i][1]);
                cnt++;
            }
        }

        vector<pair<int,pair<int,int>>> vec;

        for(int i=0;i<edges.size();i++){
            if(edges[i][3]==0){
                vec.push_back({edges[i][2],{edges[i][1],edges[i][0]}});
            }
        }

        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());

        vector<int> lastt;

        for(int i=0;i<vec.size();i++){
            int u = vec[i].second.first;
            int v = vec[i].second.second;
            int cost = vec[i].first;

            int paru = obj->findpar(u);
            int parv = obj->findpar(v);

            if(paru == parv)continue;

            obj->merge(paru,parv);
            lastt.push_back(cost);
            cnt++;
        }

        if(cnt!=(n-1))return -1;

        sort(lastt.begin(),lastt.end());

        for(int i=0;i<lastt.size();i++){
            if(k>0){
                lastt[i] = lastt[i]*2;
                k--;
            }

            mint = min(mint,lastt[i]);
        }

        return mint;


        
    }
};