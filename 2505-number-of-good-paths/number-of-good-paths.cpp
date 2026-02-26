class dsu{
public:
    vector<int> siz,par;

    dsu(int n){
        siz.resize(n,1);
        par.resize(n,0);

        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }

    int findPar(int u){
        if(par[u] == u)return u;

        return par[u] = findPar(par[u]);
    }

    void merge(int u,int v){
        int paru = findPar(u);
        int parv = findPar(v);

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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 0;

        vector<int> stat(n,0);

        dsu *obj = new dsu(n);

        map<int,vector<int>> mp;

        for(int i=0;i<vals.size();i++){
            mp[vals[i]].push_back(i);
        }

        for(auto it:mp){
            for(int i=0;i<it.second.size();i++){
                stat[it.second[i]] = 1;
            }

            for(int i=0;i<it.second.size();i++){
                for(auto at: adj[it.second[i]]){
                    if(stat[at]==1){
                        obj->merge(at,it.second[i]);
                    }
                }
            }

            map<int,int> mp2;

            for(auto at:it.second){
                mp2[obj->findPar(obj->par[at])]++;
            }

            for(auto at:mp2){
                if(at.second<=1)continue;

                long long curr = at.second;

                ans += (curr)*(curr-1)/2;
            }

        }

        return ans+n;
    }
};