//
// Created by Kahiva on 2023/11/27.
//
//https://www.acwing.com/problem/content/787/
//各种排序

#include "iostream"
#include "cstring"
#include "algorithm"

using namespace std;

const int N = 100010;

int nums[N];
int n;


void insert_sort(){
    for (int i = 1; i < n; i++){
        int x = nums[i];
        int j = i;
        while (j >0 && nums[j-1] > x){
            nums[j] = nums[j-1];
            j--;
        }
        nums[j] = x;
    }
}

void shell_sort(){
    for(int d = n/2; d > 0; d /= 2)//公差等比递减
        for(int start = 0; start < d; start++)//以公差为单位分组
            for (int i = start + d; i < n; i += d)//每组进行插入排序
            {
                int x = nums[i];
                int j = i;
                //j > start 防止越界
                while (j > start && nums[j-d] > x){
                    nums[j] = nums[j-d];
                    j -= d;
                }
                nums[j] = x;
            }

}

void quick_sort(int start, int end){
    if (start >= end) return;
    //左右指针
    int left = start - 1;
    int right = end + 1;
    //取分界值
    int mid_x = nums[(left + right) / 2];
    while (left < right){
        //找到分界值左边大于分界值的数
        do left++; while (nums[left] < mid_x);
        //找到分界值右边小于分界值的数
        do right--; while (nums[right] > mid_x);
        //交换这两个数，此后小的数在分界值左边，大的数在分界值右边

        if (left < right)
            swap(nums[left], nums[right]);

    }//循环结束后，分界值左边的数都小于分界值，右边则大于分界值

    //分界值的左区间和右区间同理进行快排
    quick_sort(start, right);
    quick_sort(right + 1, end);
}


int main(){
    cin>>n;

    for (int i = 0; i < n; i++)
        cin>>nums[i];

//    insert_sort();
//    shell_sort();
    quick_sort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout<<nums[i]<<" ";


    return 0;
}