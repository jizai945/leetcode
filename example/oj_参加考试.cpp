
// 参加考试
// 快期中考试了，小开很紧张！现在各大网站上有  个比赛，每个比赛的开始、结束的时间点是知道的。

// 小开认为，参加越多的比赛，考试就能考的越好（假的）

// 所以，他想知道他最多能参加几个比赛。

// 由于小开认为如果要参加一个比赛必须善始善终，而且不能同时参加  个及以上的比赛。

// 提示
// 小开希望通过面向对象的方法实现：

// 通过类内的私有变量存储考试可能的场数与考试开始与结束的时间
// 通过属性为 public 的函数访问私有变量，并计算最大可以参加的比赛数


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using P = pair<int,int>;

class Exam {
private:
    vector<P>_time;
    vector<int> _dfs;
    int exam_num;
    int _max;
public:
    Exam() {
        int s, e;
        cin >> exam_num;
        _max = 1;
        for (int i = 0; i < exam_num; i++) {
            cin >> s >> e;
            _time.emplace_back(make_pair(s, e));
            _dfs.emplace_back(0);
        }

        sort(_time.begin(), _time.end(), [](P a, P b){
            return a.second < b.second;
        });

        int temp = _time[0].second;
        for (int i = 0; i < exam_num; i++) {
            if (_time[i].first >= temp) {
                _max++;
                temp = _time[i].second;
            }
        }

    }

    ~Exam() {

    }

    int get_max() {
        return _max;
    }

};

int main() {
    Exam e;
    cout << e.get_max() << endl;

    return 0;
}