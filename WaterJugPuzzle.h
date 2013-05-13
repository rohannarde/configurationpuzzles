// File:         $Id: WaterJugPuzzle.h,v 1.2 2011/04/21 22:35:04 rsn5770 Exp rsn5770 $
// Author:       Anand Rathod Rohan Narde
// Description:	Provides the method implementation for Water Jug problem solving.
// Revisions:
//              $Log: WaterJugPuzzle.h,v $
//              Revision 1.2  2011/04/21 22:35:04  rsn5770
//              Indentations revised , methods added
//
//              Revision 1.1  2011/04/21 22:22:13  p334-70c
//              Initial revision
//
//              Revision 1.1  2011/04/03 18:25:05  agr5046
//              Initial revision
//
//

#ifndef WATER_PUZZLE_H
#define WATER_PUZZLE_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;


class WaterJugPuzzle{

private: 

  double index;
  int currentContainerIndex; 
  int destinationContainerIndex; 
  int finalDestinationValue;
  vector<int> containerValues;
  vector<int> containerSizes;
  vector< vector<int> > pathForDestination;
  int operation;

 public:  

  // Constructor for input of currentJug, destination jug positions, the final 
  //value to achieve, and vectors 
  // for storing the values for container sizes and amount of water in them.
	 WaterJugPuzzle(const int & currentJugIndex, const int & destinationJugIndex,
		 const int & finalValue, const vector<int> &jugValues, 
		 const vector<int> &jugSizes , const vector< vector<int> > & path,
	     const int & oper);
  
  // condition to check whether the conditions are met or not.
  bool IsPuzzleComplete() const;
  
  // Returns the trace of path for solution.
  vector< vector<int> > pathForSolution() const;
  
  // Returns the possible moves for that point.
  void getPossibleMoves(list<WaterJugPuzzle> & possibleMoves);
  
  // Overloaded == operator for compairsion.
  bool operator==(WaterJugPuzzle & check) const;

    // Overloaded < operator for comparision.
  bool operator<(const WaterJugPuzzle & check) const;

  // Destructor.
  ~WaterJugPuzzle();  
};
#endif
