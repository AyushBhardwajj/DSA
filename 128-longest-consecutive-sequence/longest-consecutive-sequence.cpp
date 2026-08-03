class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }

        if(nums.size() == 0)return 0;

        int ans = 1;

        for(auto it:st){
            int val1 = it;
            int cnt = 1;

            if(st.find(val1-1)!=st.end())continue;

            while(st.find(val1+1) != st.end()){
                cnt++;
                ans = max(ans,cnt);
                val1++;
            }
        }

        return ans;
    }
};