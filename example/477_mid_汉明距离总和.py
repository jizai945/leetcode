# 477. 汉明距离总和
# 两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。

# 给你一个整数数组 nums，请你计算并返回 nums 中任意两个数之间汉明距离的总和。

 

# 示例 1：

# 输入：nums = [4,14,2]
# 输出：6
# 解释：在二进制表示中，4 表示为 0100 ，14 表示为 1110 ，2表示为 0010 。（这样表示是为了体现后四位之间关系）
# 所以答案为：
# HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6
# 示例 2：

# 输入：nums = [4,14,4]
# 输出：4
 

# 提示：

# 1 <= nums.length <= 105
# 0 <= nums[i] <= 109
# 通过次数36,319提交次数60,359

class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        ret = 0
        m = len(nums)

        for i in range(30):
            c = 0
            for nu in nums:
                c += (nu>>i) & 0x01
            ret += c * (m-c)


        return ret