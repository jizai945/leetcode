// 504. 七进制数
// 给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。

 

// 示例 1:

// 输入: num = 100
// 输出: "202"
// 示例 2:

// 输入: num = -7
// 输出: "-10"
 

// 提示：

// -107 <= num <= 107

class Solution {
public:
    string convertToBase7(int num) {
        if (!num) return string("0");
        vector<int> buf;

        int tmp = max(num, 0-num);
        while (tmp) {
            buf.emplace_back(tmp%7);
            tmp = tmp / 7;
        }
        string ans;
        if (num < 0) {
            ans += '-';
        }

        for (int i = buf.size()-1; i>=0; --i) {
            ans += to_string(buf[i]);
        }
        return ans;

    }
};
