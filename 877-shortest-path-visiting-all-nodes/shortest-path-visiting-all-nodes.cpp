class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        if(n<=1)return 0;

        queue<pair<int,int>> q;
        set<pair<int,int>> st;

        for(int i=0;i<n;i++){
            int mask = (1<<i);

            q.push({i,mask});
            st.insert({i,mask});
        }

        int ans = 1;


        while(!q.empty()){
            int siz = q.size();

            for(int i=0;i<siz;i++){
                int node = q.front().first;
                int mask = q.front().second;
                q.pop();

                for(auto it:graph[node]){
                    int nmask = mask|(1<<it);

                    if(nmask == ((1<<n)-1))return ans;

                    if(st.find({it,nmask})==st.end()){
                        q.push({it,nmask});
                        st.insert({it,nmask});
                    }
                }

            }
            ans++;
        }

        return -1;
    }
};