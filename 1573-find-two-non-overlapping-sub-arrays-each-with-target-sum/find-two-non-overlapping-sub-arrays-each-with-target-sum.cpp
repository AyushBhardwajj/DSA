class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> frst(n,1e9),sec(n,1e9);

        map<int,int> mp1,mp2;
        mp1[0]=-1;
        int sum = 0;
        int maxt = 1e8;


        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp1.count(sum-target)){
                int diff = i-mp1[sum-target];
                maxt = min(maxt,diff);
            }

            frst[i] = maxt;
            mp1[sum] = i;
        }

        mp2[0]=n;
        sum = 0;
        maxt  =1e8;

        for(int i=n-1;i>=0;i--){
            sum+=arr[i];
            if(mp2.count(sum-target)){
                int diff = mp2[sum-target]-i;
                maxt = min(maxt,diff);
            }

            sec[i] = maxt;
            mp2[sum] = i;
        }

        int ans = 1e9;

        for(int i=0;i<n-1;i++){
            ans = min(ans,frst[i]+sec[i+1]);
        }

        if(ans>1e5)return -1;

        return ans;
    }
};