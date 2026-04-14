class Solution {
public:
    long long solve(vector<int>& robot, vector<int>& fact, int i, int j, vector<vector<long long>>& dp){
        
        if(i == robot.size()) return 0;
        if(j == fact.size()) return 1e15;

        if(dp[i][j] != -1) return dp[i][j];


        long long skip = solve(robot, fact, i, j+1, dp);

        
        long long take = abs(robot[i] - fact[j]) + solve(robot, fact, i+1, j+1, dp);

        return dp[i][j] = min(skip, take);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> fact;

        
        for(auto &f : factory){
            int pos = f[0];
            int cap = f[1];
            while(cap--){
                fact.push_back(pos);
            }
        }

        int n = robot.size();
        int m = fact.size();

        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        return solve(robot, fact, 0, 0, dp);
    }
};