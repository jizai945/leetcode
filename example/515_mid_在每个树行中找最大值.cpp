// 515. 在每个树行中找最大值
// 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

 

// 示例1：



// 输入: root = [1,3,2,5,3,null,9]
// 输出: [1,3,9]
// 示例2：

// 输入: root = [1,2,3]
// 输出: [1,3]
 

// 提示：

// 二叉树的节点个数的范围是 [0,104]
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
struct Node {
    TreeNode *nd;
    int level;
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<Node> q;
        q.push((Node){root, 1});

        while (!q.empty()) {
            if (q.front().level > ans.size()){
                ans.emplace_back(q.front().nd->val);
            } else if (q.front().nd->val > ans[q.front().level-1]) {
                ans[q.front().level-1] = q.front().nd->val;
            }

            if (q.front().nd->left != nullptr) {
                q.push((Node){q.front().nd->left, q.front().level+1});
            }
            if (q.front().nd->right != nullptr) {
                q.push((Node){q.front().nd->right, q.front().level+1});
            }
            q.pop();
        }

        return ans;
    }
};
