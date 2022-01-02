# 82. 删除排序链表中的重复元素 II
# 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。

# 返回同样按升序排列的结果链表。

 

# 示例 1：


# 输入：head = [1,2,3,3,4,4,5]
# 输出：[1,2,5]
# 示例 2：


# 输入：head = [1,1,1,2,3]
# 输出：[2,3]
 

# 提示：

# 链表中节点数目在范围 [0, 300] 内
# -100 <= Node.val <= 100
# 题目数据保证链表已经按升序排列

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        
        node = head
        last_node =  None
        ret = None
        ret_node = None

        while node != None:
            if ( last_node == None or (last_node != None and node.val != last_node.val)) and ((node.next == None) or (node.next != None and node.val != node.next.val)):
                if ret == None:
                    ret = ListNode(node.val)
                    ret_node = ret
                else:
                    tmp = ListNode(node.val)
                    ret_node.next = tmp
                    ret_node = ret_node.next

            last_node = node
            node = node.next
      

        return ret