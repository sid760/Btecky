#include <iostream>
using namespace std;

void merge(int *arr, int *leftArr, int *rightArr, int lsize, int rsize)
{
    int i = 0, j = 0, k = 0;
    while (i < lsize && j < rsize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    while (i < lsize)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rsize)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    int mid = (l + r) / 2;
    int leftArr[mid + 1];
    int rightArr[r - mid];

    for (int i = 0; i < mid + 1; i++)
    {
        leftArr[i] = arr[i];
    }

    for (int i = 0; i < r - mid; i++)
    {
        rightArr[i] = arr[i + mid + 1];
    }
    if (l < r)
    {
        mergeSort(leftArr, l, mid);
        mergeSort(rightArr, mid + 1, r);
    }

    merge(arr, leftArr, rightArr, mid + 1, r - mid);
}
void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {5, 4, -2, 1, 0};
    printArr(arr, 5);
    mergeSort(arr, 0, 4);
    printArr(arr, 5);

    return 0;
}
