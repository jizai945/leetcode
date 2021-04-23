# 368. 最大整除子集
# 给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i], answer[j]) 都应当满足：
# answer[i] % answer[j] == 0 ，或
# answer[j] % answer[i] == 0
# 如果存在多个有效解子集，返回其中任何一个均可。

 

# 示例 1：

# 输入：nums = [1,2,3]
# 输出：[1,2]
# 解释：[1,3] 也会被视为正确答案。
# 示例 2：

# 输入：nums = [1,2,4,8]
# 输出：[1,2,4,8]
 

# 提示：

# 1 <= nums.length <= 1000
# 1 <= nums[i] <= 2 * 109
# nums 中的所有整数 互不相同
# 通过次数33,152提交次数73,667


class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        A = len(nums)
        dp = [1] * A
        max_dp = 1
        nums.sort()

        for i in range(1, A):
            for j in range(i-1, -1, -1):
                if nums[i] % nums[j] == 0 or nums[j] % nums[i] == 0:
                    if (dp[j]+1 > dp[i]):
                        dp[i] = dp[j] + 1
                        max_dp = max(max_dp, dp[i])
            
        ret, index, tmp = [], max_dp, -1

        for i in range(A-1, -1, -1):
            if dp[i] == index :
                if tmp == -1 or tmp % nums[i] == 0 or nums[i] % tmp == 0:
                    tmp = nums[i]
                    index -= 1
                    ret.append(nums[i])

        return ret