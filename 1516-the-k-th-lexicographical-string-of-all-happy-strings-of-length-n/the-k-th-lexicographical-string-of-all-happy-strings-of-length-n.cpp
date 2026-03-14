class Solution {
public:
    void solve(int ind,int n,int &k,vector<char> &ch,char last,string &ans,string temp){
        if(ind == n){
            k--;
            if(k==0){
                ans = temp;
            }

            return;
        }

        for(int i=0;i<ch.size();i++){
            if(ch[i]!=last){
                temp.push_back(ch[i]);
                solve(ind+1,n,k,ch,ch[i],ans,temp);
                temp.pop_back();
            }
        }

        return;
    }
    string getHappyString(int n, int k) {
        vector<char> vec = {'a','b','c'};

        string ans = "",temp = "";

        solve(0,n,k,vec,'d',ans,temp);

        return ans;

    }
};