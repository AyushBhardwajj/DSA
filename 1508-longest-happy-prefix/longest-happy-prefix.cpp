class Solution {
public:
    string longestPrefix(string s) {
        int maxt = 0;
        int length = 0;
        int n = s.length();

        vector<int> lps(n,0);

        for(int i=1;i<n;i++){
            if(s[i]==s[length]){
                lps[i] = length+1;
                length++;
            }
            else{
                if(length>0){
                    length = lps[length-1];
                    i--;
                }
                else{
                    lps[i] = 0;
                }
            }

            maxt  =max(maxt,length);
        }

        string str = s.substr(0,length);

        return str;
    }

};