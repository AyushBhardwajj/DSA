class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even(26,0), odd(26,0);
        for(int i=0;i<s1.length();i++){
            if(i%2 == 0){
                even[s1[i]-'a']++;
            }
            else{
                odd[s1[i]-'a']++;
            }
        }

        for(int i=0;i<s2.length();i++){
            int ind = (int)(s2[i]-'a');
            if(i%2==0){
                if(even[ind]>0){
                    even[ind]--;
                }
                else{
                    return false;
                }
            }
            else{
                if(odd[ind]>0){
                    odd[ind]--;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};