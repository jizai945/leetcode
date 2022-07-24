// 919. 完全二叉树插入器
// 完全二叉树 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。

// 设计一种算法，将一个新节点插入到一个完整的二叉树中，并在插入后保持其完整。

// 实现 CBTInserter 类:

// CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构；
// CBTInserter.insert(int v)  向树中插入一个值为 Node.val == val的新节点 TreeNode。使树保持完全二叉树的状态，并返回插入节点 TreeNode 的父节点的值；
// CBTInserter.get_root() 将返回树的头节点。
 

// 示例 1：



// 输入
// ["CBTInserter", "insert", "insert", "get_root"]
// [[[1, 2]], [3], [4], []]
// 输出
// [null, 1, 2, [1, 2, 3, 4]]

// 解释
// CBTInserter cBTInserter = new CBTInserter([1, 2]);
// cBTInserter.insert(3);  // 返回 1
// cBTInserter.insert(4);  // 返回 2
// cBTInserter.get_root(); // 返回 [1, 2, 3, 4]
 

// 提示：

// 树中节点数量范围为 [1, 1000] 
// 0 <= Node.val <= 5000
// root 是完全二叉树
// 0 <= val <= 5000 
// 每个测试用例最多调用 insert 和 get_root 操作 104 次


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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        root_ = root;
        if (root == nullptr) {
            use = 0;
            llen = 1;
            return;
        }
        int level = -1;
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            if (q.front().second != level) {
                use = 1;
                level = q.front().second;
            } else {
                use++;
            }
            if (q.front().first->left != nullptr) {
                q.push(make_pair(q.front().first->left, level+1));
            }
            if (q.front().first->right != nullptr) {
                q.push(make_pair(q.front().first->right, level+1));
            }
            q.pop();
        }

        llen = pow(2, level);
        if (use == llen) {
            use = 0;
            llen *= 2;
        }
    }
    
    int insert(int val) {
        // cout << llen << " " << use << endl;
        stack<int> s;
        int tmp = llen, idx = use;
        while (tmp != 1) {
            s.push(idx);
            idx /= 2;
            tmp /= 2;
        }

        TreeNode *node = root_, *parent = root_;
        
        while (node != nullptr) {
            parent = node;
            if (s.top() %2 == 0) {
                node = node->left;
            } else {
                node = node->right;
            }
            s.pop();
        }

        if (use % 2 == 0) {
            parent->left = new TreeNode(val);
        } else {
            parent->right = new TreeNode(val);
        }

        use++;
        if (use == llen) {
            use = 0;
            llen *= 2;
        }
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root_;
    }
private:
    int use, llen;
    TreeNode *root_;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
