// Swapping two variables in cpp


#include <iostream>
using namespace std; 
int main(){ 
    cout<<"Enter a number 1:"<<endl;
    int a; 
    cin>>a;
    cout<<"ENTER A NUMBER:"<<endl; 
    int b; 
    cin>>b;
    for(int i=0; i<10; i++){ 
        int temp; 
        temp = b; 
        b = a; 
        a= temp;
        cout << "Loop Number: " <<i+1<<"\n";
        cout<<"The value of a is: "<<a<<endl;
        cout<<"The value of b is: "<<b<<endl;
    }
}
