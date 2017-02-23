// Shao, Zihao
// CS211 Section 52B Homework 4

#include <iostream>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

//Invalid function
bool invalid(string input){
   string team="";
   
   //check the size of input 
   for(int i=0; i < input.size(); i++)
      if(team.find(input[i]) > input.size())
         team = team + input[i];
   if(team.size() <= 1)
     return true;
   
   //count the number of players and check the team names are follow the rule.    
   int* count = new int[team.size()]();
   for(int i=0; i < input.size(); i++)
      for(int j=0; j < team.size(); j++)
         if(input[i] == team[j])
            count[j]++;
   for(int i=1;i < team.size();i++)
      if(count[i]!= count[0]){ 
         delete [] count;
         return true;
      }
   return false;
}


//result function
void result(string input){ 
   string team="";
  
   //count how many teams and how many players in each team.
   for(int i=0; i < input.size(); i++)
      if(team.find(input[i]) > input.size())
         team = team + input[i];
   
   //print the number    
   cout<< "There are " << team.size() << " teams." << endl;
   cout<< "Each team has " <<input.size()/team.size()<< " players." <<endl; 
   int* count = new int[team.size()]();
   
   //compute the final score for each team
   for(int i=0; i < input.size(); i++)
      for(int j=0; j < team.size(); j++) 
         if(input[i] == team[j])
            count[j] = count[j] + i + 1; cout << "Team Score" << endl;
   
   //print the score
   for(int i=0;i<team.size();i++)
      cout<< " " << team[i] << " " << (double)count[i]/(input.size()/team.size()) << endl;
   delete [] count; 
 }
//main function
int main(){
   string input;
   
   //ask user to input the team name
   cout << " Enter the team name, each team has a name(uppercase letter A-Z)." <<endl;
   cout << " Teams can't have same name,the number of players for each team should same";
   cin >> input;
   
   //go invalid function to check the input is valid or not.
   while(invalid(input)){
      cout << "It's invalid input, please re-enter the team score.";
      cin >> input; 
   }
   //go result function to count number of players, compute the scores and print them.
   result(input);
   return 0;
	
}

