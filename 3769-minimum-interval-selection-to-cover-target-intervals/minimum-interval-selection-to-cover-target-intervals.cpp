class Solution {
public:
    
    int minSelection(vector<vector<int>>& availableIntervals,
                    vector<vector<int>>& targetIntervals) {
        sort(targetIntervals.begin(), targetIntervals.end());

        vector<vector<int>> target;

        for (int j = 0; j < targetIntervals.size(); j++) {
            int s = targetIntervals[j][0];
            int e = targetIntervals[j][1];

            if (!target.empty() && s <= target.back()[1]) {
                target.back()[1] = max(target.back()[1], e);
            } else {
                target.push_back({s, e});
            }
        }

        sort(availableIntervals.begin(), availableIntervals.end());

        int ans = 0;
        int curr = -1;
        int i = 0;
        int n = availableIntervals.size();

        for (int j = 0; j < target.size(); j++) {
            int start = target[j][0];
            int end = target[j][1];

            if (curr >= end) continue;

            int pos = max(start, curr);

            if (pos == end) {
                int mx = -1;

                while (i < n && availableIntervals[i][0] <= pos) {
                    if (availableIntervals[i][1] >= pos) {
                        mx = max(mx, availableIntervals[i][1]);
                    }
                    i++;
                }

                if (mx < pos) return -1;

                curr = max(curr, mx);
                ans++;
                continue;
            }

            while (pos < end) {
                int mx = pos;

                while (i < n && availableIntervals[i][0] <= pos) {
                    mx = max(mx, availableIntervals[i][1]);
                    i++;
                }

                if (mx <= pos) return -1;

                pos = mx;
                ans++;
            }

            curr = max(curr, pos);
        }

        return ans;
    }

};