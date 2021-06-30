# 剑指 Offer 37. 序列化二叉树
# 请实现两个函数，分别用来序列化和反序列化二叉树。

# 你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

# 提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

 

# 示例：


# 输入：root = [1,2,3,null,null,4,5]
# 输出：[1,2,3,null,null,4,5]
 

# 注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        q = deque([root])
        ans = []
        while q:
            node = q.popleft()
            if not node:
                ans.append('#')
            else:
                ans.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
        while ans and ans[-1] == '#':
            ans.pop()
        return ','.join(ans)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        root_nums = data.split(',')
        if not root_nums or root_nums[0] == '#' or root_nums[0] == '':
            return None
        root_nums = deque(root_nums)
        root = TreeNode(int(root_nums.popleft()))
        left = True
        curr_nodes = deque([])
        curr_node = root
        while root_nums:
            num = root_nums.popleft()
            if left:
                left = False
                if num != '#':
                    curr_node.left = TreeNode(val=int(num))
                    curr_nodes.append(curr_node.left)
            else:
                left = True
                if num != '#':
                    curr_node.right = TreeNode(val=int(num))
                    curr_nodes.append(curr_node.right)
                curr_node = curr_nodes.popleft()
        return root

 

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
