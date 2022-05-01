// 1305. 两棵二叉搜索树中的所有元素
// 给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.

 

// 示例 1：



// 输入：root1 = [2,1,4], root2 = [1,0,3]
// 输出：[0,1,1,2,3,4]
// 示例 2：



// 输入：root1 = [1,null,8], root2 = [8,1]
// 输出：[1,1,8,8]
 

// 提示：

// 每棵树的节点数在 [0, 5000] 范围内
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
public:
    void inorder(TreeNode *root, vector<int> &cache) {
        if (root == nullptr) return;
        inorder(root->left, cache);
        cache.emplace_back(root->val);
        inorder(root->right, cache);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans, r1, r2;

        inorder(root1, r1);
        inorder(root2, r2);

        for (int i=0, j=0; i<r1.size() || j<r2.size(); ) {
            if (i == r1.size()) {
                ans.emplace_back(r2[j]);
                j++;
            } else if (j == r2.size()) {
                ans.emplace_back(r1[i]);
                i++;
            } else {
                ans.emplace_back(min(r1[i], r2[j]));
                r1[i] < r2[j]? i++: j++;
            }
        }

        return ans;
    }
};

