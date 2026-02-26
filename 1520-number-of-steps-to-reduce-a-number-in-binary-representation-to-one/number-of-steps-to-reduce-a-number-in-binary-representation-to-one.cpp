class Solution {
public:
    int numSteps(string s) {

        int ans = 0;

        while(s.length()>1){
            int n = s.length();
            if(s[n-1] == '0'){
                ans++;
                s.pop_back();
            }
            else {
                ans++;
                s[n-1] = '0';
                bool flag = true; 
                for(int i=n-2;i>=0;i--){
                    if(s[i]=='0'){
                        s[i]='1';
                        flag = false;
                        break;
                    }
                    else{
                        s[i]='0';
                    }
                }

                if(flag){
                    s = "1"+s;
                }
            }
        }

        return ans;
    }
};