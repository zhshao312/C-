#include <iostream>
#include <cmath>
using namespace std;

/* print function */
void print(int b[], int count){
	cout << "\nAnswers #: " << count++ << endl;
        int r=0;
        while (r<8){
        	for (int i=0; i<8; i++){
                	if (r==b[i])
                        	cout << 1 << ' ';
                        else
                        	cout << 0 << ' ';
                }
        cout << endl;
        r++;
        }
        cout << endl << endl;

}
/* main function */
int main(){
	//set board, start at 0 column.
	int col=0, b[8], count = -1;
	b[0] = 0;

	while(true){
        	col++;
        	if(col==8){
           		++count;
           		print(b,count); // while all columns used correctly, go print function
           		col--;
        	}
        else
        	b[col] = -1;
        	for( ; ; ){
                	b[col]++;
               		if(b[col]==8){
                   		col--;
                   		if(col==-1)
                        		return 0;
                   		else
                        		continue;
                	}
                bool nr = false; //set next row boolean false
                for(int i=0;i<col;i++){
                	if(b[col]==b[i] || col-i == abs(b[col]-b[i])){
                        	nr = true;
                        	break;
                   	}
                }
                if(nr)
                	continue;
                break;
           	}
	}
return 0;
}
