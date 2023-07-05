#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

pair<int, bool> first_pair = make_pair(0, false);
pair<int, bool> map[5][5] = {first_pair};

void check(int number){
    bool found = false;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(map[i][j].first == number){
                found = true;
                map[i][j].second = true;
            }
            if(found) break;
        }
        if(found) break;
    }
}

bool find_bingo() {
    bool bingo = false;
    int bingo_count = 0;

    for (int i = 0; i < 5; i++) {
        bingo = true;
        for (int j = 0; j < 5; j++) {
        if (!map[i][j].second) {
            bingo = false;
            break;
        }
        }
        if (bingo) {
        bingo_count++;
        }

        bingo = true;
        for (int j = 0; j < 5; j++) {
        if (!map[j][i].second) {
            bingo = false;
            break;
        }
        }
        if (bingo) {
        bingo_count++;
        }
    }

    bingo = true;
    for (int i = 0; i < 5; i++) {
        if (!map[i][i].second) {
        bingo = false;
        break;
        }
    }
    if (bingo) {
        bingo_count++;
    }

    bingo = true;
    for (int i = 0; i < 5; i++) {
        if (!map[i][4 - i].second) {
        bingo = false;
        break;
        }
    }
    if (bingo) {
        bingo_count++;
    }

    return bingo_count >= 3;
}


int main(void){
    int number, count = 1, bingo_number = 3;
    bool bingo = false;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> number;
            map[i][j].first = number;
        }
    }

    for(int i = 0; i < 25; i++){
        cin >> number;
        check(number);
        if(find_bingo()) break;
        count++;
    }

    cout << count << endl;

    return 0;
}