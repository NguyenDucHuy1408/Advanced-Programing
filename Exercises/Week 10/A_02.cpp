#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int* p = new int;     // Dòng này cấp phát bộ nhớ động cho con trỏ p
    int* p2 = p;          // Sao chép địa chỉ của p vào p2
    *p = 10;              // Gán giá trị 10 vào vùng nhớ mà p trỏ tới
    delete p;             // Giải phóng bộ nhớ mà p trỏ tới
    *p2 = 100;            // Lỗi: p đã bị giải phóng, không thể truy cập vào nó. Đây là việc sử dụng một con trỏ đã được giải phóng bộ nhớ.
    cout << *p2;          // Lỗi: tương tự như trên, p đã bị giải phóng
    delete p2;            // Lỗi: tương tự như trên, p đã bị giải phóng

    return 0;
}