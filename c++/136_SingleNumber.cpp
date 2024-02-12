#include <vector>
#include <map>
#include <iostream>

using namespace std;
/*
 * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 * You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

int singleNumber(vector<int>& nums) {
    map<int, int> m;
    for (int i: nums){
        m[i]++;
    }
    for (int i:nums){
        if (m[i] == 1){
        }
    }
    return -1;
}

int main (){
    vector<int> nums = {1};
    cout << singleNumber(nums) << endl;
    return 0;
}