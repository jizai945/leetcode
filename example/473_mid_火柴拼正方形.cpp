// 473. 火柴拼正方形
// 你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。

// 如果你能使这个正方形，则返回 true ，否则返回 false 。

 

// 示例 1:



// 输入: matchsticks = [1,1,2,2,2]
// 输出: true
// 解释: 能拼成一个边长为2的正方形，每边两根火柴。
// 示例 2:

// 输入: matchsticks = [3,3,3,3,4]
// 输出: false
// 解释: 不能用所有火柴拼成一个正方形。
 

// 提示:

// 1 <= matchsticks.length <= 15
// 1 <= matchsticks[i] <= 108
// 通过次数29,543提交次数69,861


class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0) {
            return false;
        }
        int len = totalLen / 4, n = matchsticks.size();
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for (int s = 1; s < (1 << n); s++) {
            for (int k = 0; k < n; k++) {
                if ((s & (1 << k)) == 0) {
                    continue;
                }
                int s1 = s & ~(1 << k);
                if (dp[s1] >= 0 && dp[s1] + matchsticks[k] <= len) {
                    dp[s] = (dp[s1] + matchsticks[k]) % len;
                    break;
                }
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};

