//
// Created by Kahiva on 2024/1/18.
//
#include <iostream>
#include <vector>

using namespace std;

//比较两个数的大小
bool cmp(vector<int> &A, vector<int> &B){
    if(A.size() != B.size()) return A.size() >= B.size();

    for(int i = A.size() - 1; i >= 0; i--){
        if(A[i] > B[i]) return true;
        if(A[i] < B[i]) return false;
    }

    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B){
    vector<int> C;
    int t = 0;
    for(int i = 0; t != 0 || i < A.size() || i < B.size(); i++){
        //A位减去被借的位
        if(i < A.size()) t = A[i] - t;
        //再减B位
        if(i < B.size()) t -= B[i];
        //若位运算结果为负数，代表需要借位。+10取余为借位后的结果。若不需借位也无妨，+10取余为0。
        C.push_back((t + 10) % 10);
        //保存借位
        t = t < 0 ? 1 : 0;
    }
    //去除最高位前面的0.比如运算结果为003，则去掉00，保留结果为3.
    while(C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

int main(){
    string a, b;
    vector<int> A, B;

    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    //将小数-大数转换成-（大数-小数）
    bool a_greater = cmp(A, B);
    auto C = a_greater ? sub(A, B) : sub(B, A);

    //如果是小数-大数，则在结果前面添加负号
    if(!a_greater) printf("-");
    while(C.size() != 0){
        cout << C.back();
        C.pop_back();
    }

    return 0;
}