class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n<=1)return 0;

        stack<pair<int,char>> st;

        int open = 0;
        vector<int> vec(n+1,0);

        if(s[0]=='(')st.push({1,s[0]});

        int ans = 0;

        for(int i=1;i<n;i++){
            if(s[i]=='('){
                st.push({i+1,s[i]});
            }
            else if(!st.empty()){
                int num = st.top().first;
                vec[i+1] = i+1-num+1+vec[num-1];
                st.pop(); 
            }

            ans = max(ans,vec[i+1]);
        }

        return ans;
    }
};