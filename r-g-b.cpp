#include<iostream>
#include<vector>
using namespace std;

vector<char> sort(vector<char>rgbs) {
    int left=0;
    int right = rgbs.size() - 1;

    // Move 'R' to front
    while(true) {
        while ( left < right && rgbs[left] == 'R') {
            left++;
        }
        while(left < right && rgbs[right] != 'R') {
            right--;
        }
        if (left >= right) {
            break;
        }
        swap(rgbs[left], rgbs[right]);
    }
    right = rgbs.size() - 1;
    // Move 'B' to tail
    while(true) {
         while ( left < right && rgbs[left] != 'B') {
            left++;
        }
        while(left < right && rgbs[right] == 'B') {
            right--;
        }
        if (left >= right) {
            break;
        }
        swap(rgbs[left], rgbs[right]);
    }

    return rgbs;
}

int main() {
    vector<char>rgbs = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
    vector<char>ans = sort(rgbs);

    for (char color: ans) {
        cout<<color<<" ";
    }

    return 0;
}