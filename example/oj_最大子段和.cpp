// 最大子段和
// 给出一段序列，选出其中连续且非空的一段使得这段和最大。

// 提示
// 希望聪明的你通过面向对象的方法实现：

// 通过类内的私有变量存储这段子串
// 通过属性为 public 的函数访问类内的私有变量并计算最大子段和

#include <iostream>
#include <vector>

using namespace std;

class LineSum {
private:
    vector<int> _buf;
    int _max;

public:
    LineSum() {
        int s, t;
        cin >> s;
        _max = INT32_MIN;
        int line_min = 0, line_max = 0, lin_sum = 0;

        for (int i = 0; i < s; i++) {
            cin >> t;
            _buf.emplace_back(t);
            lin_sum += t;
            _max = max(lin_sum - line_min, _max);

            line_min = min(line_min, lin_sum);
            line_max = max(line_max, lin_sum);
        }
    }

    int get_max_sum() {
        return _max;
    }

};

int main() {

    LineSum l;
    cout << l.get_max_sum() << endl;

    return 0;
}
