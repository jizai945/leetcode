// 513. 找树左下角的值
// 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

// 假设二叉树中至少有一个节点。

 

// 示例 1:



// 输入: root = [2,1,3]
// 输出: 1
// 示例 2:



// 输入: [1,2,3,4,null,5,6,null,null,7]
// 输出: 7
 

// 提示:

// 二叉树的节点个数的范围是 [1,104]
// -231 <= Node.val <= 231 - 1 

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
private:
    int deepth;
    int ans = 0;
public:
    void dfs(TreeNode *root, int level) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            if (level > deepth) {
                deepth = level;
                ans = root->val;
            }
            return ;
        }

        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        deepth = 0;
        if (root == nullptr) return -1;
        dfs(root, 1);

        return ans;
    }
};
