#include<stdio.h>
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
            swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void print_arr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
        if(i<n-1)
        {
            printf(",");
        }
    }
}
void selection_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int smallest =i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[smallest])
            smallest=j;
        }
        swap(&arr[i],&arr[smallest]);
    }
}
void insertion_sort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
       int current=arr[i];
       int previous=i-1;
       while(previous>=0 && arr[previous]< current)
       {
        arr[previous+1]=arr[previous];
        previous--;
       }
       arr[previous+1]=current;
    }
}
    // void merge_sort(int arr[],int start,int mid,int end)
    // {
    //     if(start<end)
    //     {
    //         int mid=start+(end-start)/2;
    //         merge_sort(arr,start,mid);
    //         merge_sort(arr,mid+1,end);
    //     }
    // }
    #include <stdio.h>

// This is the "Merge" part where the 'vectors' (arrays) live
void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1; // Size of left part
    int n2 = end - mid;       // Size of right part
    int leftArr[n1]; 
    int rightArr[n2];
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i++];
        } else {
            arr[k] = rightArr[j++];
        }
        k++;
    }
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}
void merge_sort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        merge_sort(arr, start, mid);      // Sort the left half
        merge_sort(arr, mid + 1, end);    // Sort the right half
        merge(arr, start, mid, end);      // Put them together
    }
}
int main()
{
    int arr[]= {3,14,52,21,5321,355,321,765,235,8475,44,3};
    int n=12;
    merge_sort(arr, 0, n - 1);
    print_arr(arr,n);
    bubble_sort(arr, n);
    print_arr(arr, n);
}