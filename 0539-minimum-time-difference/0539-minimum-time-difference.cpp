class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int timeSize = timePoints.size();
        vector<int> timeDiff(timeSize, 0);
        int ans = 24*60+1;

        for (int i=0; i<timeSize; i++){
            timeDiff[i] = stoi(timePoints[i].substr(0, 2))*60 + stoi(timePoints[i].substr(3, 2));
        }
        
        sort(timeDiff.begin(), timeDiff.end());

        for (int i=1; i<timeSize; i++){
            ans = min(ans, timeDiff[i] - timeDiff[i-1]);
        }

        ans = min(ans, (24*60 - timeDiff.back() + timeDiff.front()));

        return ans;

    }
};