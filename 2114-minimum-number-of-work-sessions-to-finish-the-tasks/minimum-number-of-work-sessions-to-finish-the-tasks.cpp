class Solution {
public:
    int solve(int bits,int st,vector<int> &tasks,int tot,vector<vector<int>> &dp){
        int n = tasks.size();

        if(bits == ((1<<n)-1))return 0;

        int ans = 1e8;

        if(dp[bits][st]!=-1)return dp[bits][st];

        for(int i=0;i<n;i++){
            if(bits&(1<<i))continue;
            
            int nbits = bits|(1<<i);

            if(st>=tasks[i]){
                ans = min(ans,solve(nbits,st-tasks[i],tasks,tot,dp));
            }
            else{
                ans = min(ans,1+solve(nbits,tot-tasks[i],tasks,tot,dp));
            }
        }

        return dp[bits][st] = ans;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();

        vector<vector<int>> dp((1<<n),vector<int>(sessionTime+1,-1));

        int bits = 0;

        return 1+solve(bits,sessionTime,tasks,sessionTime,dp);
    }
};