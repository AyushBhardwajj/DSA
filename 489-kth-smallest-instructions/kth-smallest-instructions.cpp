class Solution {
public:
    long long slv(long long neum,long long d1,long long d2){
        long long ans = 1;

        long long cnt1 = 1;
        long long end = min(d1,d2);

        while(cnt1<=end){
            ans = ans*neum;
            ans = ans/cnt1;
            neum--;
            cnt1++;
        }

        return ans;
    }
    string kthSmallestPath(vector<int>& destination, int k) {
        int vcnt = destination[0];
        int hcnt = destination[1];

        vector<long long> fac;
        fac.push_back(1);

        long long curr = 1;

        string ans = "";

        while(hcnt>0 && vcnt>0){
            long long start1 = 1;
            long long end1 = slv(hcnt+vcnt-1,hcnt-1,vcnt);
            if(k<=end1){
                ans +="H";
                hcnt--;
                continue;
            }
            k = k-end1;
            ans += "V";
            vcnt--;
        }

        while(hcnt>0){
            ans+="H";
            hcnt--;
        }

        while(vcnt>0){
            ans+="V";
            vcnt--;
        }

        return ans;
    }
};