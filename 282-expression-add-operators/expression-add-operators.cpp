class Solution {
public:
    void solve(string num,long long curr,long long target,string temp,vector<string> &ans,int ind,int last){
        if(ind == num.length()){
            if(curr == target)ans.push_back(temp);
            return;
        }

        for(int i=ind;i<num.length();i++){
            if(i!=ind && num[ind]=='0')break;
            if(ind == 0){
                solve(num,stoll(num.substr(0,i+1)),target,temp+num.substr(0,i+1),ans,i+1,stoll(num.substr(0,i+1)));
            }
            else{
                solve(num,curr+stoll(num.substr(ind,i-ind+1)),target,temp+"+"+num.substr(ind,i-ind+1),ans,i+1,stoll(num.substr(ind,i-ind+1)));
                solve(num,curr-stoll(num.substr(ind,i-ind+1)),target,temp+"-"+num.substr(ind,i-ind+1),ans,i+1,-stoll(num.substr(ind,i-ind+1)));
                solve(num,curr-last+(last)*(stoll(num.substr(ind,i-ind+1))),target,temp+"*"+num.substr(ind,i-ind+1),ans,i+1,(last)*(stoll(num.substr(ind,i-ind+1))));
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        
        string temp  ="";

        vector<string> ans;

        solve(num,0,target,temp,ans,0,0);

        return ans;
    }
};