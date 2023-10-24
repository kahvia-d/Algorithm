//
// Created by Kahiva on 2023/10/23.
//
//https://www.acwing.com/problem/content/3576/

#include "iostream"
#include "algorithm"

using namespace std;

const int months[13]={
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int is_leap(int y){
    if (y % 100!=0 && y % 4==0 || y % 400 == 0)
        return 1;
    else
        return 0;
}

int get_days(int y, int m){
    if (m==2)
        return months[m] + is_leap(y);
    else
        return months[m];
}

int get_days_amongYear(int y, int m){
    //今年三月前到明年三月前，会经过今年的2月29日（如果今年是闰年的话）
    //今年三月以及三月后到明年的同日期，会经过明年的2月29（存在的话）
    if (m<=2)
        return 365 + is_leap(y);
    else
        return 365 + is_leap(y+1);
}

int main(){
    int n;
    int y, m, d, s;
    cin>>n;
    while(n--){
        cin>>y>>m>>d>>s;
        //起始日期2月29则不确定下一年是否有2月29，跳过这一天再说。
        if (m == 2 && d == 29)
            s --, m = 3, d = 1;
        //满一年直接跳过一年
        while (s > get_days_amongYear(y, m)){
            s -= get_days_amongYear(y, m);
            y ++;
        }
        //不满一年则按天模拟度日
        while (s --){
            if (++ d > get_days(y, m)){
                d = 1;
                if ( ++ m > 12){
                    m = 1;
                    y ++;
                }
            }
        }
        printf("%04d-%02d-%02d\n", y, m, d);
    }
    return 0;
}