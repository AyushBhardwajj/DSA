class Solution {
public:
    int maxConsecutiveAnswers(string ak, int k) {
        int l = 0,r = 0;
        int n = ak.length();

        int sk = k;

        int ans = 0;

        while(r<n){
            if(ak[r]=='T'){
                if(k>0){
                    k--;
                }
                else{
                    while(ak[l]!='T'){
                        l++;
                    }
                    l++;
                }
            }

            ans = max(ans,r-l+1);
            r++;
        }
        l=0,r=0;
        k = sk;
        while(r<n){
            if(ak[r]=='F'){
                if(k>0){
                    k--;
                }
                else{
                    while(ak[l]!='F'){
                        l++;
                    }
                    l++;
                }
            }
            ans = max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};