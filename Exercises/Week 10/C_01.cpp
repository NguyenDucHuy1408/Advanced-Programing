#include <bits/stdc++.h>
using namespace std;

char* reverse_string(const char* str) {
    int len = strlen(str);
    char* reversed = new char[len + 1]; 
    reversed[len] = '\0'; 

    for (int i = 0; i < len; ++i) {
        reversed[i] = str[len - 1 - i]; 
    }

    return reversed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const char* input = "Hello, world!";
    char* reversed = reverse_string(input);
    cerr << "Original string: " << input << endl;
    cerr << "Reversed string: " << reversed << endl;

    delete[] reversed;

    return 0;
}