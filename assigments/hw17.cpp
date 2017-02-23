// Shao, Zihao
// CS211 Section 52B Homework 17

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
    ifstream in("input.txt");
    int numRows, temp;
    in >> numRows; // Read the number of Rows from the file.
    for (int i = 1; i <= numRows; ++i) { // For each row i,
        in >> temp;                //read row number
        int steps = 0;             // Initialize the number of steps.
        vector<int> height;// Initialize a container (e.g. array, vector whatever you think will be most useful).
        for (int j = 1; j <= 20; ++j) { // For each of the 20 students,
             in>>temp;          // Read the height from the file.
            	height.push_back(temp);
            	
            	for(vector<int>::iterator i= height.begin(); i != height.end(); ++i)
         		if(*i > temp){
         			height.pop_back();
         			i=height.insert(i, temp);
         			i++;
         		
         			steps += ((height.end())-i);
         			
         			break;
         		
         		}
         }// Calculate the number of steps, update steps, and add the height to the container.
         cout << i << " " << steps << endl;   // Print the row number followed by the number of steps.
     	 height.clear();
     }
     in.close();
     return 0;
 }
