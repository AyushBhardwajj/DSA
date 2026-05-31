class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = needle.length();
        int h = haystack.length();
        
        vector<int> lps(n,0);

        int length = 0;

        for(int i=1;i<n;i++){
            if(needle[i] == needle[length]){
                length++;
                lps[i] = length;
            }
            else{
                if(length!=0){
                    length = lps[length-1];
                    i--;
                }
                else{
                    lps[i] = 0;
                }
            }
        }

        int s1 = 0,s2 = 0;

        while(s1<h){
            if(needle[s2] == haystack[s1]){
                s2++;
                s1++;
            }

            if(s2 == n)return s1-s2;
            if(s1 == h)return -1;

            if(needle[s2]!=haystack[s1]){
                if(s2!=0){
                    s2 = lps[s2-1];
                }
                else{
                    s1++;
                }
            }
        }

        return -1;
    }
};