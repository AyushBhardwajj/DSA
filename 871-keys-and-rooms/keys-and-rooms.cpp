class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> st;
        st.insert(0);

        int n = rooms.size();
        int cnt = 1;
        vector<int> vis(n,0);
        vis[0]=1;

        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it:rooms[node]){
                if(!vis[it]){
                    cnt++;
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }

        if(cnt == n)return true;
        return false;
    }
};