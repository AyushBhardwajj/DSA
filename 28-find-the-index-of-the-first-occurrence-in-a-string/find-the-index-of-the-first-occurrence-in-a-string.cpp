class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();

        vector<int> lps(m,0);

        int len = 0;
        int ind = 1;

        while(ind<m){
            if(needle[ind] == needle[len]){
                len++;
                lps[ind] = len;
                ind++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    ind++;
                }
            }
        }

        int n = haystack.size();

        int i = 0;
        int j = 0;
        len = 0;

        while(i<n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }

            if(j == m){
                return i-m;
            }
            else if(haystack[i]!=needle[j]){
                if(j!=0){
                    j = lps[j-1];
                }
                else i++;
            }
        }

        return -1;
    }
};