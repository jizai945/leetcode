// 464. 我能赢吗
// 在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和 达到或超过  100 的玩家，即为胜者。

// 如果我们将游戏规则改为 “玩家 不能 重复使用整数” 呢？

// 例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。

// 给定两个整数 maxChoosableInteger （整数池中可选择的最大数）和 desiredTotal（累计和），若先出手的玩家是否能稳赢则返回 true ，否则返回 false 。假设两位玩家游戏时都表现 最佳 。

 

// 示例 1：

// 输入：maxChoosableInteger = 10, desiredTotal = 11
// 输出：false
// 解释：
// 无论第一个玩家选择哪个整数，他都会失败。
// 第一个玩家可以选择从 1 到 10 的整数。
// 如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
// 第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
// 同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。
// 示例 2:

// 输入：maxChoosableInteger = 10, desiredTotal = 0
// 输出：true
// 示例 3:

// 输入：maxChoosableInteger = 10, desiredTotal = 1
// 输出：true
 

// 提示:

// 1 <= maxChoosableInteger <= 20
// 0 <= desiredTotal <= 300

class Solution {
private:
    unordered_map<int, bool> mp; // 保存状态，用于状态压缩

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger)*maxChoosableInteger / 2  < desiredTotal) return false;

        return dfs(maxChoosableInteger, desiredTotal, 0, 0);
    }

    // useNumber每个位表示当前的数字是否使用
    bool dfs(int maxChoosableInteger, int desiredTotal, int useNumber, int currentSums) {
        if (mp.count(useNumber) == 0) {
            bool res = false;
            for (int i = 1; i <= maxChoosableInteger; i++) {
                if ( (useNumber & (1 << i)) != 0) continue;
                if (currentSums + i >= desiredTotal) {
                    res = true;
                    break;
                }

                if (!dfs(maxChoosableInteger, desiredTotal, useNumber | (1<<i), currentSums+i)) {
                    res = true;
                    break;
                }
            }
            mp[useNumber] = res;
        }

        return mp[useNumber];
    }

};

