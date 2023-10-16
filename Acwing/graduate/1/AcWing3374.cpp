//
// Created by Kahiva on 2023/10/16.
//
//https://www.acwing.com/problem/content/3377/

#include"iostream"
#include "algorithm"
#include "vector"

using namespace std;

vector<int> div(const vector<int>& V,const int& a,const int& b){
    vector<int> result;
    int left=0;
    for (int i = V.size()-1; i >=0 ; i--) {
        //当前位的被除数等于上一位的余数乘以进制b的进位数+当前位数。
        //即，将a进制的数转换为10进制再进行除法和取余（因为c语言中的除法和取余都是基于十进制）。
        left=left*a+V[i];
        //当前位除法的结果
        result.push_back(left/b);
        //当前位除法的余数
        left=left%b;
    }
    //如4进制的103向5进制转换，第一次除法结果应当是003.将其反转后去0；
    reverse(result.begin(),result.end());
    while(result.size()&&result[result.size()-1]==0)
        result.pop_back();
    //余数存在容器最后面
    result.push_back(left);
    return  result;
}

int main(){
    //a进制的c转换成b进制
    int a,b;
    string s;
    cin>>a>>b>>s;

    vector<int> V;
    for (int i = 0; i < s.size(); ++i) {
        char c=s[s.size()-1-i];
        if(c>='A'){
            //如果传入的有字母，则转换成对应的数。如A就是10，B是11.
            V.push_back(c-'A'+10);
        }else{
            V.push_back(c-'0');
        }
    }

    vector<int> resp;
    //短除法
    while(V.size()){
        //被除数除以要转的进制数
        V=div(V,a,b);
        //保存余数
        resp.push_back(V[V.size()-1]);
        //删除余数部分。之后V变成下一次的被除数。
        V.pop_back();
    }

    //反转为正序输出
    reverse(resp.begin(),resp.end());
    for (const auto &item: resp){
        if(item>=10){
            //大于10的数转换成对应的字母输出
            cout<<(char)(item-10+'a');
        }
        else
            //普通的数直接输出
            cout<<item;
    }

}