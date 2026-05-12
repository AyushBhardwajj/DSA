class Solution {
public:
    
    long long binpowmod(long long base,long long pow,long long mod){
        base = base%mod;
        long long ans = 1ll;

        while(pow){
            if(pow&1){
                ans = (ans*base)%mod;
            }

            base = (base*base)%mod;

            pow = pow>>1;
        }

        return ans;
    }

    long long solve(string &num,int curr,int tot,int ind,vector<int> &digi,int sum,int oddind,int totFac,vector<long long> &invFac,vector<vector<vector<long long>>> &dp){
        if(ind == 10){
            if(curr == (sum/2) && tot == oddind)return totFac;
            return 0;
        }

        if(dp[curr][tot][ind]!=-1)return dp[curr][tot][ind];

        long long mod = 1e9+7;

        long long ways = 0;


        for(int i=0;i<=digi[ind];i++){
            long long crr = (invFac[i]*invFac[digi[ind]-i])%mod;

            long long ans = solve(num,curr+i*ind,tot+i,ind+1,digi,sum,oddind,totFac,invFac,dp);

            ans = (ans*crr)%mod;

            ways=(ways+ans)%mod;

        }

        return dp[curr][tot][ind] = ways;
    }
     
    int countBalancedPermutations(string num) {
        int sum = 0;
        int n = num.length();

        long long mod = 1e9+7;

        vector<vector<vector<long long>>> dp(721,vector<vector<long long>>(n+1,vector<long long>(10,-1)));

        vector<long long> invFac(81,0);


        long long invff = 1;

        for(int i=1;i<=80;i++){
            invff = (invff*i)%mod;
        }

        invff = binpowmod(invff,mod-2,mod);

        invFac[80] = invff;

        for(int i=79;i>=0;i--){
            invFac[i] = (invFac[i+1]*(i+1))%mod; 
        }

        
        long long et1 = 1;

        vector<int> digi(10,0);

        for(int i=0;i<num.length();i++){
            digi[(int)(num[i]-'0')]++;
            sum+=(int)(num[i]-'0');
        }

        if(sum%2)return 0;

        long long oddFac = 1;
        long long eveFac = 1;

        int eveind = (n+1)/2;
        int oddind = (n/2);

        for(int i=1;i<=oddind;i++){
            oddFac = (oddFac*i)%mod;
        }

        eveFac = oddFac;

        if(eveind != oddind)eveFac = (eveFac*eveind)%mod;

        long long totFac = (oddFac*eveFac)%mod;

        return (int)solve(num,0,0,0,digi,sum,oddind,totFac,invFac,dp);


    }
};