class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        map<int,int> mp;
        set<int> st;

        int l = 0,r = 0;
        int n = nums.size();

        int gk = 0;
        int lk = 0;

        while(r<n){
            st.insert(nums[r]);
            mp[nums[r]]++;

            int cnt = st.size();

            while(cnt>k){
                gk += n-r;
                mp[nums[l]]--;

                if(mp[nums[l]]==0){
                    st.erase(nums[l]);
                    cnt--;
                }
                l++;
            }

            r++;
        }

        l = 0,r = 0;

        map<int,int> mp2;
        set<int> st2;

        while(r<n){
            st2.insert(nums[r]);
            mp2[nums[r]]++;
            int cnt = st2.size();

            if(cnt < k){
                lk += r-l+1;
            }
            else{
                while(cnt>=k){
                    mp2[nums[l]]--;
                    if(mp2[nums[l]]==0){
                        cnt--;
                        st2.erase(nums[l]);
                    }
                    l++;
                }
                lk += r-l+1;
            }
            r++;
        }

        int ans = (n*(n+1))/2 - gk - lk;

        cout<<gk<<"\n";
        cout<<lk<<"\n";

        return ans;

    }
};