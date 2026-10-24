class Solution {
public:
    
    int solve(int ind,int len,int cnt,vector<int> &vec,vector<vector<int>> &dp){
        if(ind>=vec.size())return 0;

        int take = 0,nottake = 0;

        if(dp[ind][cnt]!=-1)return dp[ind][cnt];

        if(ind-len+1 >= 1 && cnt>0){
            take = vec[ind]-vec[ind-len]+solve(ind+len,len,cnt-1,vec,dp);
        }

        nottake = solve(ind+1,len,cnt,vec,dp);

        return dp[ind][cnt] = max(take,nottake);
    }
    
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.length();

        vector<int> vec(n+1+carpetLen,0);
        int white = 0,black = 0;

        for(int i=0;i<n;i++){
            if(floor[i]=='1'){
                vec[i+1] = vec[i]+1;
                white++;
            }
            else{
                vec[i+1] = vec[i];
                black++;
            }
        }

        for(int i=n+1;i<vec.size();i++){
            vec[i] = vec[i-1];
        }

        int k = vec.size();

        vector<vector<int>> dp(k+2,vector<int>(numCarpets+1,-1));

        int maxt = solve(1,carpetLen,numCarpets,vec,dp);

        return white-maxt;
    }
};