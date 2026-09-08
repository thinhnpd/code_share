# MỘT SỐ LƯU Ý TRƯỚC KHI THI OFFLINE
Gửi tặng anh em Tin học THCS Nguyễn Văn Linh (Cẩm Lệ).

## 1. Kiểm tra bài
**Bước 1.** Kiểm tra logic  
**Bước 2.** Sinh test tay, có thể mô phỏng cơ chế bằng giấy bút $\rightarrow$ Kiểm tra đã hiểu đúng đề chưa.  
**Bước 3.** Sinh test vừa để check VAR.  
**Bước 4.** Sinh test khổng lồ (sub cuối) để kiểm tra TLE, MLE (Quá giới hạn RAM), ...  
**Bước 5.** Sinh test đặc biệt (edge case) (VD: Số siêu nhỏ, số chạm giới hạn, ...) (Kỹ thì làm, không thích thì bỏ qua cũng được)  

## 2. Sinh test
*(Hướng dẫn sinh test của Phạm Văn Hạnh: https://www.youtube.com/watch?v=jrm8gU-7B4o)*  
**a. Chuẩn bị:** 1 file code sinh test, 1 file code trâu, 1 file code "chuẩn" (file dùng để nộp bài), 1 file batch để chạy trình sinh test và so code.  
**b. Mô hình cơ bản của sinh test:** Chạy code sinh test $\rightarrow$ Chạy code trâu và "chuẩn" (chạy trâu trước hay "chuẩn" trước cũng đc) $\rightarrow$ So sánh 2 output của 2 code.  
**c. Quy trình cụ thể:**   

Quy ước tên bài là ```ABC```.  

**Bước 1.** Viết code cày trâu, ghi ra file có định dạng ```.ANS``` để làm file đối chứng với ```.OUT``` của code "chuẩn".  
```cpp
#incude <bits/stdc++.h>
using namespace std;
typedef long long ll; // không được dùng using ll = long long !
#define endl '\n'
const ll mod = 1e9 + 7;

int main() { 
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("ABC.INP", "r", stdin);
    freopen("ABC.ANS", "w", stdout); // Phải đổi định dạng file output qua .ANS !

    // Code gì đó...

    return 0;
}
```

**Bước 2.** Viết code sinh test 
```cpp
ll randint(ll l, ll r) {
    ll ans = 1;
    for (int i = 1; i <= 4; i++) ans = (ans << 15) ^ (rand() & ((1 << 15) - 1));
    return l + ans % (r - l + 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("ABC.INP", "w, stdout); // Code chỉ ghi ra file input, không nhập gì cả.

    srand(time(0)); // PHẢI CÓ!!! NẾU KHÔNG THÌ CHẠY LẦN NÀO CŨNG RA TEST GIỐNG NHAU.
    // Thực hiện sinh test bằng cách in ra các tham số đúng định dạng input và giới hạn của đề.
}
```

**Bước 3.** Biên dịch tất cả 3 file "chuẩn", trâu và sinh test để có 3 file .exe (để lát nữa chạy so code không cần biên dịch lại cho mỗi lần chạy)  

**Bước 4.** Viết file batch so code, đặt tên là ```run.bat```.
```batch
ABC_gen
ABC_slow
ABC

fc /w ABC.OUT ABC.ANS
```

**Bước 5.** Mở CMD, chuyển đến đường dẫn của thư mục chứa bài làm của mình, chạy lệnh ```run.bat```. Nếu thông báo như sau là OK:  
```
Comparing files ABC.OUT and ABC.ANS
FC: no differences encountered
```

## 3. Phiên bản C++
Ban giám khảo khả năng cao sẽ sử dụng phần mềm Themis để chấm bài.  
Themis mặc định dùng C++ 98, các bạn hãy code sao cho không bị CE ở bản C++ này.  
Một số lưu ý khi hạ cấp từ C++ 11 xuống C++ 98/03 *(C++03 nó chỉ là nâng cấp hiệu năng so với 98 chứ không có hàm mới gì hết nha)*:  
- Không dùng ```auto```, muốn dùng lower_bound hay upper_bound thì khai iterator/pointer ứng với KDL:
  + Mảng tĩnh (VD: ```ll a[]```): ```ll *tên biến = lower_bound...```
  + Vector (VD: ```vector<KDL>```): ```vector<KDL>::iterator tên biến = lower_bound ...```
- Không được dùng ```using ll = long long```, thay vào đó phải dùng ```#define ll long long``` hoặc ```typedef long long ll;```.
- Không được ```for``` kiểu này: ```for (int x : a)```, thay bằng ```for (int i = 0; i < a.size(); i++) ``` và truy cập bằng ```a[i]```.  

**Cách chuyển xuống phiên bản C++98 cho CodeBlocks:** Vào Settings, chọn Compiler, và chọn như hình này: <img width="546" height="450" alt="{D8FF2DE6-D564-419A-9F13-B12E523BC78C}" src="https://github.com/user-attachments/assets/5784ab39-a7bb-4b19-88a8-becd3d3287a3" />


## 4. Phần mềm khi thi
Trong phòng thi khả năng cao sẽ không có VSCode hay Sublime Text, nên hãy chọn và tập dùng 1 trong số những phần mềm sau cho mỗi ngôn ngữ:
- **C++:** CodeBlocks, Dev-C++ (đỏ hay xanh gì cũng OK).
- **Python:** Thonny, IDLE Python (IDLE Python mở bằng cách mở Start menu, tìm idle).

Những phần mềm đó chắc chắn có trong máy tính phòng thi.  
## 5. Xử lý sự cố phát sinh trên máy thi
**Đàm đạo trực tiếp sau cho anh em dễ hiểu!**
