// 720. 词典中最长的单词
// 给出一个字符串数组 words 组成的一本英语词典。返回 words 中最长的一个单词，该单词是由 words 词典中其他单词逐步添加一个字母组成。

// 若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。

 

// 示例 1：

// 输入：words = ["w","wo","wor","worl", "world"]
// 输出："world"
// 解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
// 示例 2：

// 输入：words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
// 输出："apple"
// 解释："apply" 和 "apple" 都能由词典中的单词组成。但是 "apple" 的字典序小于 "apply" 
 

// 提示：

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 30
// 所有输入的字符串 words[i] 都只包含小写字母。
// 通过

class Solution {
public:
    bool previewSon(string str, unordered_map<string, int> &mp) {
        if (str.size() == 1 || mp[str] == 1) return true;
        
        if (mp[str] == -1 || mp.count(str.substr(0, str.size()-1)) == 0) {
            mp[str] = -1;
            return false;
        }

        if ( previewSon(str.substr(0, str.size()-1), mp) ) {
            mp[str] = 1;
            return true;
        } else {
            mp[str] = -1;
            return false;
        }
    }

    string longestWord(vector<string>& words) {
        string ans;
        int maxLen = 0;
        unordered_map<string, int>mp;

        for (string str: words) {
            mp[str] = 0;
        }

        for (auto str: words) {
            if (str.size() == 1) {
                mp[str] = 1;
                if (maxLen == 0) {
                    ans = str;
                    maxLen = 1;
                } else if (maxLen == 1 && str < ans) {
                    ans = str;
                }
            } else if ( str.size() > maxLen || (str.size() == maxLen && str < ans) ) {
                if (previewSon(str, mp)) {
                    ans = str;
                    maxLen = str.size();
                }
            }
            
        }


        return ans;
    }
};

