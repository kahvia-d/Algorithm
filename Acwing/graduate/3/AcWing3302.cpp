//
// Created by Kahiva on 2023/10/24.
//
//https://www.acwing.com/problem/content/3305/

#include "iostream"
#include "stack"
#include "cstring"
#include "unordered_map"

using namespace std;

stack<char> op;
stack<int> nums;
unordered_map<char, int> pr={
        {
            '+',1
        },
        {
            '-',1
        },
        {
            '*',2
        },
        {
            '/',2
        },
};

bool isNum(char c){
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

void calculate(){
    int b = nums.top();
    nums.pop();
    int a = nums.top();
    nums.pop();
    char c = op.top();
    op.pop();

    if(c == '+'){
        nums.push(a + b);
    }else if(c == '-'){
        nums.push(a - b);
    }else if(c == '*'){
        nums.push(a * b);
    }else{
        nums.push(a / b);
    }

}

int main(){
    string s;
    cin>>s;
    for (int i = 0; i < s.length(); ++i) {
        //如果是数字字符，则将这一串数字提取出来，压入数字栈中
        if(isNum(s[i])){
            int number = s[i]-'0';
            int j;
            for (j = i + 1; isNum(s[j]); j++){
                number = number * 10 + s[j] - '0';
            }
            nums.push(number);
            i = j - 1;
        }else if (s[i] == '('){
            //如果是左括号则直接压入符号栈
            op.push(s[i]);
        }else if (s[i] == ')'){
            //如果是右括号则进行符号栈中的操作直到符号栈栈顶为左括号
            while (op.top() != '(') calculate();
            //删掉栈顶的左括号
            op.pop();
        }else{
            //如果是加减乘除，且栈顶符号优先级大于当前待压入符号，则执行栈顶的符号操作，直到栈顶为左括号，或者栈顶的优先级小于当前待压入符号
            while (op.size() && op.top()!='(' && pr[op.top()] >= pr[s[i]]){
                calculate();
            }
            //压入待压入操作符
            op.push(s[i]);
        }
    }
    //没有可压入的数字和符号了，就执行符号栈中的操作
    while (op.size()) calculate();
    //执行完毕后，数字栈中预留的数字为最终结果
    cout<<nums.top();

    return 0;
}