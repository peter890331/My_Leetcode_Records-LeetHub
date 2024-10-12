class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start_times, end_times;

        // Extract start and end times
        for (const auto& interval : intervals) {
            start_times.push_back(interval[0]);
            end_times.push_back(interval[1]);
        }

        // Sort start and end times
        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int end_ptr = 0, group_count = 0;

        // Traverse through the start times
        for (int start : start_times) {
            if (start > end_times[end_ptr]) {
                end_ptr++;
            } else {
                group_count++;
            }
        }

        return group_count;
    }
};

// as_313's solution.

// ---------------------------------
// intervals   = [[5,10],[6,8],[1,5],[2,3],[1,10]]
// start_times = [1, 1, 2,  5,  6]
// end_times   = [3, 5, 8, 10, 10]
//   X X X X X  X X X  X  X
// ---------------------------------
// start_times = [1, 1, 2,  5,  6]
//                ^
// end_times   = [3, 5, 8, 10, 10]
//                ^
//   X X X X X X X X  X  X
//  [1       5] 
// ---------------------------------
// start_times = [1, 1, 2,  5,  6]
//                   ^
// end_times   = [3, 5, 8, 10, 10]
//                ^
//   X X X X X  X X X  X  X
//  [1       5] 
//  [1                  10] 
// ---------------------------------
// start_times = [1, 1, 2,  5,  6]
//                      ^
// end_times   = [3, 5, 8, 10, 10]
//                ^
//   X X X X X  X X X  X  X
//  [1       5] 
//  [1                  10] 
//    [2 3]
// ---------------------------------
// start_times = [1, 1, 2,  5,  6]
//                          ^
// end_times   = [3, 5, 8, 10, 10]
//                ^
//   X X X X X  X X X  X  X
//  [1       5] 
//  [1                  10] 
//    [2 3] [5          10]
// ---------------------------------
// start_times = [1, 1, 2,  5,  6]
//                              ^
// end_times   = [3, 5, 8, 10, 10]
//                   ^
//   X X X X X  X X X  X  X
//  [1       5][6  8] 
//  [1                   10] 
//    [2 3] [5           10]
// ---------------------------------