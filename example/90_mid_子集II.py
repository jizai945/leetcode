# 90. 子集 II
# 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

# 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

 

# 示例 1：

# 输入：nums = [1,2,2]
# 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
# 示例 2：

# 输入：nums = [0]
# 输出：[[],[0]]
 

# 提示：

# 1 <= nums.length <= 10
# -10 <= nums[i] <= 10

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ret = []
        nums.sort()

        ret.append([])

        for n in nums:
            ret_copy = ret.copy()
            for r in ret:
                tmp = r.copy()
                tmp.append(n)
                if tmp not in ret:
                    ret_copy.append(tmp)
            ret = ret_copy.copy()

        return ret