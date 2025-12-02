#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of students\n";
    cin>>n;

    int marks[50];
    cout<<"Enter previous yeaar marks of students\n";
    for(int i = 0;i<n;i++)
    {
        cin>>marks[i];
    }
    cout<<"\nBubble Sort pass by pass analysis\n";

    for(int pass = 0;pass<n-1;pass++)
    {
        for(int i = 0;i<n-pass-1;i++)
        {
            if(marks[i]<marks[i+1]){
            {
                int temp = marks[i];
                marks[i] = marks[i+1];
                marks[i+1] = temp;
            }
        }
    }
    cout<<"After pass "<<pass+1<<"; ";
    for(int j = 0;j<n;j++)
    {
        cout<<marks[j]<<" ";
    }
    cout<<endl;

}
cout<<"\n Assigned Roll Numbers\n";
for(int i = 0;i<n;i++)
{
    cout<<"Roll No: "<<i+1<<" -> Marks: "<<marks[i]<<endl;
}
return 0;
}
