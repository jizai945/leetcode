// 1405. 最长快乐字符串
// 如果字符串中不含有任何 'aaa'，'bbb' 或 'ccc' 这样的字符串作为子串，那么该字符串就是一个「快乐字符串」。

// 给你三个整数 a，b ，c，请你返回 任意一个 满足下列全部条件的字符串 s：

// s 是一个尽可能长的快乐字符串。
// s 中 最多 有a 个字母 'a'、b 个字母 'b'、c 个字母 'c' 。
// s 中只含有 'a'、'b' 、'c' 三种字母。
// 如果不存在这样的字符串 s ，请返回一个空字符串 ""。

 

// 示例 1：

// 输入：a = 1, b = 1, c = 7
// 输出："ccaccbcc"
// 解释："ccbccacc" 也是一种正确答案。
// 示例 2：

// 输入：a = 2, b = 2, c = 1
// 输出："aabbc"
// 示例 3：

// 输入：a = 7, b = 1, c = 0
// 输出："aabaa"
// 解释：这是该测试用例的唯一正确答案。
 

// 提示：

// 0 <= a, b, c <= 100
// a + b + c > 0
// 通过次数15,709提交次数25,965

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        int last_ch = -1;
        while (a != 0 || b != 0 || c != 0) {
            int m = max(a, max(b, c));
            if (m == a) {
                if (last_ch == 1) {
                    if (b == 0 && c == 0) return ans;
                    if (a > b+c) {
                        if (b > c) {
                            last_ch = 2;
                            ans += 'b';
                            b -= 1;
                        } else {
                            last_ch = 3;
                            ans += 'c';
                            c -= 1;
                        }
                    } else {
                        if (b > c) {
                            last_ch = 2;
                            ans += (b ==1 ? "b" : "bb");
                            b -= b == 1 ? 1: 2;
                        } else {
                            last_ch = 3;
                            ans += (c ==1 ? "c" : "cc");
                            c -= c == 1? 1: 2;
                        }
                    }
                } else {
                    last_ch = 1;
                    ans += (a == 1 ? "a": "aa");
                    a -= a == 1? 1 : 2;
                }
            } else if (m == b) {
                if (last_ch == 2) {
                    if (a == 0 && c == 0) return ans;
                    if (b > a+c) {
                        if (a > c) {
                            last_ch = 1;
                            ans += 'a';
                            a -= 1;
                        } else {
                            last_ch = 3;
                            ans += 'c';
                            c -= 1;
                        }
                    } else {
                        if (a > c) {
                            last_ch = 1;
                            ans += (a ==1 ? "a" : "aa");
                            a -= a == 1 ? 1: 2;
                        } else {
                            last_ch = 3;
                            ans += (c ==1 ? "c" : "cc");
                            c -= c == 1? 1: 2;
                        }
                    }
                } else {
                    last_ch = 2;
                    ans += (b == 1 ? "b": "bb");
                    b -= b == 1? 1 : 2;
                }
            } else if (m == c) {
                if (last_ch == 3) {
                    if (a == 0 && b == 0) return ans;
                    if (c > a+b) {
                        if (a > b) {
                            last_ch = 1;
                            ans += 'a';
                            a -= 1;
                        } else {
                            last_ch = 2;
                            ans += 'b';
                            b -= 1;
                        }
                    } else {
                        if (a > b) {
                            last_ch = 1;
                            ans += (a ==1 ? "a" : "aa");
                            a -= a == 1 ? 1: 2;
                        } else {
                            last_ch = 2;
                            ans += (b ==1 ? "b" : "bb");
                            b -= b == 1? 1: 2;
                        }
                    }
                } else {
                    last_ch = 3;
                    ans += (c == 1 ? "c": "cc");
                    c -= c == 1? 1 : 2;
                }
            }
        }

        return ans;
    }
};