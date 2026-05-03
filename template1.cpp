#include<iostream>
using namespace std;
 template<typename T> T mymax(T x,T y)
 {
     return (x>y)? x : y;

 }
 int main()
 {
     cout<<"The Maximum value among 5 and 8 is: "<<mymax<int>(5,8)<<endl;
     cout<<"The Maximum value among 5.4 and 8.8 is: "<<mymax<double>(5.4,8.8)<<endl;
     cout<<"The Maximum value among 'A' and 'U'is : "<<mymax<char>('A','U')<<endl;
     return 0;
 }
//template function is generic — it works for different data types.
