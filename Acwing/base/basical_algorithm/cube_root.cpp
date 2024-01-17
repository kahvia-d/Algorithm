//
// Created by Kahiva on 2024/1/16.
//

#include <iostream>

using namespace std;

int main(){
    double x;
    scanf("%lf", &x);

    bool aboveZero = true;
    if(x < 0) aboveZero = false, x = 0 - x;

    double l = 0, r = x + 1;

    while(r - l > 1e-8){
        double mid = (l + r) / 2;
        if(mid*mid*mid >= x) r = mid;
        else l = mid;
    }

    printf("%lf", !aboveZero?-l:l);

    return 0;

}