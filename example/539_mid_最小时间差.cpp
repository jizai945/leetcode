// 539. 最小时间差
// 给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。

 

// 示例 1：

// 输入：timePoints = ["23:59","00:00"]
// 输出：1
// 示例 2：

// 输入：timePoints = ["00:00","23:59","00:00"]
// 输出：0
 

// 提示：

// 2 <= timePoints <= 2 * 104
// timePoints[i] 格式为 "HH:MM"
// 通过次数17,121提交次数28,119

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        priority_queue<int> q;

        for (auto t: timePoints) {
            int time = stoi(t.substr(0, 2))*60 + stoi(t.substr(3,5));
            q.push(time);
            q.push(time + 1440);
        }

        int ans = 1440;
        int last = q.top();
        q.pop();
        while(!q.empty()) {
            ans = min(ans, last - q.top());
            last = q.top();
            q.pop();
        }

        return ans;
    }
};

