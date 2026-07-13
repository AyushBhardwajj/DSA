class Solution {
public:
    long long binpowermod(long long base,long long pow,long long mod){
        long long ans = 1;
        base = base%mod;

        while(pow>0){
            if(pow&1){
                ans = (ans*base)%mod;
            }

            base = (base*base)%mod;

            pow = pow>>1;
        }

        return ans;
    }
    int minimumCost(vector<int>& nums, int k) {
        
        long long curr = k;

        int n = nums.size();

        long long cost = 0;

        long long ans = 0;

        long long mod = 1e9+7;

        for(int i=0;i<n;i++){
            if(curr>=nums[i]){
                curr-=nums[i];
                continue;
            }
            long long need = nums[i]-curr;
            long long div = (need+k-1)/k;



            long long costadd = ((((div%mod)*(cost+1+cost+div)%mod)%mod)*binpowermod(2ll,mod-2,mod))%mod;

            ans  = (ans + costadd)%mod;

            cost = (cost+div)%mod;

            curr = div*k - need;
        }

        return ans;
    }
};