class Solution {
public:
    int findpow(long long base,long long pow,long long mod){
        base = base%mod;
        long long ans  =1;
        while(pow){
            if(pow&1){
                ans = (ans*base)%mod;
            }

            base = (base*base)%mod;

            pow = pow>>1;
        }

        return (int)ans;
    }

    long long solve(int digit,int eveCnt,int currSum,vector<int>& freq,vector<long long> &invfac,int totalsum,long long totalPerm,int n,vector<vector<vector<long long>>> &dp){
        if(digit == 10){
            if((currSum == (totalsum)/2) && eveCnt == (n+1)/2){
                return totalPerm;
            }
            return 0;
        }

        if(dp[digit][eveCnt][currSum]!=-1)return dp[digit][eveCnt][currSum];


        long long ways = 0;
        long long mod = 1e9+7;

        for(int i = 0;i<=min(freq[digit],(n+1)/2 - eveCnt);i++){
            long long div = (invfac[i]*invfac[freq[digit]-i])%mod;

            long long val = solve(digit+1,eveCnt+i,currSum+i*digit,freq,invfac,totalsum,totalPerm,n,dp);

            ways = (ways + (div*val)%mod)%mod;
        }

        return dp[digit][eveCnt][currSum] = ways;
    }

    int countBalancedPermutations(string num) {
        int n = num.length();
        int totalsum = 0;
        long long mod = 1e9+7;

        vector<int> freq(10,0);

        for(int i=0;i<n;i++){
            freq[num[i]-'0']++;
            totalsum += (int)(num[i]-'0');
        }

        if(totalsum%2)return 0;

        vector<long long> fact(n+1,1);
        fact[0] = 1;
        fact[1] = 1;

        for(int i=2;i<=n;i++){
            fact[i] = ((fact[i-1]*i)%mod);
        }

        vector<long long> invfact(n+1,1);

        invfact[n] = findpow(fact[n],mod-2,mod);

        for(int i=n-1;i>=0;i--){
            invfact[i] = 1ll*(invfact[i+1]*(i+1))%mod;
        }

        long long totalPerm = 1ll*(fact[(n+1)/2]*fact[n/2])%mod;

        vector<vector<vector<long long>>> dp(10,vector<vector<long long>>((n+3)/2,vector<long long>(721,-1)));

        return solve(0,0,0,freq,invfact,totalsum,totalPerm,n,dp);

    }
};