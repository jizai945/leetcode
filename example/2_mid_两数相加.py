# 2. 两数相加
# 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

# 请你将两个数相加，并以相同形式返回一个表示和的链表。

# 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 

# 示例 1：


# 输入：l1 = [2,4,3], l2 = [5,6,4]
# 输出：[7,0,8]
# 解释：342 + 465 = 807.
# 示例 2：

# 输入：l1 = [0], l2 = [0]
# 输出：[0]
# 示例 3：

# 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
# 输出：[8,9,9,9,0,0,0,1]
 

# 提示：

# 每个链表中的节点数在范围 [1, 100] 内
# 0 <= Node.val <= 9
# 题目数据保证列表表示的数字不含前导零
# 通过次数776,768提交次数1,949,320

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 == None or l2 == None:
            return None
        l1_sum, l2_sum, index = 0, 0, 0

        sum = 0
        head, last_node = None, None
        while not (sum == 0 and l1==None and l2==None):
            sum += (l1.val if l1 != None else 0) +\
                    (l2.val if l2 != None else 0)
            index += 1
            l1 = l1.next if l1 != None else None
            l2 = l2.next if l2 != None else None

            tmp = ListNode(int(sum%10))
            if last_node != None:
                last_node.next = tmp
            else:
                head = tmp
            
            last_node = tmp
            sum //= 10
            
        return head
