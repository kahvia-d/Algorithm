//
// Created by Kahiva on 2024/2/8.
//
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

//采用二分查找b中第一个可能满足的值，l和r是查找区间，ai是a当前的i，x是条件目标值
int div_search(int l, int r, int ai, int x){
    int i = l, j = r;
    while(i < j){
        int mid = i + j >> 1;
        if(a[ai] + b[mid] >= x) j = mid;
        else i = mid + 1;
    }

    return i;
}


int main(){
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);

    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < m; i++) scanf("%d", &b[i]);

    //随着i增大，j的范围一定会减小
    for(int i = 0, j = m - 1; i < n; i++){
        j = div_search(0, j, i, x);
        //如果满足条件，则输出。
        if(a[i] + b[j] == x){
            printf("%d %d", i, j);
            break;
        }
    }

    return 0;
}