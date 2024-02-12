#include <vector>
#include <iostream>
#include <map>
using namespace std;

/*
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
*/


int majorityElement(vector<int>& nums) {
    int majority = nums.size()/2;
    map<int, int> m;
    for(auto i: nums){
        m[i]++;
        if (m[i] > majority)
            return i;
    }
    return -1;
}

int main(){
    // vector <int> nums = {3,2,3};
    vector <int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums);
}