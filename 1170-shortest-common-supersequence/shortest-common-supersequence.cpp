class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        string ans = "";

        int last1 = n1,last2 = n2;

        while(last1>0 && last2>0){
            if(str1[last1-1]==str2[last2-1]){
                ans.push_back(str1[last1-1]);
                last1--;
                last2--;
            }

            else{
                if(dp[last1-1][last2]>dp[last1][last2-1]){
                    ans.push_back(str1[last1-1]);
                    last1--;
                }
                else{
                    ans.push_back(str2[last2-1]);
                    last2--;
                }
            }
        }

        while(last1>0){
            ans.push_back(str1[last1-1]);
            last1--;
        }

        while(last2>0){
            ans.push_back(str2[last2-1]);
            last2--;
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};