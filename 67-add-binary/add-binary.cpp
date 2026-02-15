class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";

        int start1 = a.length()-1,start2 = b.length()-1;
        int curr = 0;

        while(start1>=0 && start2>=0){
            int frst = (int)(a[start1]-'0');
            int sec = (int)(b[start2]-'0');
            int sum = frst+sec+curr;

            if(sum == 0){
                ans.push_back('0');
                curr = 0;
            }
            else if(sum==1){
                ans.push_back('1');
                curr = 0;
            }

            else if(sum==2){
                ans.push_back('0');
                curr = 1;
            }
            else{
                ans.push_back('1');
                curr = 1;
            }
            start1--;
            start2--;
        }

        while(start1>=0){
            int frst = (int)(a[start1]-'0');
            int sum = frst+curr;

            if(sum == 0){
                ans.push_back('0');
                curr = 0;
            }
            else if(sum==1){
                ans.push_back('1');
                curr = 0;
            }

            else if(sum==2){
                ans.push_back('0');
                curr = 1;
            }
            else{
                ans.push_back('1');
                curr = 1;
            }
            start1--;
        }

        while(start2>=0){
            int frst = (int)(b[start2]-'0');
            int sum = frst+curr;

            if(sum == 0){
                ans.push_back('0');
                curr = 0;
            }
            else if(sum==1){
                ans.push_back('1');
                curr = 0;
            }

            else if(sum==2){
                ans.push_back('0');
                curr = 1;
            }
            else{
                ans.push_back('1');
                curr = 1;
            }
            start2--;
        }

        if(curr==1){
            ans.push_back('1');
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};