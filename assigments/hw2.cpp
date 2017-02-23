// Shao, Zihao
// CS211 Section 52B Homework 2
// Question 1

#include <iostream>
using namespace std;
void rightShift(int a[], int length)
{
        int temp = a[length-1];
        for(int i=length-1;i>0;i--)
                a[i] = a[i-1];
        a[0] = temp;
}

bool equivalent(int a[], int b[], int length)
{
        bool equal = true;
        for(int i=0;i<length;i++)
                if(a[i]!=b[i])
                        equal = false;
        return equal;
}
int main()
{
        int a[5] = {1,2,3,4,5};
        int b[5] = {2,3,4,5,1};
        bool equal = false;
        for(int i=0;i<5;i++)
        {
                if(equivalent(a,b,5))
                        equal = true;
                rightShift(a,5);
        }
        if(equal)
                cout<<"a and b are equivalent"<<endl;
        else
                cout<<"a and b are not equivalent"<<endl;
        return 0;
}
