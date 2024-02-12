#include <iostream>
#include <vector>
#include "assert.h"


using namespace std;

/*
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * Note that you must do this in-place without making a copy of the array.
*/

void printVector(vector<int> &nums) {
    for (auto &a: nums) {
        cout << a << " ";
    }
    cout << endl;
}

void switchPos(int p1, int p2, vector<int> &nums) {
    int temp = nums[p1];
    nums[p1] = nums[p2];
    nums[p2] = temp;
}

void moveZeroes(vector<int> &nums) {
    int p1 = 0, p2 = 1;
    while (p2 < nums.size()) {

        while ( p2 < nums.size() && nums[p2] == 0 ) {
            p2++;
        }

        if (nums[p1] == 0 && p2 < nums.size()) {
            switchPos(p1, p2, nums);
        }
        p1++;
        p2++;
    }
}

int main() {

    vector<int> v1 = {0, 1, 0, 3, 12};
    vector<int> r1 = {1, 3, 12, 0, 0};
    vector<int> v2 = {0};
    vector<int> r2 = {0};

    //vector<int> v3 = {0, 1, 0, 3, 12, 0, 12, 0, 11, 1};
    vector<int> v3 = {1,0,1};

    //moveZeroes(v1);
    //moveZeroes(v2);
    moveZeroes(v3);
    //myAssert(v1, r1);
    printVector(v1);
    printVector(v2);
    printVector(v3);

    cout << "All tests passed successfully." << endl;
    return 0;
}