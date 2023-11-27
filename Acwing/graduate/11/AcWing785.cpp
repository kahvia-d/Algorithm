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

int main(){
    cin>>n;

    for (int i = 0; i < n; i++)
        cin>>nums[i];

//    insert_sort();
    shell_sort();
    for (int i = 0; i < n; i++)
        cout<<nums[i]<<" ";


    return 0;
}