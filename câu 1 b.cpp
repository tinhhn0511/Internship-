// Câu 1b
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

// Hàm nhập mảng
void inputArr(int array1[], int n) {
    for (int i = 0; i < n; i++)
        cin >> array1[i];
}

// Hàm xuất mảng
void printArr(int array1[], int n) {
    for (int i = 0; i < n; i++)
        cout << " " << array1[i];
}

/*Tạo macro SIZE_OF_ARRAY để lấy độ dài (số phần tử) của mảng chỉ định*/
#define SIZE_OF_ARRAY(array)    (sizeof(array)/sizeof(array[0]))


/*Tạo hàm so sánh tăng dần sử dụng trong hàm qsort*/
int compareIntAsc(const void* a, const void* b)
{
    int aNum = *(int*)a;
    int bNum = *(int*)b;

    return aNum - bNum;
}

void array_unique(int* array, size_t size) {
    //Khởi tạo mảng max chứa kết quả
    //max[0] : phần tử xuất hiện nhiều nhất
    //max[1] : số lần xuất hiện của phần tử đó
    int max[] = { 0,0 };

    //Sử dụng vòng lặp for để lọc ra các phần tử xuất hiện nhiều hơn 1 lần
    //So sánh số lần xuất hiện và thay đổi max khi cần.
    int count = 1;
    for (size_t i = size - 1; i > 0; --i) {
        if (array[i] == array[i - 1]) ++count; //Thấy phần tử trùng nhau thì tiếp tục đếm
        else {
            //So sánh số lần xuất hiện với max[1] 
            if (max[1] < count) {
                //Nếu tìm thấy phần tử xuất hiện nhiều hơn thì gán phần tử vào max[0]
                //Và gán số lần xuất hiện vào max[1]
                max[0] = array[i];
                max[1] = count;
            }
            count = 1;
        }
    }
    cout << "Phan tu " << max[0] << " xuat hien nhieu nhat trong mang voi " << max[1] << " lan";
}

int main() {
    int n;
    // Nhập số lượng phần tử mảng;
    do {
        cout << "Nhap n: ";
        cin >> n;
    } while (n <= 0);  // Neu n<=0 thi nhap lai
    int array1[100];
    inputArr(array1, n);
    // Sắp xếp các mảng theo thứ tự tăng dần
    qsort(array1, SIZE_OF_ARRAY(array1), sizeof(int), compareIntAsc);

    //Đếm số lần xuất hiện của các phần tử trong mảng C++
    array_unique(array1, SIZE_OF_ARRAY(array1));

    return 0;
}