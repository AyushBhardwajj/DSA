class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<int> vec1(32,0),vec2(32,0);

        for(int i=0;i<arr1.size();i++){
            int num = arr1[i];
            int cnt = 0;
            while(num>0){
                if(num&1){
                    vec1[cnt]++;
                }
                cnt++;
                num = num>>1;
            }
        }
        for(int i=0;i<arr2.size();i++){
            int num = arr2[i];
            int cnt = 0;
            while(num>0){
                if(num&1){
                    vec2[cnt]++;
                }
                cnt++;
                num = num>>1;
            }
        }

        int ans = 0;

        for(int i=0;i<32;i++){
            long long curr = 1ll*vec1[i]*vec2[i];
            curr = curr%2;

            if(curr>0){
                ans += 1<<i;
            }
        }

        return ans;
    }
};