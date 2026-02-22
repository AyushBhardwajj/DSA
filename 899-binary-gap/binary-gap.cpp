class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int cnt = 0;
        bool flag = false;
        while(n>0){
            if(n&1){
                flag = true;
                ans = max(ans,cnt);
                cnt = 1;
            }
            else if(flag){
                cnt++;
            }

            n = n>>1;
        }

        return ans;
    }
};