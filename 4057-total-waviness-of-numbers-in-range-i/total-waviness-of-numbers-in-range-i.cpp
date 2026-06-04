class Solution {
public:
    int totalWaviness(int num1, int num2) {

        int ans = 0;
        for(int i=num1;i<=num2;i++){

            int numt = i;

            vector<int> vec;

            while(numt>0){
                vec.push_back(numt%10);
                numt = numt/10;
            }

            for(int i=1;i<vec.size()-1;i++){
                if(vec[i]>vec[i-1] && vec[i]>vec[i+1]){
                    ans++;
                }

                else if(vec[i]<vec[i-1] && vec[i]<vec[i+1]){
                    ans++;
                }
            }
        }

        return ans;
    }
};