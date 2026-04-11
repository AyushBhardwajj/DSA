class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        int ans = 1e9;

        for(auto it:mp){
            if(it.second.size()<3)continue;
            for(int i=2;i<it.second.size();i++){
                int a = it.second[i-2];
                int b = it.second[i-1];
                int c = it.second[i];
                ans = min(ans,abs(a-b)+abs(b-c)+abs(c-a));
            }
        }

        if(ans == 1e9)return -1;
        return ans;
    }
};