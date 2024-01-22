//
// Created by Kahiva on 2024/1/22.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> div(vector<int> A, int b){
    vector<int> C;
    int t = 0;

    //从大数高位开始除
    for(int i = A.size() - 1; i >= 0; i--){
        t = t * 10 + A[i];
        //能除就除
        if(t >= b) C.push_back(t / b), t = t % b;
        //不能除，商就置零
        else C.push_back(0);
    }

    //翻转数组，并去除高位0。
    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    //翻转回来，把最终的余数补在数组最后面
    reverse(C.begin(), C.end());
    C.push_back(t);

    return C;
}

int main(){
    string a;
    int b;
    vector<int> A;

    cin >> a >> b;

    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    auto C = div(A, b);

    for(int i = 0; i < C.size() - 1; i++) printf("%d", C[i]);

    printf("\n%d", C.back());

    return 0;
}