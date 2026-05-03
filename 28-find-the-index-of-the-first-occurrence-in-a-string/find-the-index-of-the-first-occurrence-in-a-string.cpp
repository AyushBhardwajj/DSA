class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();

        vector<int> lps(n,0);
        int length = 0;

        for(int i=1;i<n;i++){
            if(needle[i]==needle[length]){
                lps[i] = length+1;
                length++;
            }
            else{
                if(length>0){
                    length = lps[length-1];
                    i--;
                }else{
                    lps[i] = 0;
                }
            }
        }

        int i = 0,j = 0;
        int m = haystack.size();

        while(i<m){
            if(needle[j]==haystack[i]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }

            if(j==n){
                return i-j;
            }
        }

        return -1;
    }
};