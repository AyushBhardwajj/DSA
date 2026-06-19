class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
                if(str1[i] == str2[j])dp[i+1][j+1] = max(dp[i+1][j+1],1+dp[i][j]);
            }
        }

        int last1 = n1,last2 = n2;

        string ans = "";

        while(last1>0 && last2>0){
            if(str1[last1-1] == str2[last2-1]){
                ans.push_back(str1[last1-1]);
                last1--;
                last2--;
            }
            else if(dp[last1][last2-1] > dp[last1-1][last2]){
                ans.push_back(str2[last2-1]);
                last2--;
            }
            else{
                ans.push_back(str1[last1-1]);
                last1--;
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