#include <iostream>

using namespace std;

/*
 You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with
 word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

 Return the merged string.
*/

string mergeAlternately(string word1, string word2) {
    string res;
    string nextChar;
    int posW1 = 0, posW2 = 0;

    int i = 0;
    while (i < word1.size() + word2.size()) {
        if (posW1 < word1.size()) {
            res += word1[posW1];
            i++;
            posW1++;
        }
        if (posW2 < word2.size()) {
            res += word2[posW2];
            i++;
            posW2++;
        }
    }
    return res;
}

bool assert(string input, string result){
    if(input != result){
        cout << "ERROR: "<< input << "!=" << result << endl;
        exit(1);
    }
    return true;
}

int main() {
    assert(mergeAlternately("abc", "pqr"), "apbqcr");
    assert(mergeAlternately("ab", "pqrs"), "apbqrs");
    assert(mergeAlternately("abcd", "pq"), "apbqcd");

    cout << "All tests passed successfully." << endl;
    return 0;
}