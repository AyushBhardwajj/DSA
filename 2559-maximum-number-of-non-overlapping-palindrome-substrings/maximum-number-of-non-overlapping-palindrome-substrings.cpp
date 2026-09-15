class Solution {
public:
    int dp[2000][2000];
    int maxPalindromes(string s, int k) {
        
        int n = s.length();
        memset(dp,0,sizeof(dp));

        int i = 0,j=0;

        if(k==1)return n;
        if(n==1 && k>1)return 0;

        while(j<n){
            dp[i][j] = 1;
            i++,j++;
        }
        i = 0,j=1;

        while(j<n){
            if(s[i]==s[j])dp[i][j]=1;
            i++,j++;
        }
        i=0,j=2;

        while(j<n){
            int nj = j;
            i = 0;

            while(nj<n){
                if(s[i]==s[nj] && dp[i+1][nj-1]==1){
                    dp[i][nj]=1;
                }
                i++,nj++;
            }
            j++;
        }

        vector<int> ans(n,0);

        if(n==1)ans[0]=1;

        for(int i=1;i<n;i++){
            if(dp[0][i]==1 && (i+1)>=k){
                ans[i] = 1;
            }
            for(int j=1;j<=i;j++){
                if(dp[j][i]==1 && (i-j+1)>=k){
                    ans[i] = max(ans[i],1+ans[j-1]);
                }
                else ans[i] = max(ans[i],ans[j]);
            }
        }

        return ans[n-1];
    }
};