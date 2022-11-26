// Write a program to create a class template having a an array and perform the following menu based operation of integer array and floating point array on objects of the class template.
// I. Search an user entered element
// II. Sum of all the elements
// III. Find 2nd largest element and 2nd minimum element.

#include<iostream>
using namespace std;

template<class T>

class Array
{
    T arr[10];
    int n;
    public:
    void getdata(){
        cout<<"Enter the size of the array: ";
        cin>>n;
        cout<<"Enter the elements of the array: ";
        for(int i=0;i<n;i++)
            cin>>arr[i];
    }
    void search(){
        T key;
        cout<<"Enter the element to be searched: ";
        cin>>key;
        for(int i=0;i<n;i++){
            if(arr[i]==key){
                cout<<"Element found at position "<<i+1<<endl;
                return;
            }
        }
        cout<<"Element not found"<<endl;
    }
    void sum(){
        T s=0;
        for(int i=0;i<n;i++)
            s+=arr[i];
        cout<<"Sum of all the elements is: "<<s<<endl;
    }
    void second(){
        T max1=arr[0],max2=arr[0],min1=arr[0],min2=arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]>max1){
                max2=max1;
                max1=arr[i];
            }
            else if(arr[i]>max2)
                max2=arr[i];
            if(arr[i]<min1){
                min2=min1;
                min1=arr[i];
            }
            else if(arr[i]<min2)
                min2=arr[i];
        }
        cout<<"Second largest element is: "<<max2<<endl;
        cout<<"Second smallest element is: "<<min2<<endl;
    }
};

int main()
{
    int ch;
    cout<<"Enter 1 for integer array and 2 for floating point array: ";
    cin>>ch;
    if(ch==1){
        Array<int> a;
        a.getdata();
        cout<<"Enter 1 to search, 2 to find sum and 3 to find second largest and second smallest element: ";
        cin>>ch;
        switch(ch){
            case 1: a.search();
                    break;
            case 2: a.sum();
                    break;
            case 3: a.second();
                    break;
            default: cout<<"Invalid choice"<<endl;
        }
    }
    else if(ch==2){
        Array<float> a;
        a.getdata();
        cout<<"Enter 1 to search, 2 to find sum and 3 to find second largest and second smallest element: ";
        cin>>ch;
        switch(ch){
            case 1: a.search();
                    break;
            case 2: a.sum();
                    break;
            case 3: a.second();
                    break;
            default: cout<<"Invalid choice"<<endl;
        }
    }
    else
        cout<<"Invalid choice"<<endl;
    return 0;
}
