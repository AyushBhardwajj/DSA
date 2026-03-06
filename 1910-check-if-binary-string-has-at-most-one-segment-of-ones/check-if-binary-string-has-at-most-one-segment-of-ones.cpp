class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = true;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0' && flag){
                flag = false;
            }

            if(s[i]=='1' && !flag)return false;
        }

        return true;
    }
};