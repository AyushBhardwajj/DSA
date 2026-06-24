class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        vector<int> cost(n,1e9),time(n,1e9);

        cost[0] = passingFees[0];
        time[0] = 0;

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        pq.push({cost[0],time[0],0});

        while(!pq.empty()){
            vector<int> vec = pq.top();
            pq.pop();

            int cst = vec[0];
            int tim = vec[1];
            int node = vec[2];

            for(auto it:adj[node]){

                if(cost[it.first] > cst+passingFees[it.first] && tim+it.second<=maxTime){
                    cost[it.first] = cst+passingFees[it.first];
                    int ntim = tim+it.second;
                    pq.push({cost[it.first],ntim,it.first});
                }

                else if(time[it.first] > tim+it.second && tim+it.second<=maxTime){
                    time[it.first] = tim+it.second;
                    int ncost = cst+passingFees[it.first];
                    pq.push({ncost,time[it.first],it.first});
                }
            }
        }

        return cost[n-1]>=1e9?-1:cost[n-1];
    }
};