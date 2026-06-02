class Solution {
public:
    
    int solve(vector<int>& firstStart,
              vector<int>& firstDuration,
              vector<int>& secondStart,
              vector<int>& secondDuration) {

        int minEnd = INT_MAX;

        for (int i = 0; i < firstStart.size(); i++) {
            minEnd = min(minEnd, firstStart[i] + firstDuration[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < secondStart.size(); i++) {
            int finishTime =
                max(minEnd, secondStart[i]) + secondDuration[i];

            ans = min(ans, finishTime);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int landFirst =
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration);

        int waterFirst =
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration);

        return min(landFirst, waterFirst);
    }
};