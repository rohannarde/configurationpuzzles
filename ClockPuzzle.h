// File:         $Id: ClockPuzzle.h,v 1.2 2011/04/21 22:25:23 rsn5770 Exp rsn5770 $
// Author:       Anand Rathod Rohan Narde
// Description:  Provides the method declaration for clock problem solving.
// Revisions:
//              $Log: ClockPuzzle.h,v $
//              Revision 1.2  2011/04/21 22:25:23  rsn5770
//              const methods checked
//
//              Revision 1.1  2011/04/21 22:22:13  p334-70c
//              Initial revision
//
//              Revision 1.1  2011/04/21 19:44:06  agr5046
//              Initial revision
//
//              Revision 1.1  2011/04/03 18:25:05  agr5046
//              Initial revision
//
//

#ifndef CLOCK_PUZZLE_H
#define CLOCK_PUZZLE_H


#include <iostream>
#include <string>
#include <list>
using namespace std;


class ClockPuzzle{

private: 
  int currentTime; 
  int finalTime; 
  int hoursOnDial; 
  list<int> pathForDestination;

 public:  

  // Constructor for input of initial time, destination time and number
  // of hours on the dial.
  ClockPuzzle(const int & initialTime, const int & destinationTime,
               const int & noOFHours, const list<int> & path);
 public: 
  
  // condition to check whether the conditions are met or not.
  bool IsPuzzleComplete() const;
  
  // Returns the trace of path for solution.
  list<int> pathForSolution() const;
  
  // Returns the possible moves for that point.
  void getPossibleMoves(list<ClockPuzzle> & possibleMoves);
  
  // Overloaded == operator for compairsion.
  bool operator==(ClockPuzzle & check) const;
  
  // Overloaded < operator for comparision.
  bool operator<(const ClockPuzzle & check) const;

  // Destructor.
  ~ClockPuzzle();  
};
#endif
