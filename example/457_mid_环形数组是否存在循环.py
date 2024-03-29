# 457. 环形数组是否存在循环
# 存在一个不含 0 的 环形 数组 nums ，每个 nums[i] 都表示位于下标 i 的角色应该向前或向后移动的下标个数：

# 如果 nums[i] 是正数，向前 移动 nums[i] 步
# 如果 nums[i] 是负数，向后 移动 nums[i] 步
# 因为数组是 环形 的，所以可以假设从最后一个元素向前移动一步会到达第一个元素，而第一个元素向后移动一步会到达最后一个元素。

# 数组中的 循环 由长度为 k 的下标序列 seq ：

# 遵循上述移动规则将导致重复下标序列 seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
# 所有 nums[seq[j]] 应当不是 全正 就是 全负
# k > 1
# 如果 nums 中存在循环，返回 true ；否则，返回 false 。

 

# 示例 1：

# 输入：nums = [2,-1,1,2,2]
# 输出：true
# 解释：存在循环，按下标 0 -> 2 -> 3 -> 0 。循环长度为 3 。
# 示例 2：

# 输入：nums = [-1,2]
# 输出：false
# 解释：按下标 1 -> 1 -> 1 ... 的运动无法构成循环，因为循环的长度为 1 。根据定义，循环的长度必须大于 1 。
# 示例 3:

# 输入：nums = [-2,1,-1,-2,-2]
# 输出：false
# 解释：按下标 1 -> 2 -> 1 -> ... 的运动无法构成循环，因为 nums[1] 是正数，而 nums[2] 是负数。
# 所有 nums[seq[j]] 应当不是全正就是全负。

class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        m = len(nums)
        

        def go(idx, target, sign):
            if sign != 0 and( (nums[idx] > 0 and sign != 1) or (nums[idx] < 0 and sign != 2) ):
                flag[idx] = 1
                return False

            if flag[idx] == 1:

                    return (nums[idx] + idx) % m != idx and (sign != 0)
            else:
                flag[idx] = 1
                return go((nums[idx] + idx) % m, target, 1 if nums[idx] > 0 else 2)

        for i in range(m):
            flag = [0] * m
            if go(i, i, 0) == True:
                return True
        
        return False
