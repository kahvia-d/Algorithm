//
// Created by Kahiva on 2024/1/16.
//

#include <iostream>

using namespace std;

const int N = 100010;
int t[N];


int main(){
    int n, q;
    scanf("%d%d", &n, &q);

    for(int i = 0; i < n; i++) scanf("%d", &t[i]);

    while(q--){
        int x;
        scanf("%d", &x);

        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            //查找x1位置时，x1以及其后元素都满足>=x这个性质
            //当mid对应元素满足性质时，x1应在mid或者mid前，更新右区间为mid
            if(t[mid] >= x) r = mid;
            //当mid对应元素不满足性质时，x1应在mid后，更新左区间为mid + 1.
            else l = mid + 1;
        }
        if(t[l] != x) printf("-1 -1\n");
        else{
            printf("%d ", l);
            int l = 0, r = n - 1;
            while(l < r){
                //在l == mid == r - 1时，若是t[mid]满足性质，左区间会更新为mid
                //为防止死循环，mid应上取整
                int mid = l + r + 1 >> 1;
                //查找x_last元素位置时，x_last及其前面元素满足<=x的性质
                //当mid对应元素满足该性质时，x_last应在mid或者mid后，更新左区间为mid
                //当mid对应元素不满足时，x_last应在mid前，更新右区间为mid - 1
                if(t[mid] <= x) l = mid;
                else r = mid - 1;
            }
            printf("%d\n", l);
        }
    }

    return 0;
}