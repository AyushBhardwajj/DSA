class Solution {
public:
    long long dp[17][10][2][2][3][17];

    long long solve(string &str,int ind,int last,int tight,int isVal,int flow,int cnt){
        if(ind == str.length()){
            return cnt;
        }

        if(dp[ind][last][tight][isVal][flow][cnt]!=-1)return dp[ind][last][tight][isVal][flow][cnt];

        int limit = tight?(int)(str[ind]-'0'):9;

        long long ans = 0;

        for(int i=0;i<=limit;i++){
            int ntight = tight&&(i==limit)?1:0;
            int nxtisVal = (!isVal && (i==0))?0:1;

            if(isVal==0){
                ans += solve(str,ind+1,i,ntight,nxtisVal,0,cnt);
            }
            else{
                if(flow == 0){
                    if(i>last){
                        ans += solve(str,ind+1,i,ntight,nxtisVal,2,cnt);
                    }
                    else if(i == last){
                        ans += solve(str,ind+1,i,ntight,nxtisVal,0,cnt);
                    }
                    else{
                        ans += solve(str,ind+1,i,ntight,nxtisVal,1,cnt);
                    }
                }
                else if(flow == 1){
                    if(i>last){
                        ans += solve(str,ind+1,i,ntight,nxtisVal,2,cnt+1);
                    }
                    else if(i == last){
                        ans += solve(str,ind+1,i,ntight,nxtisVal,0,cnt);
                    }
                    else{
                        ans += solve(str,ind+1,i,ntight,nxtisVal,1,cnt);
                    }
                }
                else{
                    if(i<last){
                        ans += solve(str,ind+1,i,ntight,nxtisVal,1,cnt+1);
                    }
                    else if(i == last){
                        ans += solve(str,ind+1,i,ntight,nxtisVal,0,cnt);
                    }
                    else{
                        ans += solve(str,ind+1,i,ntight,nxtisVal,2,cnt);
                    }
                }
            }

        }

        return dp[ind][last][tight][isVal][flow][cnt] = ans;
    }

    long long totalWaviness(long long num1, long long num2) {
        num1--;
        string str1 = to_string(num1);
        string str2 = to_string(num2);

        memset(dp,-1,sizeof(dp));

        long long val1 = solve(str1,0,0,1,0,0,0);

        memset(dp,-1,sizeof(dp));

        long long val2 = solve(str2,0,0,1,0,0,0);

        return val2-val1;
    }
};