# 83. 删除排序链表中的重复元素
# 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。

# 返回同样按升序排列的结果链表。

 

# 示例 1：


# 输入：head = [1,1,2]
# 输出：[1,2]
# 示例 2：


# 输入：head = [1,1,2,3,3]
# 输出：[1,2,3]

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None:
            return None

        last_val = head.val
        node = head.next
        ret = ListNode(last_val)
        ret_node = ret

        while node != None:
            if node.val == last_val:
                pass
            else:               
                tmp = ListNode(node.val)
                last_val = node.val
                ret_node.next = tmp
                ret_node = ret_node.next
            
            node = node.next

        
        return ret