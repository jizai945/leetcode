# 203. 移除链表元素
# 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 

# 示例 1：


# 输入：head = [1,2,6,3,4,5,6], val = 6
# 输出：[1,2,3,4,5]
# 示例 2：

# 输入：head = [], val = 1
# 输出：[]
# 示例 3：

# 输入：head = [7,7,7,7], val = 7
# 输出：[]
 

# 提示：

# 列表中的节点在范围 [0, 104] 内
# 1 <= Node.val <= 50
# 0 <= k <= 50
# 通过次数183,727提交次数367,712

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        tmp = head
        node = ret = None


        while tmp != None:
            if tmp.val == val:
                pass
            elif node == None:
                node = ListNode(tmp.val)
                ret = node
            else:
                node.next = ListNode(tmp.val)
                node = node.next
                
            tmp = tmp.next

        return ret