//
// Created by Kahiva on 2024/1/30.
//
#include <iostream>

using namespace std;

const int N = 100010;

//记录当前子序列中某数字出现的次数
int check[N];
//序列整体
int a[N];

int main(){
    int n, res;
    scanf("%d", &n);

    //输入序列
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    //双指针，i用于遍历，j用作子序列左起点。
    for(int i = 0, j = 0; i < n; i++){
        check[a[i]] ++;
        //若子序列出现重复的数，则新开子序列，更新check数组。
        while(check[a[i]] > 1){
            check[a[j]] --;
            j ++;
        }
        //随时更新最长子序列长度
        res = max(res, i - j + 1);
    }

    printf("%d", res);


    return 0;
}