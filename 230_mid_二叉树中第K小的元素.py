# 230. 二叉搜索树中第K小的元素
# 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

   

# 示例 1：


# 输入：root = [3,1,4,null,2], k = 1
# 输出：1
# 示例 2：


# 输入：root = [5,3,6,2,4,null,null,1], k = 3
# 输出：3
 

 

# 提示：

# 树中的节点数为 n 。
# 1 <= k <= n <= 104
# 0 <= Node.val <= 104


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def get_num(self, root: Optional[TreeNode]):
        if not root:
            return
        
        self.nums.append(root.val)
        self.get_num(root.left)
        self.get_num(root.right)


    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.nums = list()
        self.get_num(root)

        self.nums.sort()
        return self.nums[k-1]