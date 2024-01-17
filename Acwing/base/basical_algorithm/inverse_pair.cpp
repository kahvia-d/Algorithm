//
// Created by Kahiva on 2024/1/17.
//
//逆序对的数量
//https://www.acwing.com/problem/content/790/

#include <iostream>

using namespace std;

const int N = 100010;

long long t[N], tmp[N];

long long counts = 0;

void calculate_reverse_pair(int l, int r){
    if(l >= r) return;
    int mid = l + r >> 1;

    calculate_reverse_pair(l, mid), calculate_reverse_pair(mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r){
        if(t[i] <= t[j]) {
            tmp[k++] = t[i++];
        }
        else{
            tmp[k++] = t[j++];
            //将后半部分的小元素移到前半部分时，越过的前半部分元素个数即为逆序对个数
            counts += (mid - i + 1);
        }
    }
    while(i <= mid) tmp[k++] = t[i++];
    while(j <= r) tmp[k++] = t[j++];

    for(int i = l, j = 0; i <= r; i++, j++)
        t[i] = tmp[j];

}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%lld", &t[i]);

    calculate_reverse_pair(0, n - 1);

    printf("%lld", counts);

    return 0;
}