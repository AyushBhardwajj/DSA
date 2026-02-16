class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        int cnt = 0;

        vector<int> vec(32,0);
        int start = 0;

        while(n>0){
            if(n&1){
                vec[start] = 1;
            }
            n = n>>1;
            start++;
        }

        reverse(vec.begin(),vec.end());
        

        for(int i=0;i<32;i++){
            if(vec[i]==1)ans += pow(2,i);
        }

        return ans;
        
    }
};