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

vector<int> vals;   // 用於儲存inorder遍歷的val

public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);                      // 將inorder遍歷的val存入vals
        return build(0, vals.size()-1);     // 使用vals構建平衡的BST
    }

private:
    void inorder(TreeNode* root) {          // 將inorder遍歷的val存入vals
        if (!root) return;                  // 如果節點為空，則返回
        inorder(root->left);                // 遍歷左子樹
        vals.push_back(root->val);          // 記錄當前val
        inorder(root->right);               // 遍歷右子樹
    }

    TreeNode* build(int l, int r) {         // 使用vals構建平衡的BST
        if (l > r)  return nullptr;         // 如果索引範圍無效，返回空節點
        int m = l+(r-l)/2;                  // 計算中間索引
        auto root = new TreeNode(vals[m]);  // 使用中間索引的val創建新節點
        root->left = build(l, m-1);         // 遞迴構建左子樹
        root->right = build(m+1, r);        // 遞迴構建右子樹
        return root;                        // 返回根節點
    }
};

// Reference from 花花酱 LeetCode 1382. Balance a Binary Search Tree - 刷题找工作 EP315, https://youtu.be/U24USYuOWzw.