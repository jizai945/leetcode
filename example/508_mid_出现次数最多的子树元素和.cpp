// 508. 出现次数最多的子树元素和
// 给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。

// 一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。

 

// 示例 1：



// 输入: root = [5,2,-3]
// 输出: [2,-3,4]
// 示例 2：



// 输入: root = [5,2,-5]
// 输出: [2]
 

// 提示:

// 节点数在 [1, 104] 范围内
// -105 <= Node.val <= 105

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
    unordered_map<int, int> mp;
public:
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int sums = root->val;
        sums += dfs(root->left);
        sums += dfs(root->right);
        mp[sums]++;
        return sums;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        int times = 0;

        dfs(root);
        for (auto &[key, val]: mp) {
            
            if (val == times) ans.push_back(key);
            else if (val > times) {
                ans.clear();
                times = val;
                ans.push_back(key);
            }
        }

        return ans;
    }
};

