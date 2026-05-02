
#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
void linear_search(int arr[],int n,int target)
{
    int found=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target)
        {
            found=1;
            printf("your target element %d found at %d index",target,i);
            break;
        }
    }
    if(found==0)
    {
        printf("your target element not found in the array provided");
    }
}
void binary_search(int arr[],int n,int target)
{
    int start=0;
    int end=n-1;
    int index=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(target==arr[mid])
        {
            index=mid;
            break;
        }
        else if(target>mid)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    if(index==-1)
    {
        printf("your target element %d not found in this array",target);
    }
    else
    {
        printf("tour target element %d found at index %d",target,index);
    }
}
int insert_pos(int arr[], int n, int pos, int x)
{
    if (pos >= n || pos <0)
    return n;
    else
    for (int i = n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = x;
    return n + 1;
}
void getmax(int arr[], int n)
{
    int max=arr[0];
    for(int i=0; i<n ; i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    printf("%d is maximum in array\n",max);
}
void getmin(int arr[], int n)
{
    int min=arr[0];
    for(int i=0; i<n ; i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    printf("%d is minimum in array\n",min);
}
void reversed_array(int arr[],int n)
{
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
int delete(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            break;
        }
    }
    for (int j = i; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }
    return n - 1;
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof (arr)/sizeof (arr[0]);
    printf("Orignal Array--->\n");
    display(arr, n);
    getmax(arr,n);
    getmin(arr,n);
    printf("reversed array\n");
    reversed_array(arr,n);
    display(arr,n);
    n = insert_pos(arr, n, 3, 99);
    display(arr, n);
    n = delete(arr, n, 99);
    display(arr, n);
    n = delete(arr, n, 1);
    display(arr, n);
    return 0;
}