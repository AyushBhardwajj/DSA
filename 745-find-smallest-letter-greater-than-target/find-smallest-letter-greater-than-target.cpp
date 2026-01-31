class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ch = 'A';

        for(int i=0;i<letters.size();i++){
            if(letters[i]>target){
                if(ch == 'A'){
                    ch = letters[i];
                }
                else if(letters[i]<ch){
                    ch = letters[i];
                }
            }
        }

        if(ch == 'A')return letters[0];
        return ch;
    }
};