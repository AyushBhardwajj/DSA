class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long tot = 0;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tot+=grid[i][j];
            }
        }

        long long sum1 = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum1+=grid[i][j];
            }

            if(sum1 == (tot-sum1)){
                return true;
            }
        }

        long long sum2 = 0;

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                sum2+=grid[i][j];
            }

            if(sum2 == (tot-sum2))return true;
        }

        return false;
    }
};