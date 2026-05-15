class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        multiset<int> mt;

        int n = nums.size();

        vector<int> mp(n);

        mp[0] = nums[0];
        int start = 0;
        mt.insert(nums[0]);

        for(int i=1;i<n;i++){
            if((i-start) > k){
                auto it = mt.find(mp[start]);
                mt.erase(it);
                start++;
            }

            auto val  = mt.rbegin();;

            int curr = nums[i]+ *val;

            mp[i] = curr;

            mt.insert(curr);
        } 

        return mp[n-1];
    }
};