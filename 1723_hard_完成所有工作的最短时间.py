# 1723. 完成所有工作的最短时间
# 给你一个整数数组 jobs ，其中 jobs[i] 是完成第 i 项工作要花费的时间。

# 请你将这些工作分配给 k 位工人。所有工作都应该分配给工人，且每项工作只能分配给一位工人。工人的 工作时间 是完成分配给他们的所有工作花费时间的总和。请你设计一套最佳的工作分配方案，使工人的 最大工作时间 得以 最小化 。

# 返回分配方案中尽可能 最小 的 最大工作时间 。

 

# 示例 1：

# 输入：jobs = [3,2,3], k = 3
# 输出：3
# 解释：给每位工人分配一项工作，最大工作时间是 3 。
# 示例 2：

# 输入：jobs = [1,2,4,7,8], k = 2
# 输出：11
# 解释：按下述方式分配工作：
# 1 号工人：1、2、8（工作时间 = 1 + 2 + 8 = 11）
# 2 号工人：4、7（工作时间 = 4 + 7 = 11）
# 最大工作时间是 11 。
 

# 提示：

# 1 <= k <= jobs.length <= 12
# 1 <= jobs[i] <= 107
# 通过次数17,371提交次数34,651



# 自己做的会超时
# class Solution:
#     def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
#         self.A = len(jobs)
#         if self.A <= k:
#             return max(jobs)

#         sum1 = [[0 for i in range(k)] for j in range(self.A+1)]      
#         T =  self.dfs(jobs, k, sum1, 0)
#         return T

#     def dfs(self, jobs: List[int], k: int, sum1, index):

#         if index >= self.A:
#             return max(sum1[-1])

#         ret = [0] * k
#         res = sys.maxsize
#         for kk in range(k):
#             for j in range(k):
#                 if j == kk:
#                     sum1[index+1][j] = sum1[index][j] + jobs[index]
#                 else:
#                     sum1[index+1][j] = sum1[index][j]
                
#             for j in range(k):  
#                 ret[j] = self.dfs(jobs, k, sum1, index+1)
                
#             res = min(res, max(ret))
        
#         return res


class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:

        def check(limit):
            # 剪枝：排序后，大的先拿出来试，如果方案不行，失败得更快
            arr = sorted(jobs)

            groups = [0] * k
            # 分成K 组，看看在这个limit 下 能不能安排完工作
            if backtrace(arr, groups, limit):
                return True
            else:
                return False


        def backtrace(arr, groups, limit):
            # 尝试每种可能性
            #print(arr, groups, limit)
            if not arr: return True #分完，则方案可行
            v = arr.pop()

            for i in range(len(groups)):
                if groups[i] + v <= limit:
                    groups[i] += v
                    if backtrace(arr, groups, limit):
                        return True
                    groups[i] -= v

                    # 剪枝，如果这个工人没分到活，那别人肯定得多干活了，那最后的结果必然不是最小的最大值，就不用继续试了。 
                    if groups[i] ==0:
                        break

            arr.append(v)

            return False
        
        #每个人承担的工作的上限，最小为，job 里面的最大值，最大为 jobs 之和
        l, r  = max(jobs), sum(jobs)

        while l < r:
            mid = (l + r)//2

            if check(mid):
                r = mid
            else:
                l = mid + 1

        return l
