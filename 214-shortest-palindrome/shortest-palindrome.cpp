class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        string st = s;
        reverse(st.begin(),st.end());
        string temp = s+"#"+st;
        vector<int> lps(temp.length(),0);
        int k = temp.length();

        lps[0] = 0;
        int length = 0;

        for(int i=1;i<k;i++){
            if(temp[i] == temp[length]){
                lps[i] = length+1;
                length++;
            }
            else{
                if(length == 0){
                    lps[i] = length;
                }
                else{
                    length = lps[length-1];
                    i--;
                }
            }
        }

        string culprit = st.substr(0,n-lps[k-1]);

        string ans = culprit+s;

        return ans;

        
    }
};