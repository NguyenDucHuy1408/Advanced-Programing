#include <iostream>
using namespace std;

// Hàm tính độ dài của xâu
size_t strlen(const char *str) {
    size_t length = 0;
    while (*str++) {
        length++;
    }
    return length;
}

// Hàm sao chép xâu nguồn vào xâu đích
char* strcpy(char *dest, const char *src) {
    char *save = dest;
    while ((*dest++ = *src++)) {}
    return save;
}

// Hàm đảo ngược thứ tự của xâu
void reverse(char a[]) {
    size_t length = strlen(a);
    for (size_t i = 0; i < length / 2; ++i) {
        char temp = a[i];
        a[i] = a[length - i - 1];
        a[length - i - 1] = temp;
    }
}

// Hàm xóa kí tự c trong xâu a
void delete_char(char a[], char c) {
    size_t i, j;
    for (i = 0, j = 0; a[i] != '\0'; ++i) {
        if (a[i] != c) {
            a[j++] = a[i];
        }
    }
    a[j] = '\0';
}

// Hàm độn thêm kí tự space vào cuối xâu a để a có độ dài bằng n
void pad_right(char a[], int n) {
    size_t length = strlen(a);
    if (length >= n) return;
    for (size_t i = length; i < n; ++i) {
        a[i] = ' ';
    }
    a[n] = '\0';
}

// Hàm độn thêm kí tự space vào đầu xâu a để a có độ dài bằng n
void pad_left(char a[], int n) {
    size_t length = strlen(a);
    if (length >= n) return;
    size_t padding = n - length;
    for (size_t i = length + padding; i >= padding; --i) {
        a[i] = a[i - padding];
    }
    for (size_t i = 0; i < padding; ++i) {
        a[i] = ' ';
    }
}

// Hàm cắt bớt đoạn cuối của xâu a để a có độ dài n
void truncate(char a[], int n) {
    size_t length = strlen(a);
    if (length <= n) return;
    a[n] = '\0';
}

// Hàm kiểm tra xâu có phải là đối xứng hay không
bool is_palindrome(char a[]) {
    size_t length = strlen(a);
    for (size_t i = 0; i < length / 2; ++i) {
        if (a[i] != a[length - i - 1]) {
            return false;
        }
    }
    return true;
}

// Hàm xóa các kí tự trắng đứng ở đầu xâu a
void trim_left(char a[]) {
    size_t length = strlen(a);
    size_t i = 0;
    while (a[i] == ' ') {
        ++i;
    }
    for (size_t j = 0; j < length - i + 1; ++j) {
        a[j] = a[i + j];
    }
}

// Hàm xóa các kí tự trắng đứng ở cuối xâu a
void trim_right(char a[]) {
    size_t length = strlen(a);
    size_t i = length - 1;
    while (a[i] == ' ') {
        --i;
    }
    a[i + 1] = '\0';
}

int main() {
    char str[] = "  Hello, World!  ";

    // Đảo xâu
    cout << "Reversed string: ";
    reverse(str);
    cout << str << "\n";

    // Xóa kí tự ','
    delete_char(str, ',');
    cout << "String after deleting ',': " << str << "\n";

    // Độn phải
    pad_right(str, 20);
    cout << "String after padding right: " << str << "\n";

    // Độn trái
    pad_left(str, 25);
    cout << "String after padding left: " << str << "\n";

    // Cắt xâu
    truncate(str, 10);
    cout << "String after truncating: " << str << "\n";

    // Kiểm tra đối xứng
    char palindrome[] = "radar";
    char non_palindrome[] = "hello";
    cout << palindrome << " is palindrome: " << boolalpha << is_palindrome(palindrome) << "\n";
    cout << non_palindrome << " is palindrome: " << boolalpha << is_palindrome(non_palindrome) << "\n";

    // Lọc trái
    trim_left(str);
    cout << "String after trimming left: " << str << "\n";

    // Lọc phải
    trim_right(str);
    cout << "String after trimming right: " << str << "\n";

    return 0;
}