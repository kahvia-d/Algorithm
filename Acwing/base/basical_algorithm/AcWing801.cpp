//
// Created by Kahiva on 2024/1/30.
//
//二进制中1的个数
//https://www.acwing.com/problem/content/803/

#include <iostream>

using namespace std;

const int N = 100010;
int a[N];

int lowbit(int x){
    //-x相当于x的补码
    return x & -x;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    for(int i = 0; i < n; i++){
        int k = 0;
        while(a[i]){
            a[i] -= lowbit(a[i]);
            k++;
        }
        printf("%d ", k);
    }

    return 0;
}