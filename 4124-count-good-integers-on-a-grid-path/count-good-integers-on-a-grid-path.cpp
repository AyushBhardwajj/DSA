class Solution {
public:
    long long dp[17][20][10][2][17];
    
    long long solve(string &str,int strind,int dirind,int prevnumber ,int limit,string dir,int nxtind){
        if(strind==str.length()){
            return 1;
        }

        if(dp[strind][dirind][prevnumber][limit][nxtind]!=-1)return dp[strind][dirind][prevnumber][limit][nxtind];

        long long cnt = 0;
        int last = (limit==1)?(int)(str[strind]-'0'):9;
        int start = 0;
        if(strind == nxtind)start = prevnumber;

        for(int i=start;i<=last;i++){
            int nlimit = (limit==1 && (i==last))?1:0;
            int nprevnumber = prevnumber;
            int ndirind = dirind;
            int nnxtind = nxtind;
            if(strind == nxtind){
                nprevnumber = i;
                if(dir[dirind]=='R')nnxtind++;
                else nnxtind+=4;
                ndirind++;
            }
            

            cnt += solve(str,strind+1,ndirind,nprevnumber,nlimit,dir,nnxtind);
        }

        return dp[strind][dirind][prevnumber][limit][nxtind] = cnt;
    }

    long long countGoodIntegersOnPath(long long l, long long r, string directions) {

        string low = "",high="";

        for(int i=0;i<16;i++){
            low.push_back('0');
            high.push_back('0');
        }

        int cnt = 15;

        long long val = l-1;

        while(val>0){
            low[cnt] = (char)('0'+(val%10));
            val = val/10;
            cnt--;
        }

        val = r;
        cnt = 15;

        while(val>0){
            high[cnt] = (char)('0'+(val%10));
            val = val/10;
            cnt--;
        }

        //cout<<low<<" "<<high;

        memset(dp,-1,sizeof(dp));
        long long ll =  solve(low,0,0,0,1,directions,0);
        memset(dp,-1,sizeof(dp));
        long long rl = solve(high,0,0,0,1,directions,0);

        return rl-ll;
    }
};