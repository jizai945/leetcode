// 1185. 一周中的第几天
// 给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。

// 输入为三个整数：day、month 和 year，分别表示日、月、年。

// 您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}。

 

// 示例 1：

// 输入：day = 31, month = 8, year = 2019
// 输出："Saturday"
// 示例 2：

// 输入：day = 18, month = 7, year = 1999
// 输出："Sunday"
// 示例 3：

// 输入：day = 15, month = 8, year = 1993
// 输出："Sunday"
 

// 提示：

// 给出的日期一定是在 1971 到 2100 年之间的有效日期。
// 通过次数13,740提交次数22,462
// 请问您在哪类招聘中遇到此题？


class Solution {
public:
    bool isRun(int year) {
        if (year % 400 == 0)
            return true;

        if(year%4 == 0&& year%100 != 0)
            return true;

        return false;
    }

    string dayOfTheWeek(int day, int month, int year) {
        int sum_day = 0;
        vector<int> month_day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<string> day_string = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        for (int i = 1970; i < year; i++) {
            sum_day += isRun(i) ? 366 : 365;
        }

        for (int i = 0; i < month - 1; i++) {
            if (i != 1) {
                sum_day += month_day[i];
            } else {
                sum_day += isRun(year) ? 29: 28;
            }
        }

        sum_day += day;
        sum_day += 3;
        sum_day = sum_day % 7;

        return day_string[sum_day];

    }
};