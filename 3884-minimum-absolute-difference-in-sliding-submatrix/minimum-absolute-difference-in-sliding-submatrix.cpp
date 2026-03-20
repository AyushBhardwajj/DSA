class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        int row = m-k+1;
        int col = n-k+1;

        vector<vector<int>> ans(row,vector<int>(col,0));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                vector<int> nums;

                for(int p=i;p<i+k;p++){
                    for(int t=j;t<j+k;t++){
                        nums.push_back(grid[p][t]);
                    }
                }

                sort(nums.begin(),nums.end());

                int diff = 1e9;

                for(int p=1;p<nums.size();p++){
                    if(nums[p]==nums[p-1])continue;
                    diff = min(diff,nums[p]-nums[p-1]);
                }

                if(diff == 1e9)diff = 0;

                cout<<diff<<"\n";

                ans[i][j] = diff;
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<ans[i][j]<<"\n";
            }
        }

        return ans ;
    }
};