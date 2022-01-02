# 题目：
# 给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定不同的子数组为好子数组。

# （例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）

# 返回 A 中好子数组的数目。


# 1.滑动窗口
# 2. 巧妙地方： 恰好为K = 最多K个 - 最多K-1个

# 巧妙地方： 恰好为K = 最多K个 - 最多K-1个


class Solution:
    def subarraysWithKDistinct(self, A: List[int], K: int) -> int:

        return self.maxDistinct(A, K) - self.maxDistinct(A, K-1)

    def maxDistinct(self, A: List[int], K: int):
        left, right, size, count, res = 0, 0, len(A), 0, 0
        arr = [0 for i in range(0, size+1)]

        while right < size:
            if(arr[A[right]] == 0):
                count += 1
            arr[A[right]] += 1
            right += 1

            while count > K:
                arr[A[left]] -= 1
                if arr[A[left]] == 0:
                    count -= 1
                left += 1

            res += right - left

        return res
