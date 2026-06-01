class Solution {
public:
    int strStr(string haystack, string needle) {
        long long base = 1;
        long long hash1 = 0;
        long long hash2 = 0;

        int n = needle.length();
        int h = haystack.length();

        long long mod = 1e9+7;

        for(int i=0;i<n;i++){
            hash1 = ((hash1*31)%mod + (needle[i]-'a'+1))%mod;
        }

        for(int i=0;i<n;i++){
            hash2 = ((hash2*31)%mod + (haystack[i]-'a'+1))%mod;
            if(i<n-1)base = (base*31)%mod;
        }

        if(hash1 == hash2){
            if(needle == haystack.substr(0,n))return 0;
        }

        for(int i=n;i<h;i++){
            hash2 = (hash2 - (base*(haystack[i-n]-'a'+1))%mod + mod)%mod;
            hash2  =  ((hash2*31)%mod + haystack[i]-'a'+1)%mod;

            if(hash1 == hash2){
                if(needle == haystack.substr(i-n+1,n))return i-n+1;
            }
        }

        return -1;
    }
};