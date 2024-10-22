/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        queue<TreeNode*> level;
        level.push(root);

        while (!level.empty()){
            long long sum = 0;
            int level_size = level.size();
            for (int i=0; i<level_size; i++){
                TreeNode* node = level.front();
                sum += (node->val);
                level.pop();
                if (node->left){
                    level.push(node->left);
                }
                if (node->right){
                    level.push(node->right);
                }
                // cout<<sum<<',';
            }
            // cout<<endl;
            ans.push_back(sum);
        }

        if (k > ans.size()) return -1;

        // print(ans);
        sort(ans.begin(), ans.end(), greater<long long>());
        return ans[k-1];
    }

    // void print(vector<long long> ans){
    //     for (int i=0; i<ans.size(); i++){
    //         cout<<ans[i]<<',';
    //     }
    // }

};

// Reference from C++ std::queue 用法與範例, https://shengyu7697.github.io/std-queue/.
// Reference from C++中sort函数从大到小排序的两种方法, https://blog.csdn.net/lytwy123/article/details/84503492.
// Reference from UK07's solution.