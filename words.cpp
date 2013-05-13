
#include "Solver.h"
#include "WordPuzzle.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <algorithm>

#include <vector>
#include <set>


using namespace std;

// Main starts here
int main(int argc, char *argv[])
{
	// The string to store the startWord
	string startWord;
	// The string to store the final Word
	string finalWord;
	if(argc != 4)
        {
                cout<<"Usage: ./words startWord finalWord dictFile"<<endl;
                return -1;
        }

	startWord = argv[1];
	finalWord = argv[2];
	// The Size of the word to reduce size of the dictionary 	
	const int sizeFilter = startWord.size();
	// the set to store all the words
	set< string > wordSet1;
	// the initial path storing container
	vector < string > movesMade;
	// the string to store the words from the file one at a time
	string line;
	string aToz = "abcdefghijklmnopqrstuvwxyz";

	// improper word size 
	if(startWord.size() != finalWord.size())
        {
                cout<<"Enter same length strings"<<endl;
                return -1;
        }
	
	// File operations
  	ifstream myfile;
	myfile.open(argv[3]);
  	if (myfile.is_open())
  	{
  		while ( myfile.good() )
    		{
      			getline (myfile,line);
      			if(line.size() == sizeFilter && islower(line[0]))
			wordSet1.insert(line);
    		}
		
    		myfile.close();
  	}
  	else 
	{
		cout << "Unable to open file";
		cout<<endl; 
		return -1;
	}
	//cout<<"Wordset size "<<wordSet1.size()<<endl;
	// Again , validation testing
	
	for(int i=0;i< sizeFilter;i++)
	{
			if(isdigit(startWord[i]))
			{
				cout<<"Invalid lower-case word"<<endl;
				return -1;
			}
	}
	for(int i=0;i< sizeFilter;i++)
        {
                        if(isdigit(finalWord[i]))
                        {
                                cout<<"Invalid lower-case word"<<endl;
                                return -1;
                        }
        }
	

	//Pushing start word in the vector path
	movesMade.push_back(startWord);
	
	// creating the first wordPuzzle object with start values
	WordPuzzle 
	wordPuzzle(startWord,finalWord,movesMade,wordSet1);

	wordPuzzle.setWordSet(wordSet1);
	wordPuzzle.setCheck(aToz);
	// Initializing the solver
	Solver<WordPuzzle> solver = wordPuzzle;
	WordPuzzle sol = solver.solve();
	// After solver terminates
	if(sol.IsPuzzleComplete())
	{
		cout<<"Solution found, printing.."<<endl;
		vector< string > path = sol.pathForSolution();
		vector< string >::const_iterator it;
		
		for(it = path.begin() ; it != path.end() ; ++it)
		{
			cout<<"STATE: "<<*it<<endl;
		}
		
	}	
	else
	{
		cout<<"No Solution Possible"<<endl;
	}
	
	return 0;
}