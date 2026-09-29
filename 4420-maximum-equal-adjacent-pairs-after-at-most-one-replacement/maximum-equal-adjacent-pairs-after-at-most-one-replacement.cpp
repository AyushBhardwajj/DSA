class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();

        map<int,map<int,int>> mp;
        int cnt = 0;

        for(int i=0;i<n-1;i++){
            mp[nums[i]][nums[i+1]]++;
            if(nums[i]!=nums[i+1])mp[nums[i+1]][nums[i]]++;
            if(nums[i]==nums[i+1])cnt++;
        }

        int ans = 0;

        for(auto it:mp){
            int maxt = 0;
            for(auto at:it.second){
                if(at.first == it.first)continue;
                int val = at.second;
                maxt = max(maxt,val);
            }

            ans = max(ans,maxt+cnt);
        }

        return ans;


    }
};