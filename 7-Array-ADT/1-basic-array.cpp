// #include<iostream>
// using namespace std;

// class Array{
//     public:
//     int A[20];
//     int size;
//     int length;
// };

// void Display(Array arr){
//     cout<<"Elements are: ";
//     for (int i = 0; i < arr.length; i++)
//     {
//         cout<<arr.A[i]<<" ";
//     }
    
// }

// int main(){

//     Array arr = {{2,3,4,5,6}, 20, 5};

//     Display(arr);   
    
//     return 0;
// }

#include<iostream>
using namespace std;
int main()
{
    int size;
    int a[100];
    cout<<"Enter the size of an array"<<endl;
    cin>>size;
    cout<<"Enter the element in an array"<<endl;
     for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    cout<<"Display the elements in an array"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<a[i];
    }
    return 0;
}
