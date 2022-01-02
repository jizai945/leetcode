# 740. 删除并获得点数
# 给你一个整数数组 nums ，你可以对它进行一些操作。

# 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除每个等于 nums[i] - 1 或 nums[i] + 1 的元素。

# 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。

 

# 示例 1：

# 输入：nums = [3,4,2]
# 输出：6
# 解释：
# 删除 4 获得 4 个点数，因此 3 也被删除。
# 之后，删除 2 获得 2 个点数。总共获得 6 个点数。
# 示例 2：

# 输入：nums = [2,2,3,3,3,4]
# 输出：9
# 解释：
# 删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
# 之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
# 总共获得 9 个点数。
 


class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        
        A = len(nums)
        dp = b = [[0 for i in range(2)] for i in range(A+1)]  
        nums.sort()
        ret = 0


        for i in range(A):
            if i != 0 and nums[i] == nums[i-1]:
                dp[i+1][0] = dp[i][0]
                dp[i+1][1] = dp[i][1] + nums[i]
                continue
            else:
                dp[i+1][0] = max(dp[i][0], dp[i][1])

            if i == 0 or nums[i] == nums[i-1] + 1:
                dp[i+1][1] = dp[i][0] + nums[i]
            else:
                dp[i+1][1] = max(dp[i][0], dp[i][1]) + nums[i]



        return max(dp[-1][0], dp[-1][1])





