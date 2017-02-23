// Shao, Zihao
// CS211 Section 52B Homework 1
// Question 1  

#include <iostream>
using namespace std;
int main() {
	for (int i=4; ; i++){ // the program in theory will run infinitely because no such # exists 
		if (((i*i)%10)%2!=0 && (((i*i)%100)/10)%2!=0){ // tests the last two digits to see if it is odd
			cout << i*i << endl;
			break;
		}		
	}
return 0;
}
//perfect square