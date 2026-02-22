class Solution {
public:
    string maximumXor(string s, string t) {
        int ones = 0 ,zeros = 0;

        int n = s.length();

        string ans = "";

        for(int i=0;i<t.length();i++){
            if(t[i]=='0')zeros++;
            else ones++;
        }

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(zeros>0){
                    ans.push_back('1');
                    zeros--;
                }
                else{
                    ans.push_back('0');
                }
            }
            else{
                if(ones>0){
                    ans.push_back('1');
                    ones--;
                }
                else{
                    ans.push_back('0');
                }
            }
        }

        return ans;
    }
};