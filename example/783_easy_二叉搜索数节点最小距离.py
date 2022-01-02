
# 783. 二叉搜索树节点最小距离
# 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

# 注意：本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同

 

# 示例 1：


# 输入：root = [4,2,6,1,3]
# 输出：1
# 示例 2：


# 输入：root = [1,0,48,null,null,12,49]
# 输出：1
 

# 提示：

# 树中节点数目在范围 [2, 100] 内
# 0 <= Node.val <= 105

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treePre(self, node, my_list, min_ret):
        if node.left != None:
            self.treePre(node.left, my_list, min_ret)

        my_list.append(node.val)
        if (len(my_list) > 1):
            min_ret[0] = min(min_ret[0], my_list[-1] - my_list[-2])

        if node.right != None:
            self.treePre(node.right, my_list, min_ret)

    def minDiffInBST(self, root: TreeNode) -> int:
        my_list, min_ret = [], [100000]

        self.treePre(root, my_list, min_ret)

        return min_ret[0]