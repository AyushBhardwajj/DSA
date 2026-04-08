class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        long long mod = 1e9+7;
        
        for(int i=0;i<queries.size();i++){
            long long num = queries[i][3];
            for(int j=queries[i][0];j<=queries[i][1];j+=queries[i][2]){
                num = queries[i][3];
                num = (num*nums[j])%mod;
                nums[j] = (int)num;
            }
        }

        int xrr = 0;

        for(int i=0;i<nums.size();i++){
            xrr = xrr^nums[i];
        }

        return xrr;
    }
};