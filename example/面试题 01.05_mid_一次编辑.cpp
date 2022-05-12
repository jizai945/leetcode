// 面试题 01.05. 一次编辑
// 字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

 

// 示例 1:

// 输入: 
// first = "pale"
// second = "ple"
// 输出: True
 

// 示例 2:

// 输入: 
// first = "pales"
// second = "pal"
// 输出: False

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m = first.size(), n = second.size();
        int use = 1;

        if (abs(m - n) > 1) return false;
        if (m == n) {
            for (int i = 0; i < m; i++) {
                if (first[i] != second[i] ) {
                    if (use == 0) return false;
                    use--;
                }
            }
        } else {
            string shortStr, longStr;
            int len;
            if (m < n) {
                shortStr = first;
                longStr = second;
                len = n;
            } else {
                shortStr = second;
                longStr = first;
                len = m;
            }

            for (int i = 0; i < len-1; i++) {
                if (shortStr[i] != longStr[i]) {
                    if (use == 0) return false;
                    shortStr = shortStr.substr(0, i) + longStr[i] + shortStr.substr(i);
                    use--;
                }
            }
            if (! (use || (use == 0 && shortStr[len-1] == longStr[len-1])) ) return false; 
        }

        return true;
    }
};
