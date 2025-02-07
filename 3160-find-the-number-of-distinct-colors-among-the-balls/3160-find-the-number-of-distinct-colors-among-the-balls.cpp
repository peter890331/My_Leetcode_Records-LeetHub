class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball;
        unordered_map<int, int> color;
        vector<int> ans;
        for (auto querie: queries){
            int ball_ = querie[0];
            int color_ = querie[1];
            if (!ball[ball_]){
                ball[ball_] = color_;
                color[color_]++;
            }
            else {
                color[ball[ball_]]--;
                if (color[ball[ball_]] == 0){
                    color.erase(ball[ball_]);
                }
                ball[ball_] = color_;
                color[color_]++;
            }
            ans.push_back(color.size());
        }
        return ans;
    }
};