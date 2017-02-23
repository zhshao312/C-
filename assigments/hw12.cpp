// Shao, Zihao
// CS211 Section 52B Homework 12

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

typedef double (*FUNC)(double);

//integrate function
double integrate(FUNC f, double a, double b){
    double area=0;
    for (double i=a; i<=b; i+=.0001)
        area+=f(i)*.0001;
    return area;
};

double line(double x){
    return x;
}

double square(double x){
    return x*x;
}

double cube(double x){
    return x*x*x;
}
//main function
int main() {
    cout<< "The integral of f(x)=x between 1 and 5 is: "<<integrate(line, 1, 5)<<endl;
	cout<< "The integral of f(x)=x^2 between 1 and 5 is: "<<integrate(square, 1, 5)<<endl;
	cout<< "The integral of f(x)=x^3 between 1 and 5 is: "<<integrate(cube, 1, 5)<<endl;
    return 0;
}