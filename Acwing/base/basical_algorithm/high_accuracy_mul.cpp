//
// Created by Kahiva on 2024/1/22.
//
#include <iostream>
#include <vector>
using namespace std;

//乘法的实质就是123 * 4 = 100 * 4 + 20 * 4 + 3 * 4.结果的个位诞生于最低位乘以4，十位诞生于十位乘以4加上个位进的位
//以此类推。
vector<int> mul(vector<int> &A, int b){
    vector<int> C;
    int t = 0;
    //大数每一位乘以小数，并加上低位进的位，得到的结果最后一位，为当前位的数，结果的其余位都是进位。
    for(int i = 0; i < A.size(); i++){
        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(t);

    while(C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main(){
    string a;
    int b;
    cin >> a >> b;

    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    auto C = mul(A, b);

    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;
}