# 483. 最小好进制
# 对于给定的整数 n, 如果n的k（k>=2）进制数的所有数位全为1，则称 k（k>=2）是 n 的一个好进制。

# 以字符串的形式给出 n, 以字符串的形式返回 n 的最小好进制。

 

# 示例 1：

# 输入："13"
# 输出："3"
# 解释：13 的 3 进制是 111。
# 示例 2：

# 输入："4681"
# 输出："8"
# 解释：4681 的 8 进制是 11111。
# 示例 3：

# 输入："1000000000000000000"
# 输出："999999999999999999"
# 解释：1000000000000000000 的 999999999999999999 进制是 11。
 

# 提示：

# n的取值范围是 [3, 10^18]。
# 输入总是有效且没有前导 0。
 

# 通过次数12,460提交次数21,565


class Solution:
    def smallestGoodBase(self, n: str) -> str:
        num = int(n)

        for i in range(num.bit_length(), 2, -1):
            # k^0 + k^1 + …… + k^(i-1) = n -- 通过二分法计算 k
            # kn - n = k^i - 1
            left, right = 2, num - 1
            while left <= right:
                mid = (left + right) // 2
                s = mid * num - num - pow(mid, i) + 1
                if s == 0:
                    return str(mid)
                elif s > 0:
                    left = mid + 1
                else:
                    right = mid - 1
        return str(num - 1)
