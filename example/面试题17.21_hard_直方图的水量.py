# 面试题 17.21. 直方图的水量
# 给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为 1。



# 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的直方图，在这种情况下，可以接 6 个单位的水（蓝色部分表示水）。 感谢 Marcos 贡献此图。

# 示例:

# 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
# 输出: 6
# 通过次数36,404提交次数57,563

# class Solution:
#     def trap(self, height: List[int]) -> int:
#         if len(height) < 2:
#             return 0

#         ret = 0

#         for i  in range(1, len(height)-1):
#             k = max(height[0:i+1])
#             n = max(height[i:])

#             if k > height[i] and n > height[i]:
#                 ret += min(k, n) - height[i]

#         return ret


# dp
class Solution:
    def trap(self, height: List[int]) -> int:
        N = len(height)
        if N < 2:
            return 0

        l_dp, r_dp = [0] * N, [0] * N
        l_dp[0] = height[0]
        r_dp[-1] = height[-1]
        ret = 0

        # 右最大的dp
        for i in range(N-2, -1, -1):
            r_dp[i] = max(r_dp[i+1], height[i])

        # 左最大的dp，顺便求水量
        for i in range(1, N):
            l_dp[i] = max(l_dp[i-1], height[i])

            ret += 0 if height[i] == l_dp[i] or height[i] == r_dp[i] else (min(l_dp[i], r_dp[i]) - height[i])

        return ret
