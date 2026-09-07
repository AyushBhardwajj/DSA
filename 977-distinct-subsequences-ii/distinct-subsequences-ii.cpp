class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        long long mod = 1e9+7;

        vector<vector<long long>> dp(n,vector<long long>(n,0ll));
        vector<int> chh(26,-1);
        vector<int> stt(n,0);

        dp[0][0]=1;
        chh[s[0]-'a'] = 0; 

        for(int i=1;i<n;i++){
            int ind = (int)(s[i]-'a');

            if(chh[ind] != -1){
                dp[0][i] = dp[0][i-1];
                stt[i] = chh[ind];
                chh[ind] = i;
                continue;
            }

            dp[0][i] = dp[0][i-1] + 1;
            chh[ind] = i;
        }

        for(int i=1;i<n;i++){
            for(int j=i;j<n;j++){
                if(stt[j]<=0){
                    dp[i][j] = (dp[i][j-1]+dp[i-1][j-1])%mod;
                }
                else{
                    // cout<<"hello"<<"\n";
                    dp[i][j] = (dp[i][j-1] + dp[i-1][j-1] - dp[i-1][stt[j]-1]+mod)%mod;
                }
            }
        }

        // for(int i=0;i<3;i++){
        //     for(int j=0;j<3;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        long long ans = 0;

        for(int i=0;i<n;i++){
            ans = (ans + dp[i][n-1])%mod;
        }

        return (int)ans;
    }
};