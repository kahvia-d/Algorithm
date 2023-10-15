//
// Created by Kahvia on 2023/10/15.
//
//https://www.acwing.com/problem/content/3379/

#include <iostream>
#include <algorithm>
using namespace std;

#define N 1010

struct Student{
    int id;
    int score;

    bool operator <(const Student& s)const{
        if(score!=s.score)
            return score<s.score;
        else//成绩相同的时候则学号小的优先
            return id<s.id;
    }

    bool operator >(const Student& s)const{
        if(score!=s.score)
            return score>s.score;
        else
            return id<s.id;
    }
}c[N];

int main(){
    //数据量
    int n;
    cin >> n ;
    for (int i = 0; i < n; ++i) {
        cin>>c[i].id>>c[i].score;
    }

    //从低到高排序
    sort(c,c+n);

    for(int i=0;i<n;i++){
        cout<<c[i].id<<" "<<c[i].score<<endl;
    }
}
