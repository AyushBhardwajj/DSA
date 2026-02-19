class Solution {
public:
    int countBinarySubstrings(string s) {
        int diff = 0;

        int o = 0,z = 0;
        int i = 0;
        int ans = 0;

        while(i<s.length()){
            char curr = s[i];
            z = 0;

            while(i<s.length() && curr == s[i]){
                z++;
                i++;
            }

            ans += min(o,z);

            curr = s[i];
            o = 0;

            while(i<s.length() && curr == s[i]){
                o++;
                i++;
            }

            ans  += min(o,z);

        }

        return ans;
    }
};