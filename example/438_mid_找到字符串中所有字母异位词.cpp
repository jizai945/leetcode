// 438. 找到字符串中所有字母异位词
// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

 

// 示例 1:

// 输入: s = "cbaebabacd", p = "abc"
// 输出: [0,6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
//  示例 2:

// 输入: s = "abab", p = "ab"
// 输出: [0,1,2]
// 解释:
// 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
// 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
// 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。

class Solution {
private:
    vector<int> arr;
    unordered_map<char, int> mmap;

public:
    Solution():arr(26, 0) {}

    bool judge(void) {
        for (auto it = mmap.begin(); it != mmap.end(); it++) {
            if (arr[it->first - 'a'] != it->second) {
                return false;
            }
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.size(), m = p.size();

        if (n < m) return {};

        for (int i = 0; i < n; i++) {
        
            arr[s[i] - 'a']++;
            if (i < m) {
                mmap[p[i]]++;
            } else {
                arr[s[i - m] - 'a']--;
            }  

            if (i >= m-1) {
                if (judge()) {
                    res.push_back(i - m + 1);
                }
            }  
        }

        return res;
    }
};