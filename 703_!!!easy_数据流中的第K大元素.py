
# 设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。

# 请实现 KthLargest 类：

# KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
# int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。


# 优先队列 使用小顶堆
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.pq = nums
        self.k = k
        heapq.heapify(self.pq)

    def add(self, val: int) -> int:
        heapq.heappush(self.pq, val)

        while len(self.pq) > self.k:
            heapq.heappop(self.pq)

        return self.pq[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)

# 排序
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = copy.copy(k)
        self.nums = copy.copy(nums)
        self.nums.sort(reverse=True)

    def add(self, val: int) -> int:
        self.nums.append(val)
        self.nums.sort(reverse=True)
        return self.nums[self.k-1]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
