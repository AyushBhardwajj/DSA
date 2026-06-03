class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        int n = s.length();

        string merge = s+"#"+rev;

        vector<int> lps(2*n+1,0);
        int length = 0;

        for(int i=1;i<=2*n;i++){
            if(merge[i] == merge[length]){
                lps[i] = length+1;
                length++;
            }
            else{
                if(length != 0){
                    length = lps[length-1];
                    i--;
                }
                else{
                    lps[i] = 0;
                }
            }
        }

        string ans = rev.substr(0,n-lps[2*n])+s;

        return ans;
    }
};