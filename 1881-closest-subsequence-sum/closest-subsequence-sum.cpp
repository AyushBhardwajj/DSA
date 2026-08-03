class Solution {
public:
    
    void solve(int ind,int end,vector<int> &nums,set<long long> &st,long long &sum){
        if(ind > end)return;

        sum+=nums[ind];
        st.insert(sum);
        solve(ind+1,end,nums,st,sum);
        sum-=nums[ind];
        solve(ind+1,end,nums,st,sum);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        set<long long> st1,st2;

        int n = nums.size();
        int start1 = n/2,start2 = start1+1;
        long long sum = 0;
        long long goald = goal;

        solve(0,start1,nums,st1,sum);
        solve(start2,n-1,nums,st2,sum);

        long long ans = abs(goald-1ll*0);

        for(auto it:st1){
            long long val1 = it;
            long long diff1 = abs(goald-val1);
            ans = min(ans,diff1);

            long long need = goald-val1;

            auto at = st2.lower_bound(need);

            if(at != st2.end()){
                long long val2 = *at;
                val2+=val1;
                long long diff2 = abs(goald-val2);
                ans = min(ans,diff2);
            }

            if(at != st2.begin()){
                at--;
                long long val3 = *at;
                val3+=val1;
                long long diff3 = abs(goald-val3);
                ans = min(ans,diff3);
            }

        }

        for(auto at:st2){
            long long val1 = at;
            long long diff1 = abs(goald-val1);
            ans = min(ans,diff1);
        }

        return (int)ans;


    }
};