//
// Created by Kahiva on 2023/10/23.
//
//https://www.acwing.com/activity/content/code/content/1405572/

#include "iostream"
#include "algorithm"

using namespace std;

//非闰年的每月天数
const int months[13] = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

//是否闰年
int is_reap (int y){
    //普通闰年（不能被100整除，但是能被4整除）和世纪闰年（能被400整除）
    if (y % 100 !=0 && y % 4 == 0 || y % 400 == 0){
        return 1;
    }
    return 0;
}

//某一年的某一月有几天
int get_days(int y, int m){
    if (m == 2)
        return months[m] + is_reap(y);
    else
        return months[m];
}

int main(){
    int year, month, day, days;
    //输入某一年的多少天
    while (cin>>year>>days){
        month=1,day=0;
        //模拟日期变化
        while (days--){
            //月满则轮月
            if (++day > get_days(year, month)){
                day=1;
                //月满则轮年
                if (++month > 12){
                    month = 1;
                    year++;
                }
            }
        }
        printf("%04d-%02d-%02d\n", year, month, day);
    }
}