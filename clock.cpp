// File:         $Id: clock.cpp,v 1.2 2011/05/06 00:03:46 p334-70c Exp rsn5770 $
// Author:       Anand Rathod
// Description:  Contains the main method to initiate the clock puzzle and take input values from user.
// Revisions:
//              $Log: clock.cpp,v $
//              Revision 1.2  2011/05/06 00:03:46  p334-70c
//              Check.
//
//              Revision 1.1  2011/04/21 22:22:03  p334-70c
//              Initial revision
//
//              Revision 1.1  2011/04/21 19:42:24  agr5046
//              Initial revision
//
//              Revision 1.1  2011/04/03 18:25:05  agr5046
//              Initial revision
//
//

#include "Solver.h"
#include "ClockPuzzle.h"
#include <sstream>
#include <cstdlib>
#include <string>
using namespace std;


int main (int argc, char *argv[] ){ 

  int noOfHoursOnDial;
  int initialTime; 
  int destinationTime;


  if( argc != 4 ){ 
    cerr << "Invalid Number of Arguments" << endl;
  }

  else{
	  //Check whether input Values are valid or not.
	  istringstream testInputValues[3];
	  testInputValues[0].str(argv[1]);
	  testInputValues[1].str(argv[2]);
	  testInputValues[2].str(argv[3]);
	  int tempValue;

	  noOfHoursOnDial = atoi(argv[1]);
         initialTime = atoi(argv[2]);
         destinationTime = atoi(argv[3]);

	  testInputValues[0] >> tempValue;
	  testInputValues[1] >> tempValue;
	  testInputValues[2] >> tempValue;

	  // Check for validation of values.
	  for(int i=0; i<3; i++)
	  {
		  if(!testInputValues[i].eof() || testInputValues[i].fail())
		  {
			  cerr <<" Invalid Arguments Passed"<<endl;
			  return -1;
		  }
	  }
    
      // Check for zero condition.(hours should be greater than zero)
      if(initialTime <= 0 || noOfHoursOnDial <= 0 || destinationTime <= 0)
		cerr << "Hours Values should be greater than Zero" << endl;
    
      // Check whether values entered are proper or not.
      else if( initialTime > noOfHoursOnDial || destinationTime > 
				noOfHoursOnDial)
		cerr << "Invalid configuration of hour values" << endl;

      else
	  {
		list<int> tempList; 
		ClockPuzzle clockPuzzle(initialTime, destinationTime,
		 noOfHoursOnDial, 
		tempList);
		Solver<ClockPuzzle> solver(clockPuzzle); 
		ClockPuzzle sol(solver.solve());   // Checking for 
							//possible best solution.

		if (sol.IsPuzzleComplete()){ 
			int counter = 1;
			cout << "Possible Best Solution :" << endl;
			list<int> solveList(sol.pathForSolution());
        
			for(list<int>::iterator iterator = 
			solveList.begin(); 
			iterator != solveList.end(); ++iterator){
				cout << "Step" << counter << " : " <<
				 *iterator << endl;
				++counter;
			}
		}
		else
			cout << "There is no solution for given problem" 
				<< endl;
	  }
	}
} 
