class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0)return false;

        unordered_map<int,int> mp;
        int n = nums.size();

        int start = 0,end = k;

        for(int i=0;i<min(n,k);i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]]=1;
            }
            else return true;
        }

        

        while(end<n){
            if(mp.find(nums[end]) == mp.end()){
                mp[nums[end]]=1;
            }
            else return true;

            mp[nums[start]]--;
            if(mp[nums[start]]==0)mp.erase(nums[start]);
            end++;
            start++;
        }

        return false;

    }
};