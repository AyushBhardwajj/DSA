class Solution {
public:
    int minimumDeletions(string s) {
        
        int preva = 0,prevb = 0;
        int tota =0 ,totb = 0;

        int n = s.length();
        int ans = n;

        for(int i=0;i<n;i++){
            if(s[i]=='a')tota++;
            else totb++;
        }

        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                int rema = tota-preva-1;
                int curr = rema+prevb;

                ans = min(ans,curr);
                preva++;
            }

            else{
                int rema = tota-preva;
                int curr = rema+prevb;

                ans = min(ans,curr);
                prevb++;
            }
        }

        return ans;
    }
};