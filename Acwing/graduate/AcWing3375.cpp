//
// Created by Kahiva on 2023/10/15.
//
//https://www.acwing.com/problem/content/3378/

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 1010

struct Student{
    string name;
    int score;

    bool operator <(const Student& s)const{
        return score<s.score;
    }

    bool operator >(const Student& s)const{
        return score>s.score;
    }
}c[N];

int main(){
    //数据量和数据处理模式（0从高到低，1从低到高）
    int n,mode;
    cout<<"请输入："<<endl;
    cin >> n >> mode;
    for (int i = 0; i < n; ++i) {
        cin>>c[i].name>>c[i].score;
    }

    if(mode){
        //stable_sort默认从低到高
        stable_sort(c,c+n);
    }else{
        stable_sort(c,c+n,greater<Student>());
    }

    for(int i=0;i<n;i++){
        cout<<c[i].name<<" "<<c[i].score<<endl;
    }
}
