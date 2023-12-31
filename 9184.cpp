#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    else if(a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    else if(a < b && b < c) return w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main(void){
    int a, b, c;

    while(1){
        cin >> a >> b >> c;

        if(a != -1 && b != -1 && c != -1){
            cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl; 
        }else break;
    }
    
    return 0;
}