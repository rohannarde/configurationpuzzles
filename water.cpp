// File:         $Id: water.cpp,v 1.2 2011/05/06 00:03:46 p334-70c Exp rsn5770 $
// Author:       Anand Rathod
// Description:	 Contains the main method to initiate the Water Jug puzzle and take input values from user.
// Revisions:
//              $Log: water.cpp,v $
//              Revision 1.2  2011/05/06 00:03:46  p334-70c
//              Check.
//
//              Revision 1.1  2011/04/21 22:22:03  p334-70c
//              Initial revision
//
//              Revision 1.1  2011/04/03 18:25:05  agr5046
//              Initial revision
//
//

#include "Solver.h"
#include "WaterJugPuzzle.h"
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;


int main (int argc, char *argv[] ){ 

	if( argc < 3 ){ 
    		cerr << "Invalid Number of Arguments" << endl;
   	}
	else {
		int tempValue;
		int arrSize = argc - 2;
		int destinationValue;
		vector<int> jugValues;
		vector<int> jugSizes;
		vector< vector<int> > path;

		istringstream testDestinInputValues;
		testDestinInputValues.str(argv[1]);
		destinationValue = atoi(argv[1]);
		testDestinInputValues >> tempValue;	

		// Tests inputs for validations.
		if(!testDestinInputValues.eof() || 
		testDestinInputValues.fail())
			{
				  cerr <<" Invalid Arguments Passed"
				<<endl;
				  return -1;
			}
		

		for(int i=0; i<arrSize; i++)
		{
			istringstream testInputValues;
			testInputValues.str(argv[i+2]);
			int ContainerSize = atoi(argv[i+2]);
		    testInputValues >> tempValue;	

			if(!testInputValues.eof() ||
			 testInputValues.fail())
			{
				  cerr <<" Invalid Arguments Passed"<<endl;
				  return -1;
			}

			jugValues.push_back(0);
			jugSizes.push_back(ContainerSize);
		}

		int min=jugSizes.at(0); int max=0;

		//check the conditions for jar sizes
		for(int i=0; i<jugSizes.size(); i++)
		{
			if(jugSizes.at(i)<=0)
			{
				cerr <<" Invalid Arguments Passed"
				<<endl;
				return -1;
			}
			else
			{
				if(jugSizes.at(i)>max)
					max = jugSizes.at(i);
				if(jugSizes.at(i)<min)
					min = jugSizes.at(i);
			}
		}

		//checks for the destination jar size.
		if(destinationValue < 0 || destinationValue > max)
		{
				cerr <<" Invalid Arguments Passed"<<endl;
				return -1;
		}

		// water puzzle initial object.
		WaterJugPuzzle waterJugPuzzle(0, 0,
			 destinationValue, jugValues, 
			jugSizes, path,0);

		// Solver initialized.
		Solver<WaterJugPuzzle> solver(waterJugPuzzle); 
		WaterJugPuzzle sol(solver.solve());  
			 // Checking for possible best 
		//solution.

		if (sol.IsPuzzleComplete()){ 
			cout << "Possible Best Solution :" << endl;
			vector< vector<int> > solveList(sol.pathForSolution());

			int counter =0;
			for(vector< vector<int> >::iterator iterator = solveList.begin(); 
				iterator != solveList.end(); ++iterator){
				if(counter!=0)
				{
					int values[3];
					for(unsigned int i=0; i<(*iterator).size(); i++)
						values[i] =(*iterator).at(i);

					// checks for the operations used to reach the possible
					// optimal solution for the problem.
					if(values[2]==0)
						cout<<"Fill the "<<jugSizes.at(values[0])
						<<" liter container";
					else if(values[2]==1)
						cout<<"Empty the "<< jugSizes.at(values[0]) 
						<<" liter container";
					else
						cout<<"Pour the "<<jugSizes.at(values[0])
						<<" liter container into the "
						<<jugSizes.at(values[1])<<" liter container";
				}
				counter++;
				cout<<endl;
			}
		}
		else
		{
			cout<<"No solution exists";
		}
	}
} 
