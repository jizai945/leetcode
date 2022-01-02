# 剑指 Offer 53 - I. 在排序数组中查找数字 I
# 统计一个数字在排序数组中出现的次数。

 

# 示例 1:

# 输入: nums = [5,7,7,8,8,10], target = 8
# 输出: 2
# 示例 2:

# 输入: nums = [5,7,7,8,8,10], target = 6
# 输出: 0
 

# 限制：

# 0 <= 数组长度 <= 50000

 

# 注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

# 通过次数154,900提交次数285,906

class Solution:
    def search(self, nums: List[int], target: int) -> int:

        left = 0
        right = len(nums) - 1

        while left < right:
            mid = (left + right) // 2
            if nums[mid] == target :
                if (mid == 0 or nums[mid-1] < target):
                    left = right = mid
                    break
                else:
                    right = mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        ret = 0
        for i in range(left, len(nums)):
            if nums[i] == target:
                ret += 1
            else:
                break

        return ret


