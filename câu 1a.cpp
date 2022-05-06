// cau 1a 
#include<iostream>
using namespace std;

// Ham doi vi tri hai phan tu
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Ham sap xep giam
void sortArrGiam(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
}

// Ham nhap mang
void inputArr(int a[], int n) {
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

// Ham xuat mang
void printArr(int a[], int n) {
    for (int i = 0; i < 5; i++)
        cout << " " << a[i];
}

int main() {
    int n;
    // Nhap so luong phan tu mang
    do {
        cout << "Nhap n: ";
        cin >> n;
    } while (n <= 0);  // Neu n<=0 thi nhap lai

    int a[100];  
    // khai bao mang a co n phan tu

    inputArr(a, n); 
    // Goi ham nhap mang

    sortArrGiam(a, n);
    // Goi ham sap xep

    cout << "Mang sau khi sap xep tang dan: " << endl;
    printArr(a, n);
    return 0;
}
/*vd: n = 6
Phan tu nhap vao
      1 2 3 4 5 6
5 phan tu lon nhat dau tien:
      6 5 4 3 2
 */ 
