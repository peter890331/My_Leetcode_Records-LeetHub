class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> rank_map;
        vector<int> arr_sort = arr;
        vector<int> ans;
        sort(arr_sort.begin(), arr_sort.end());
        arr_sort.erase(unique(arr_sort.begin(), arr_sort.end()), arr_sort.end()); // unique返回值是重複元素的開始位置。
        for (int i=0; i<arr_sort.size(); i++){
            rank_map[arr_sort[i]] = i+1;
        }
        for (int i=0; i<arr.size(); i++){
            ans.push_back(rank_map[arr[i]]);
        }
        return ans;
    }
};

// Reference from 13.c++-stl::vector删除重复元素, https://blog.csdn.net/hgy413/article/details/6371475.