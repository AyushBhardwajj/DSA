class Solution {
public:
   
    void solve(vector<string> &vec,vector<string> &ans,vector<vector<int>> &dp,int k){
        if(ans.size()>0)return;
        int n = vec.size();
        int m = vec[0].length();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = 0;
            }
        }

        dp[0][0] = 1;

        for(int i=1;i<m;i++){
            if(vec[0][i]=='.')dp[0][i] = dp[0][i-1];
        }

        for(int i=1;i<n;i++){
            if(vec[i][0] == '.')dp[i][0] = dp[i-1][0];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(vec[i][j] == '.'){
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }

        int curr = dp[n-1][m-1];

        if(curr==k){
            ans = vec;
            return;
        }

        if(curr<k)return;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 && j==0)continue;

                if(vec[i][j] == '.'){
                    vec[i][j] = '#';
                    solve(vec,ans,dp,k);
                    vec[i][j] = '.';
                }

            }
        }
    }

    vector<string> createGrid(int m, int n, int k) {
        vector<string> vec;
        vector<vector<int>> dp(m,vector<int>(n,0));

        string temp = "";

        for(int i=0;i<n;i++){
            temp.push_back('.');
        }

        for(int i=0;i<m;i++){
            vec.push_back(temp);
        }

        vector<string> ans;

        solve(vec,ans,dp,k);

        return ans;
        

    }
};