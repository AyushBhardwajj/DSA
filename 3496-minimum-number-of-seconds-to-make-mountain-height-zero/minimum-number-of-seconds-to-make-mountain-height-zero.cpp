
class Solution {
public:
    bool solve(long long sec,int mt,vector<int> &wt){
        long long h = 0;

        for(int i=0;i<wt.size();i++){
            long long start = 1,end = 1e8;
            long long curr = 0;
            while(start<=end){
                long long mid = (start+end)/2;

                if((sec/wt[i]) >= (mid*(mid+1)/2)){
                    curr = mid;
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }

            }

            h += curr;

            if(h>=mt)return true;
        }

        if(h>=mt)return true;
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long start = 1,end = 1e16;

        long long ans = 1e16;

        sort(workerTimes.begin(),workerTimes.end());

        while(start<=end){
            long long mid = (start+end)/2;

            bool f = solve(mid,mountainHeight,workerTimes);

            if(f){
                ans = mid;
                end = mid-1;
            }
            else{
                start =mid+1;
            }
        }

        return ans;


    }
};