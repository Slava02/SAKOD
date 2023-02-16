#include <iostream>

using std::swap;
using std::cin;
using std::cout;

int GetOrderStat(int A[], int left, int right, int k);;

int main(){
    int n, k;
    cin >> n >> k;
    int * array = new int[n];
    for(int i = 0; i < n; i++)
        cin >> array[i];
    cout << GetOrderStat(array, 0, n-1, k);
    delete[] array;
    return 0;
}


int GetOrderStat(int A[], int left, int right, int k) {
    int i=left, j=right, x=A[left], num=0; 
    if(left==right) return A[left];
    do {
        while(A[i] < x)i++; 
        while(A[j]>x)j--; 
        if(i <= j) {
            swap(A[i], A[j]);
            i++; 
            j--; 
        }
    } while(i<j);
    if(k<= num) {return GetOrderStat(A, left, i-1, k);}
    else return GetOrderStat(A, i, right, k-num);
}