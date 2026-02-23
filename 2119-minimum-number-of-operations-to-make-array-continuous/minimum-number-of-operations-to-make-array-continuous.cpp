class Solution {
public:
    int minOperations(vector<int>& nums) {
        multiset<int> st;
        map<int,int> mp;
        set<int> stt;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int start = 0;
        int maxt = 1;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            mp[nums[i]]++;
            stt.insert(nums[i]);

            int frst = *st.begin();
            int end = *st.rbegin();

            while(abs(end-frst)>=n){
                auto it = st.find(frst);
                st.erase(it);
                mp[frst]--;

                if(mp[frst]==0){
                    stt.erase(frst);
                }

                frst = *st.begin();
            }

            int curr = stt.size();

            maxt = max(maxt,curr);
        }

        int ans = n-maxt;

        return ans;
    }
};