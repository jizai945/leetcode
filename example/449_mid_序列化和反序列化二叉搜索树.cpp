// 449. 序列化和反序列化二叉搜索树
// 序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

// 设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

// 编码的字符串应尽可能紧凑。

 

// 示例 1：

// 输入：root = [2,1,3]
// 输出：[2,1,3]
// 示例 2：

// 输入：root = []
// 输出：[]
 

// 提示：

// 树中节点数范围是 [0, 104]
// 0 <= Node.val <= 104
// 题目数据 保证 输入的树是一棵二叉搜索树。


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        afterRun(root, ans);
        ans = ans.substr(0, ans.size()-1);
        // cout << ans << endl;
        return ans;
    }

    void afterRun(TreeNode *node, string &s) {
        if (node == nullptr) return;

        afterRun(node->left, s);
        afterRun(node->right, s);
        s += to_string(node->val) + ",";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;

        stack<int> stk;
        int idx, start = 0;
        for (idx = 0; idx < data.size(); idx++) {
            if (data[idx] == ',') {
                stk.push(stoi(data.substr(start, idx-start)));
                start = idx+1;
            }
        }
        stk.push(stoi(data.substr(start)));

        return construct(INT_MIN, INT_MAX, stk);
    }
    
    TreeNode *construct(int lower, int upper, stack<int> &stk) {
        if (stk.empty() || stk.top() < lower || stk.top() > upper) {
            return nullptr;
        }

        int val = stk.top();
        TreeNode *root = new TreeNode(val);
        stk.pop();
        root->right = construct(val, upper, stk);
        root->left = construct(lower, val, stk);

        return root;
    } 
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;