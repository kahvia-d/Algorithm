//
// Created by Kahiva on 2024/1/25.
//
#include <iostream>

using namespace std;

const int N = 100010;
//a数组为前缀和数组，b为差分数组
int a[N], b[N];

void insert(int l, int r, int c){
    //对于前缀和数组a而言，要使[l, r]的前缀和+c
    //只需使差分数组b的第l位元素+c，这会让l及其以后的前缀和+c
    //然后第r+1位元素-c，这会让r+1及其以后的前缀和-c，即[r + 1, ?]的前缀和保持不变。
    b[l] += c;
    b[r + 1] -= c;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    //初始时，将a和b都看作全为零的的数组，前缀和和差分都为0。
    //然后输入数组a。
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    //将输入的数组a看作待添加的元素c，即区间[i,i]上的元素都加上常数c（a[i]）。
    for(int i = 1; i <= n; i++) insert(i, i, a[i]);

    //同样的执行m次insert即可。
    while(m--){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    //计算前缀和。
    for(int i = 1; i <= n; i++) b[i] += b[i - 1];

    for(int i = 1; i <= n; i++) printf("%d ", b[i]);

    return 0;
}