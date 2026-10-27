class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string frst = "";
        string sec = "";

        for(int i=0;i<n;i++){
            frst.push_back('.');
            sec.push_back('#');
        }

        sec[n-1] = '.';

        ans.push_back(frst);

        for(int i=0;i<m-1;i++){
            ans.push_back(sec);
        }

        return ans;

        
    }
};