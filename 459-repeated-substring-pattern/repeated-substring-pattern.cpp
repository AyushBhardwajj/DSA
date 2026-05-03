class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length()/2;
        int n = s.length();

        for(int i=len;i>=1;i--){
            if(n%i == 0){
                string str = "";
                int times = n/i;
                string nstr = s.substr(0,i);

                while(times--){
                    str+=nstr;
                }

                if(str == s)return true;
            }
        }

        return false;
    }
};