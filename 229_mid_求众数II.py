# 229. 求众数 II
# 给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

 

 

# 示例 1：

# 输入：[3,2,3]
# 输出：[3]
# 示例 2：

# 输入：nums = [1]
# 输出：[1]
# 示例 3：

# 输入：[1,1,1,3,3,2,2,2]
# 输出：[1,2]
 

# 提示：

# 1 <= nums.length <= 5 * 104
# -109 <= nums[i] <= 109
 

# 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。

# 通过次数64,325提交次数121,635

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        map = {}
        res = []
        size = len(nums)

        for n in nums:
            if n in map:
                map[n] += 1
            else:
                map[n] = 1

        for key, value in map.items():
            if value > (size / 3):
                res.append(key)

        return res