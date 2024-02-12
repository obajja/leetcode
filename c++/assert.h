#include <iostream>

using namespace std;

template<typename T>
bool myAssert(T input, T result) {
    if (input != result) {
        cout << "ERROR: " << input << "!=" << result << endl;
        exit(1);
    }
    return true;
}

bool myAssert(string input, string result) {
    if (input != result) {
        cout << "ERROR: " << input << "!=" << result << endl;
        exit(1);
    }
    return true;
}
