class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> mp;

        for(int i=0;i<text.size();i++){
            mp[text[i]]++;
        }

        int ans = 1e9;

        ans = min(ans,mp['b']);
        ans = min(ans,mp['a']);
        ans = min(ans,mp['n']);
        ans = min(ans,mp['l']/2);
        ans = min(ans,mp['o']/2);

        return ans;
    }
};