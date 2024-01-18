//
// Created by Kahiva on 2024/1/18.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B){
    vector<int> C;
    int t = 0;
    for(int i = 0; t != 0 || i < A.size() || i < B.size(); i++){
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t = t >= 10 ? 1 : 0;
    }

    return C;
}

int main(){
    string a, b;
    vector<int> A, B;

    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    auto C = add(A, B);


    while(C.size() != 0){
        cout << C.back();
        C.pop_back();
    }

    return 0;
}