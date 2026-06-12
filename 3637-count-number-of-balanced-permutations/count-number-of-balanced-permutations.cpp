class Solution {
public:
    long long binpowmod(long long base,long long pow,long long mod){
        base = (base)%mod;
        long long ans = 1;

        while(pow>0){
            if(pow&1){
                ans = (ans*base)%mod;
            }

            base = (base*base)%mod;

            pow = pow>>1;
        }

        return ans;
    }


    long long solve(int digit,int cnt,int sum,long long totalperm,vector<long long> &invfac,int n,int totsum,vector<int> &freq,vector<vector<vector<long long>>> &dp){
        if(digit == 10){
            if(sum == (totsum)/2 && cnt == (n+1)/2){
                return totalperm;
            }

            return 0;
        }

        if(dp[digit][cnt][sum]!=-1)return dp[digit][cnt][sum];

        long long mod = 1e9+7;
        long long ways = 0;
        
        for(int i=0;i<=min(freq[digit],(n+1)/2 - cnt);i++){
            long long inv = (invfac[i]*invfac[freq[digit]-i])%mod;

            long long curr = solve(digit+1,cnt+i,sum+i*digit,totalperm,invfac,n,totsum,freq,dp);

            ways = (ways+(curr*inv)%mod)%mod;
        }

        return dp[digit][cnt][sum] = ways;

    }
    int countBalancedPermutations(string num) {
        int n = num.length();
        int totsum = 0;
        vector<int> freq(10,0);

        for(int i=0;i<n;i++){
            totsum+=(num[i]-'0');
            freq[num[i]-'0']++;
        }

        if(totsum&1)return 0;

        long long mod = 1e9+7;

        vector<long long> fact(n+1,1);

        fact[1] =1;

        for(int i=2;i<=n;i++){
            fact[i] = (fact[i-1]*i)%mod;
        }

        vector<long long> invfac(n+1,1);

        invfac[n] = binpowmod(fact[n],mod-2,mod);

        for(int i=n-1;i>=0;i--){
            invfac[i] = (invfac[i+1]*(i+1))%mod;
        }

        vector<vector<vector<long long>>> dp(10,vector<vector<long long>>((n+3)/2,vector<long long>(361,-1)));

        long long totalper = (fact[(n+1)/2]*fact[n/2])%mod;

        return (int)solve(0,0,0,totalper,invfac,n,totsum,freq,dp);
    }
};