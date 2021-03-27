# 61. 旋转链表
# 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

 

# 示例 1：


# 输入：head = [1,2,3,4,5], k = 2
# 输出：[4,5,1,2,3]
# 示例 2：


# 输入：head = [0,1,2], k = 4
# 输出：[2,0,1]


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head == None:
            return None

        list_head = []
        node = head

        while node != None:
            list_head.append(node)
            node = node.next

        k %= len(list_head)

        ret = list_head[-k]
        list_head[-k-1].next = None
        if k != 0:
            list_head[-1].next = head

        return ret