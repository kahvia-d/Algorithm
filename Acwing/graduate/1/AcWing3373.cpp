//
// Created by Kahiva on 2023/10/15.
//
//https://www.acwing.com/problem/content/3376/
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

vector<int> div(vector<int> a,const int& b){
    vector<int> divResult;
    for (int i = a.size()-1, left=0; i >=0 ; i--) {
        //当前被除数=上一位被除数除以二的余数*10+当前位
        left=left*10+a[i];
        //当前被除数/b的结果
        divResult.push_back(left/b);
        //当前被除数除以b的余数
        left=left%b;
    }

    //将其变为倒序的结果
    reverse(divResult.begin(), divResult.end());
    //删除最后面的几个0（0来自于每一位被除数除以除数的结果）
    //检查vector的大小是有必要的。vector为空时调用back函数会导致内存溢出。
    while (divResult.size()&&divResult.back()==0){
        divResult.pop_back();
    }
    //返回高精度十进制数除以b的结果（传进来倒序，出去也是倒序）
    return divResult;
}

int main(){
    string s;

    while (cin>>s){
        vector<int> a;
        vector<int> result;
        for (int i = 0; i < s.length(); ++i) {
            //数字字符减'0'转换成int数字，逆序存储。
            a.push_back(s[s.length()-1-i]-'0');
        }
        while (a.size()){
            //短除法直到被除数为0为止
            result.push_back(a[0]%2);
            a=div(a,2);
        }
        //恢复正常顺序，高位排前面，低位排后面
        reverse(result.begin(), result.end());
        for (const auto &item: result){
            cout<<item;
        }
        cout<<endl;
    }


    return 0;
}

