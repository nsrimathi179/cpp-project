#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream file("data.txt");
    int n;
    cout<<"Enter the no.of.students: ";
    cin>>n;

    string name;
    char grade;
    int marks;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the Name and Marks: "<<endl;
        cin>>name>>marks;

        if(marks >= 80){
            cout<<"grade A";
        }else if(marks >=50){
            cout<<"grade B";
        }else{
            cout<<"grade C";
        }

        file<<name<<" "<<marks<<" "<<grade<<endl;
        file.close();

        return 0;
    }


}
