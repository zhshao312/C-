// Shao, Zihao
// CS211 Section 52B Homework 21
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//value of fraction method
double value_of_fraction(int array[]){
    int length = 0;
    while(array[++length]!=-1);
    double result = array[length-1];
  
    for(int k=length-2; k>=0; k--){
   		result = (array[k] + 1/result);
    }
    return result;
}

//continued_fraction method
double continued_fraction(int v[],int array[]){
   int length = 0;
   while(array[++length]!=-1);
   double result = array[length-1];
   v[1] = 1;
   v[0] = array[length-1];
   
   for(int k=length-2; k>=0; k--) {
    	int temp = v[1];
    	v[1] = v[0];
   	    v[0] = v[0]*array[k]+temp;
   }
}

//compute gcd
int gcd(int a,int b){
   if(b == 0) return a;
   else return gcd(b,a%b);
}

//reduced method
void reduced(int v[]){
   int temp = gcd(v[0],v[1]);
   v[0] = v[0]/temp;
   v[1] = v[1]/temp;
}

//main
int main(){
   int array[] = {1,2,3,4,5,-1};
   int v[2];
   cout << "Value of fraction is " << value_of_fraction(array) << endl;
   continued_fraction(v,array);
   cout << "Numerator of Value of fraction is " << v[0] << endl;
   cout << "Denominator of Value of fraction is " << v[1] << endl;
   return 0;
}