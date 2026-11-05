class Solution {
public:
    long long solve(vector<long long> &curr,int ind,int k,int x,vector<vector<long long>> &dp){
        if(ind >= curr.size()){
            if(k==0)return 0;
            return 1e15;
        }

        if(dp[ind][k]!=-1)return dp[ind][k];

        long long take = 1e15,nottake = 1e15;

        if(k>0){
            take = curr[ind]+solve(curr,ind+x,k-1,x,dp);
        }
        nottake = solve(curr,ind+1,k,x,dp);

        return dp[ind][k] = min(take,nottake);

    }
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();
        vector<long long> curr;
        long long sum1 = 0,sum2 = 0;
        multiset<int> st1,st2;
        int s1 = 0,s2 = 0;
        int l = 0;

        for(int i=0;i<n;i++){
            sum2+=nums[i];
            st2.insert(nums[i]);
            s2++;

            if(s1>0){
                auto it = st1.rbegin();
                auto at = st2.begin();

                int val1 = *it;
                int val2 = *at;

                if(val1>val2){
                    st1.erase(prev(st1.end()));
                    st2.erase(at);
                    sum2 = sum2 - val2 +val1;
                    sum1 = sum1 - val1 +val2;
                    st1.insert(val2);
                    st2.insert(val1);
                }
            }

            if(x%2){
                while(s2>=s1){
                    auto it = st2.begin();
                    int val1 = *it;
                    st1.insert(val1);
                    sum2-=val1;
                    sum1+=val1;
                    st2.erase(it);
                    s1++;
                    s2--;
                }
            }
            else{
                while(s2>s1){
                    auto it = st2.begin();
                    int val1 = *it;
                    st1.insert(val1);
                    sum2-=val1;
                    sum1+=val1;
                    st2.erase(it);
                    s1++;
                    s2--;
                }
            }

            if((s1+s2) == x){
                if(x%2 == 0){
                    int m1 = *st2.begin();
                    int m2 = *st1.rbegin();

                    long long mint1 = 1ll*s1*m1 - sum1 + sum2 - 1ll*s2*m1;
                    long long mint2 = 1ll*s1*m2 - sum1 + sum2 - 1ll*s2*m2;

                    long long mint = min(mint1,mint2);

                    curr.push_back(mint);
                }
                else{
                    //int m1 = *s2.begin();
                    int m2 = *st1.rbegin();

                    //long long mint1 = 1ll*s1*m1 - sum1 + sum2 - 1ll*s2*m1;
                    long long mint2 = 1ll*s1*m2 - sum1 + sum2 - 1ll*s2*m2;

                    //long long mint = min(mint1,mint2);

                    curr.push_back(mint2);
                }

                int rem = nums[l];
                l++;

                auto it = st2.find(rem);

                if(it!=st2.end()){
                    st2.erase(it);
                    sum2 -= rem;
                    s2--;
                    continue;
                }
                else{
                    auto at = st1.find(rem);
                    st1.erase(at);
                    sum1 -= rem;
                    s1--;
                }
            }
        }

        vector<vector<long long>> dp(n,vector<long long>(k+1,-1));

        return solve(curr,0,k,x,dp);

    }
};