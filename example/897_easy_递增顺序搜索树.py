# 897. 递增顺序搜索树
# 给你一棵二叉搜索树，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。

 

# 示例 1：


# 输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
# 输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
# 示例 2：


# 输入：root = [5,1,7]
# 输出：[1,null,5,null,7]
 

# 提示：

# 树中节点数的取值范围是 [1, 100]
# 0 <= Node.val <= 1000
# 通过次数49,744提交次数66,616


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        self.list = []
        
        ret = TreeNode(-1)
        self.inOrd(root)

        ret.val = self.list[0]
        last_tmp = ret
        for li in self.list[1:]:
            tmp = TreeNode(li)
            last_tmp.right = tmp
            last_tmp = tmp

        return ret

    
    def inOrd(self, root:TreeNode):
        if root == None:
            return 
        
        self.inOrd(root.left)
        self.list.append(root.val)
        self.inOrd(root.right)