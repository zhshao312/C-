#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//valid function to test the filled numbers are valid
bool valid( int* q, int c ){
    //set up numbers
    int values[][5] = {
        { -1 }, { 0, -1 }, { 0, -1 }, { 0, 1, 2, -1 }, { 0, 1, 3, -1 }, { 1, 4, -1 }, { 2, 3, 4, -1 }, { 3, 4, 5, 6, -1 }};
    
    //row-test
    for ( int i = 0 ; i < c ; ++i )
        if ( q[i] == q[c] )
            return false;
    //adjacent-test
    for ( int i = 0 ; values[c][i] != -1 ; ++i )
    {
        if (abs( q[c] - q[ values[c][i] ] ) == 1 )
            return false;
    }
    return true;
}
//print function
void print(int* q){
    cout << "Answers : " <<  endl;
    cout << " " << q[0] << q[1] << endl;
    cout << q[2] << q[3] << q[4] << q[5] << endl;
    cout << " " << q[6] << q[7] << " ";
    cout << endl << endl;
}
//move function
void move(int* q, int i) 
{	
	//if 8 numbers are set, go to print results
    if(i==8)
    {
        print(q); 
        return;
    }
    //if numbers input, fo valid function, then move
    for(int j=0;j<8;j++) 
    { q[i]=j;
        if(valid(q,i)) 
            move(q,i+1);
    }
    // no value of j worked so return;
}

//main function
int main(){
    int q[8];
    move(q,0);
    return 0;
}


