class dsu{
public:
    vector<int> par,siz;
    dsu(int n){
        par.resize(n);
        siz.resize(n);

        for(int i=0;i<n;i++){
            par[i]=i;
            siz[i]=1;
        }
    }

    int findpar(int u){
        if(u == par[u])return u;
        return par[u] = findpar(par[u]);
    }

    void merge(int u,int v){
        int par1 = findpar(u);
        int par2 = findpar(v);

        if(par1 == par2)return;

        else if(siz[par1]>siz[par2]){
            par[par2] = par1;
            siz[par1]+=siz[par2];
        }
        else{
            par[par1] = par2;
            siz[par2]+=siz[par1];
        }

        return;
    }

};
class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0] - points[j][0])+abs(points[i][1]-points[j][1]);
                pq.push({dist,i,j});
            }
        }

        dsu* obj = new dsu(n);

        int cnt = 0;
        int cost = 0;

        while(!pq.empty()){
            int d = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            int parx = obj->findpar(x);
            int pary = obj->findpar(y);

            if(parx == pary)continue;

            cost += d;
            obj->merge(parx,pary);
        }

        return cost;
    }
};