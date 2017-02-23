// Shao, Zihao
// CS211 Section 52B Homework 3

#include <iostream>
    using namespace std;  
    
int main() {
	
	/*board section*/	
	int b[8][8] = {0}, 				
		r,							
   		c = 0;						
		b[0][0] = 1;				
	/*create 8x8 board, putting 1st queen on up-left corner*/
	
	
	/*column section*/ 
	nc:
		c++; 						
		if (c == 8) 				
		goto print; 				
		r = -1; 
	/*add column position, solutions for columns 0 through 7 found, go print section*/
	/*otherwise start at the first position of the column*/					
	
	
	/*row section*/
	nr:
		r++; 						
		if (r == 8) 				
		goto backtrack; 			
 	/*add row position, try every row of current column, go backtrack section*/
 		
 		//row test
 		for (int i = 0; i < c; ++i)
			if (b[r][i] == 1) 		
				goto nr; 			
 		/*if another queen on same row, go to the next row*/
 		
 		//up diagonal test
 		for (int i = 1; (r-i) >= 0 && (c-i) >= 0; ++i)
			if (b[r-i][c-i] == 1) 	
        	goto nr;      	
 		/*if another queen on up-diagonal, go to the next row*/
 		
 		//down diagonal test	
 		for (int i = 1; (r+i) < 8 && (c-i) >= 0; ++i)
			if (b[r+i][c-i] == 1) 	
			goto nr; 			
 		/*if another queen on down-diagonal, go to the next row*/
		
		b[r][c] = 1; 				
		goto nc; 					
		/*no conflicts found, place the queen, go to next column*/
	
	/*backtrack section*/
	backtrack:
		c--; 						
		if (c == -1)			 	
		return 0; //stop program
		/*go back one column, if past first column, all solutions found*/
		
		r = 0;						
		while (b[r][c] != 1)		
  		r++;						
		b[r][c] = 0;				
		goto nr;					
		/*start looking first row, while we haven’t found the queen, go to the next row of current column*/
 
	/*print section*/
 	print: 	
	cout << "Solution #: " << count <<  endl;
		for (int i=0; i<8; i++){
			for (int j=0; j<8; j++){
				cout << b[i][j] << ' ';
			}
		cout << endl;
		}
		count++;
		cout << endl;
		goto backtrack;

}