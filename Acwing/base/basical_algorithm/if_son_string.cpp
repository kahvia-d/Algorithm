//
// Created by Kahiva on 2024/2/8.
//
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int j = 0; j < m; j++) scanf("%d", &b[j]);

    //双指针
    int i = 0, j = 0;

    //双指针都未扫描完各自的串时，保持循环
    while(i < n && j < m){
        //如果子串当前字符匹配到，则换下一个字符
        if(a[i] == b[j]) i++, j++;
            //否则继续匹配
        else j++;
    }

    //若字串匹配完毕，则输出yes
    if(i == n) printf("Yes");
    else printf("No");

    return 0;
}