#include <iostream>
using namespace std; 

void printArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        cout << array[i] << endl;
}

int find_min(int x, int y) { return (x>y) ? y : x;}
int find_max(int x, int y) { return (x<y) ? y : x; }


int find_mid(int a, int b, int c) {
    int tmp_min = find_min(b, c); 
    int tmp_max = find_max(b, c);
    int min = find_min(a, tmp_min);
    int max = find_max(a, tmp_max);
    int mid = 0; 
    if ((a != min) && (a != max)){ mid = a;}
    if ((b != min) && (b != max)){ mid = b;}
    if ((c != min) && (c != max)){ mid = c;}
    return mid; 
}

void quickSort(int *array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = 0;
    if(j-i > 2) {
        pivot = find_mid(array[i], array[(i + j) / 2], array[j]);
    } else {
        pivot = array[(i + j) / 2];
    }
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

void fill_arr(int* arr, int n) {
    for(int i=0; i<n; i++) {cin >> arr[i];}
    cout << "All set \n";
}

int main()
{
    int n;  
    cout << "Enter the size of array :\n" << endl;
    cin >> n; 
    cout << "Enter " << n <<" elemets: \n"  << endl;
    int* arr = new int[n];
    fill_arr(arr, n);

    cout << "Before Quick Sort :" << endl;
    printArray(arr, n);

    quickSort(arr, 0, n-1);

    cout << "After Quick Sort :" << endl;
    printArray(arr, n);

    free(arr);
    return (0);
}