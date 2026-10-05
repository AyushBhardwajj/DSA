class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<pair<int,char>> st;

        int ans = 0;

        int n = s.length();

        int cnt = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
                st.push({cnt,'('});
            }
            else{
                int cc =0;
                while(i<n && s[i]==')'){
                    i++;
                    cc++;
                }
                i--;

                ans += pow(2,cnt-1);
                cnt = cnt-cc;
            }
        }

        return ans;
    }
};