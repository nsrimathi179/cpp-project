#include<iostream>
using namespace std;

class exceptionmarks{
    public:
    const char* what(){
        cout<<"Invalid charecters. "<<endl;
    }
};
int main(){
    int marks;
    cout<<"Enter the marks: ";
    cin>>marks;

    try{
        if(marks>100 || marks<0){
           throw exceptionmarks();
        }
    }
    catch( exceptionmarks e){
       cout<<e.what()<<endl;
    }
return 0;

}
