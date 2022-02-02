// 梦中的统计
// 小开的大脑反应灵敏，仿佛真实地看到了她数过的一个又一个数。她开始注意每一个数码()：每一个数码在计数的过程中出现过多少次？

// 给出两个整数  和  ()，求每一个数码出现了多少次。

// 例如考虑序列 : , , , , , , , ,  。统计后发现：

//  出现了 1次，
//  出现了 10次，
//  出现了 2次，
//  出现了 9次，
//  出现了 1次，
//  出现了 1次,
//  出现了 1次，
//  出现了 1次，
//  出现了 0次，
//  出现了 1次。
// 题目要求
// 小开最近也学习了类，希望你能通过封装的类来实现这个统计方法。

// 通过类内的私有变量来存储数据范围
// 通过属性为 public 的函数访问私有变量并统计


#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Count {
private:
    int _start;
    int _end;
    int _count[10];
public:
    Count() {
        cin >> _start >> _end;
        memset(_count, 0, sizeof(_count)*sizeof(int));
        for (int i = _start; i <= _end; i++) {
            int num = i;
            while (num) {
                _count[num%10]++;
                num /= 10;
            }
        }
    }
    ~Count() {

    }

    void get_num_count() {
        for (int i = 0; i < 10; i++) {
            cout << _count[i] << (i == 9 ? "" : " ");
            // if (i >= 10) break;
        }
        cout << endl;
    }
};

int main() {
    Count a;
    a.get_num_count();

    return 0;
}