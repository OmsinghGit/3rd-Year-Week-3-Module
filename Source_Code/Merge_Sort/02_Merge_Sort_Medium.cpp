#include <iostream>
using namespace std;

void merge(int arr[], int s, int mid, int e)
{
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;

    for (int i = 0; i < len1; i++)
        first[i] = arr[k++];

    k = mid + 1;

    for (int i = 0; i < len2; i++)
        second[i] = arr[k++];

    int i = 0, j = 0;
    k = s;

    while (i < len1 && j < len2)
    {
        if (first[i] < second[j])
            arr[k++] = first[i++];
        else
            arr[k++] = second[j++];
    }

    while (i < len1)
        arr[k++] = first[i++];

    while (j < len2)
        arr[k++] = second[j++];

    delete[] first;
    delete[] second;
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, mid, e);
}

int main()
{
    int n;
    cin >> n;

    int arr[100000];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    int median = arr[n / 2];

    cout << "Median: " << median << endl;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > median)
            count++;
    }

    cout << "Orders Above Median: " << count << endl;

    cout << "Difference: " << arr[n - 1] - arr[0];

    return 0;
}