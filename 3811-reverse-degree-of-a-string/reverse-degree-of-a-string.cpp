class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans = 0;

        for(int i=0;i<n;i++){
            int crr = s[i]-'a';
            crr = 26-crr;
            ans += crr*(i+1);
        }

        return ans;
    }
};