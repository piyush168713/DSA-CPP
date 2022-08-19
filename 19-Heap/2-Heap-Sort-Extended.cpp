#include<iostream>
using namespace std;

void insert(int A[], int n){
    int i = n, temp;
    temp = A[n];
    while(i>1 && temp > A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

int Delete(int A[], int n)
{
    int x, i, j, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];

    A[n] = val;   // this stores element at the last place
    
    i = 1, j = 2*i;

    while(j < n-1)
    {
        if(A[j+1] > A[j])
            j = j+1;

        if(A[i] < A[j]){
            swap(A[i], A[j]);
            // temp = A[i];
            // A[i] = A[j];
            // A[j] = temp;
            i = j;
            j = 2*j;
        }
        else
            break;
    }
    return val;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    
    int size = n;

    while(size > 1){
        // step 1
        // swap
        swap(arr[size], arr[1]);
        size--;

        // step 2
        heapify(arr, size, 1);
    }
}

int main(){
    
    int H[] = {0, 2, 5, 8, 9, 4, 10, 7};
    int H1[] = {0, 10, 20, 30, 25, 5, 40, 35};
    // H1 after inserting - 40 25 35 10 5 20 30

    // insert(H, 2);    // here 2 is index.......insert an element at index 2
    // insert(H, 3);
    // insert(H, 4);
    // insert(H, 5);

    cout<<"\n------ Normal Insert T.C - O(nlogn) ------\n";
    for (int i = 2; i <= 7; i++){
        insert(H1, i);
    }

    for (int i = 1; i <= 7; i++){
        cout<<H1[i]<<" ";
    }
    cout<<endl;

    cout<<"\n------ Heapify Insert T.C - O(n) ------\n";

    int arr[6] = {-1, 54, 53, 55, 52, 50};

    int n = 7;
    
    // Heap creation
    for (int i = n/2; i > 0; i--)
    {
        heapify(H1, n, i);
    }

    // max Heap format
    cout<<"Printing Array in max Heap format: \n";
    for (int i = 1; i <= n; i++){
        cout<<H1[i]<<" ";
    }
    cout<<endl<<endl;

    // Heap Sort
    heapSort(H1, n);
    cout<<"Printing Array in Heap Sort:  T.C - O(nlogn) \n";
    for (int i = 1; i <= n; i++){
        cout<<H1[i]<<" ";
    }
    cout<<"\n\n";


    cout<<"\n------ Deletion ------\n";

    for (int i = 7; i >= 1; i--)
    {
        // After Deletion, the array will be in sorted order
        // Deleted element uses the free space to store, they must will be arranged in ascending order from the left side.
        cout<<"Deleted element is: "<<Delete(H1, i)<<endl;
    }
    
    cout<<"\nAfter Deletion\n";
    for (int i = 1; i <= 7; i++){
        cout<<H1[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
