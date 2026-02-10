class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        
        map<char,int> mp;
        int n = s.length();

        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        stack<char> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>s[i] && mp[st.top()]>1){
                mp[st.top()]--;
                st.pop();
            }
            st.push(s[i]);
        }

        string ans = "";

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        int i = ans.length()-1;

        while(i>0 && ans[i]==ans[i-1]){
            ans.pop_back();
            mp[ans[i-1]]--;
            i--;
        }


        // while(i>0 && ans[i]==s[i] && mp[s[i]]>1){
        //     ans.pop_back();
        //     mp[s[i]]--;
        //     i--;
        // }

        i = ans.length()-1;

        while(i>0){
            if(mp[ans[i]]>1){
                mp[ans[i]]--;
                ans.pop_back();
            }
            else break;
            i--;
        }



        return ans;
    }
};