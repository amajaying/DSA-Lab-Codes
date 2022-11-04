// Write a C program to the following sorting operations on the give sequence in
// ascending order: 10, 75, 115, 51, 33, 12, 2, 12
// A) Bubble Sort
// B) Insertion Sort
// C) Selection Sort
// D) Radix Sort
// E) Heap Sort
// F) Quick Sort
// G) Merge Sort

#include<stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    int i, j, temp;
    for(i=1; i<n; i++)
    {
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, temp, min;
    for(i=0; i<n-1; i++)
    {
        min = i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void radixSort(int arr[], int n)
{
    int i, j, temp, max, exp;
    max = arr[0];
    for(i=1; i<n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    for(exp=1; max/exp>0; exp*=10)
    {
        int count[10] = {0};
        for(i=0; i<n; i++)
        {
            count[(arr[i]/exp)%10]++;
        }
        for(i=1; i<10; i++)
        {
            count[i] += count[i-1];
        }
        int output[n];
        for(i=n-1; i>=0; i--)
        {
            output[count[(arr[i]/exp)%10]-1] = arr[i];
            count[(arr[i]/exp)%10]--;
        }
        for(i=0; i<n; i++)
        {
            arr[i] = output[i];
        }
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && arr[l]>arr[largest])
    {
        largest = l;
    }
    if(r<n && arr[r]>arr[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i, temp;
    for(i=n/2-1; i>=0; i--)
    {
        heapify(arr, n, i);
    }
    for(i=n-1; i>=0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low-1;
    int j, temp;
    for(j=low; j<=high-1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(i=0; i<n1; i++)
    {
        L[i] = arr[l+i];
    }
    for(j=0; j<n2; j++)
    {
        R[j] = arr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 8;
    int arr[8] = {10,75,115, 51, 33, 12, 2, 12};
    printf("The array before sorting: \n");
    printArray(arr, n);
    printf("Choose the sorting method:\n1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n4.Radix Sort\n5.Heap Sort\n6.Quick Sort\n7.Merge Sort\n");

    int choice;
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            insertionSort(arr, n);
            break;
        case 3:
            selectionSort(arr, n);
            break;
        case 4:
            radixSort(arr, n);
            break;
        case 5:
            heapSort(arr, n);
            break;
        case 6:
            quickSort(arr, 0, n-1);
            break;
        case 7:
            mergeSort(arr, 0, n-1);
            break;
        default:
            printf("Invalid choice");
    }
    printf("The array after sorting: \n");
    printArray(arr, n);
    return 0;
}
