# 810. 黑板异或游戏
# 黑板上写着一个非负整数数组 nums[i] 。Alice 和 Bob 轮流从黑板上擦掉一个数字，Alice 先手。如果擦除一个数字后，剩余的所有数字按位异或运算得出的结果等于 0 的话，当前玩家游戏失败。 (另外，如果只剩一个数字，按位异或运算得到它本身；如果无数字剩余，按位异或运算结果为 0。）

# 换种说法就是，轮到某个玩家时，如果当前黑板上所有数字按位异或运算结果等于 0，这个玩家获胜。

# 假设两个玩家每步都使用最优解，当且仅当 Alice 获胜时返回 true。

 

# 示例：

# 输入: nums = [1, 1, 2]
# 输出: false
# 解释: 
# Alice 有两个选择: 擦掉数字 1 或 2。
# 如果擦掉 1, 数组变成 [1, 2]。剩余数字按位异或得到 1 XOR 2 = 3。那么 Bob 可以擦掉任意数字，因为 Alice 会成为擦掉最后一个数字的人，她总是会输。
# 如果 Alice 擦掉 2，那么数组变成[1, 1]。剩余数字按位异或得到 1 XOR 1 = 0。Alice 仍然会输掉游戏。
 

# 提示：

# 1 <= N <= 1000
# 0 <= nums[i] <= 2^16
# 通过次数6,901提交次数9,893
# 请问您在哪类招聘中遇到此题？


# class Solution:
#     def xorGame(self, nums: List[int]) -> bool:
#         n = len(nums)
#         use = [0] * n
#         xor = 0
#         index = 0

#         for nu in nums:
#             xor ^= nu
        
#         while True:
#             tmp = index
#             for i in range(len(use)):
#                 if use[i] != 1 and xor ^ use[i] != 0:
#                     use[i] = 1
#                     index += 1
#                     break

#             if tmp == index:
#                 break


#         return True if index % 2 ==0 else False


class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        if len(nums) % 2 == 0:
            return True
        
        xorsum = reduce(xor, nums)
        return xorsum == 0
