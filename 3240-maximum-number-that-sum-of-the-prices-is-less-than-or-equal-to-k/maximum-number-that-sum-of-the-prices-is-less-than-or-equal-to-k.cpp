class Solution {
public:

    long long dp[53][2][53];

    long long solve(string &str,int idx,int flag,int cnt,int x){
        if(idx==str.length()){
            return cnt;
        }

        int nt = str.length();

        if(dp[idx][flag][cnt]!=-1)return dp[idx][flag][cnt];

        int limit = (flag == 1)?(int)(str[idx]-'0'):1;

        long long ans = 0;

        for(int i=0;i<=limit;i++){
            int ncnt = cnt;
            if((i==1) && ((nt-idx)%x == 0))ncnt +=1;
            int nflag = ((i==limit) && (flag))?1:0;

            ans += solve(str,idx+1,nflag,ncnt,x);
        }

        return dp[idx][flag][cnt] = ans;
    }

    string convertt(long long mid){
        string str = "";

        while(mid>0){
            if(mid&1){
                str.push_back('1');
            }
            else str.push_back('0');

            mid = mid/2;
        }

        while(str.length()<=51)str.push_back('0');

        reverse(str.begin(),str.end());

        return str;
    }
    
    long long findMaximumNumber(long long k, int x) {
        

        long long start = 0,end = 1e15+1;
        long long ans = 1e15;


        while(start<=end){
            memset(dp,-1,sizeof(dp));
            long long mid = start + (end-start)/2;

            string str = convertt(mid);

            long long curr = solve(str,0,1,0,x);

            if(curr>k){
                end = mid-1;
            }
            else{
                ans = mid;
                start = mid+1;
            }

            cout<<mid<<" "<<curr<<"\n";
        }

        return ans;
    }
};