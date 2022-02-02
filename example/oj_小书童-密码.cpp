// 小书童-密码
// “小书童”有一天登陆时忘记密码了（他没绑定邮箱 or 手机），于是便把问题抛给了神犇你。虽然忘记密码，但他还记得密码是由一串字母组成。且密码是由一串字母每个向后移动  位形成。z 的下一个字母是 a ，如此循环。他现在找到了移动前的那串字母及  ，请你求出密码。(均为小写)

// 提示
// 小书童希望通过面向对象的方法实现：

// 通过类内的私有变量存储密码相关信息
// 通过公开函数访问类内的私有变量，并进行解密操作

#include <iostream>

using namespace std;

class Password {
private:
    int _offset;
    string _err_pwd;
    string _pwd;

public:
    Password() {
        cin >> _offset >> _err_pwd;
        _offset = _offset % 26;
        for (auto ch: _err_pwd) {
            ch = (ch + _offset > 'z') ? ch + (_offset-26) : ch + _offset;
            _pwd += ch;
            
        }
    }

    ~Password() {

    }

    string get_pwd() {
        return _pwd;
    }
};

int main() {
    Password p;
    cout << p.get_pwd() << endl;

    return 0;
}
