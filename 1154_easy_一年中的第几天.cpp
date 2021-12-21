// 1154. 一年中的第几天
// 给你一个字符串 date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 日期。请你计算并返回该日期是当年的第几天。

// 通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。

 

// 示例 1：

// 输入：date = "2019-01-09"
// 输出：9
// 示例 2：

// 输入：date = "2019-02-10"
// 输出：41
// 示例 3：

// 输入：date = "2003-03-01"
// 输出：60
// 示例 4：

// 输入：date = "2004-03-01"
// 输出：61
 

// 提示：

// date.length == 10
// date[4] == date[7] == '-'，其他的 date[i] 都是数字
// date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日
// 通过次数39,684提交次数61,361

class Solution {
public:
    bool isRun(int year) {
        if(year%400==0)
            return true;
        else {
            if(year%4==0&&year%100!=0)
                return true;
            else
                return false;
        }
    }

    int dayOfYear(string date) {
        int idx = date.find("-", 0);
        int year = atoi(date.substr(0, idx).c_str());
        string sub_str = date.substr(idx+1);
        idx = sub_str.find("-", 0);
        int month = atoi(sub_str.substr(0, idx).c_str());
        int day = atoi(sub_str.substr(idx+1).c_str());

        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int res = 0;
        for (int i = 1; i < month; i++) {
            if (i == 2) {
                if (isRun(year)) {
                    res += 29;
                } else {
                    res += 28;
                }
            } else {
                res += days[i-1];
            }
        }

        res += day;

        // cout << year << endl;
        // cout << year << month << day << endl;

        return res;
    }
};