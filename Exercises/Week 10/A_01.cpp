#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;

char* concat(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2); 
 
    int totalLen = len1 + len2;

    char* result = new char[totalLen + 1]; 

    strcpy(result, str1);
    strcat(result, str2);
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const char* s1 = "Hello";
    const char* s2 = "World";
    char* result = concat(s1, s2);
	
    cout << "Concatenated string: " << result << '\n';
}