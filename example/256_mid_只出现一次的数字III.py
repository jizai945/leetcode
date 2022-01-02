# 260. 只出现一次的数字 III
# 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

 

# 进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

 

# 示例 1：

# 输入：nums = [1,2,1,3,2,5]
# 输出：[3,5]
# 解释：[5, 3] 也是有效的答案。
# 示例 2：

# 输入：nums = [-1,0]
# 输出：[-1,0]
# 示例 3：

# 输入：nums = [0,1]
# 输出：[1,0]
# 提示：

# 2 <= nums.length <= 3 * 104
# -231 <= nums[i] <= 231 - 1
# 除两个只出现一次的整数外，nums 中的其他数字都出现两次
# 通过次数72,153提交次数97,618

# class Solution:
#     def singleNumber(self, nums: List[int]) -> List[int]:
#         map = dict()
#         for n in nums:
#             if n not in map:
#                 map[n] = 1
#             else:
#                 map[n] += 1

#         ans = list()
#         for key, value in map.items():
#             if value == 1:
#                 ans.append(key)

#         return ans
            

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xorsum = 0
        for num in nums:
            # 出现两次的都会被异或掉， 最终是出现一次的两个数相互异或
            xorsum ^= num
        
        # 得到不同的最低位
        lsb = xorsum & (-xorsum)
        type1 = type2 = 0
        for num in nums:
            # 与最低不同位异或两个数会被分为两组
            if num & lsb:
                type1 ^= num
            else:
                type2 ^= num
        
        return [type1, type2]
