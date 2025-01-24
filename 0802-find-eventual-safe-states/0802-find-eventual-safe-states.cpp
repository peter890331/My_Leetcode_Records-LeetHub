class Solution {
public:
    bool safe[10000], visited[10000];       // 宣告，在函數中再初始化。
    // vector<bool> safe(10000, false);     // 不能在全域範圍內初始化。
    // vector<bool> visited(10000, false);  // 不能在全域範圍內初始化。

    bool DFS(int now, vector<vector<int>>& graph) {
        bool is_safe = visited[now] = true;
        for (int j: graph[now]){
            if (!visited[j]){
                DFS(j, graph);
            }
            is_safe &= safe[j];
        }
        return safe[now] = is_safe;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        memset(safe, false, sizeof(safe));          // 在函數中再初始化。
        memset(visited, false, sizeof(visited));    // 在函數中再初始化。
        for (int i=0; i<n; i++){
            if (!visited[i]){
                DFS(i, graph);
            }
            if (safe[i]){
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// DFS.
// Reference from LeetCode - 802. Find Eventual Safe States　解題心得, https://home.gamer.com.tw/artwork.php?sn=5594597.