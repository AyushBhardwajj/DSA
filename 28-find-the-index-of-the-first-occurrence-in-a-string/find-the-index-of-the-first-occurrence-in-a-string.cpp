class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> lps(m,0);
        int length = 0;

        for(int i=1;i<m;i++){
            if(needle[i]==needle[length]){
                length++;
                lps[i] = length;
            }
            else{
                if(length == 0){
                    lps[i] = 0;
                }
                else{
                    length = lps[length-1];
                    i--;
                }
            }
        }

        int i = 0;
        int j = 0;

        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }

            if(j == m){
                return i-j;
            }
            else if(i<n && haystack[i]!=needle[j]){
                if(j==0){
                    i++;
                }
                else{
                    j = lps[j-1];
                }
            }
        }

        return -1;
    }
};