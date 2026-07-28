class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int n = s.length();

        if(n==0 || n==1)return n;

        int ans = 0;

        int l = 0,r= 0;

        while(r<n){
            mp[s[r]]++;

            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }

            ans = max(ans,r-l+1);
            r++;
        }

        return ans;

    }
};