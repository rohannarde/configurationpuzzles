// File:         $Id: ClockPuzzle.cpp,v 1.2 2011/04/21 22:32:16 rsn5770 Exp rsn5770 $
// Author:       Anand Rathod Rohan Narde
// Description:	Provides the method implementation for clock problem solving.
// Revisions:
//              $Log: ClockPuzzle.cpp,v $
//              Revision 1.2  2011/04/21 22:32:16  rsn5770
//              Tested methods , checked
//
//              Revision 1.1  2011/04/21 22:22:03  p334-70c
//              Initial revision
//
//              Revision 1.1  2011/04/21 19:43:56  agr5046
//              Initial revision
//
//              Revision 1.1  2011/04/03 18:25:05  agr5046
//              Initial revision
//
//

#include "ClockPuzzle.h"
using namespace std;

// Constructor for input of initial time, destination time and number
// of hours on the dial.
ClockPuzzle::ClockPuzzle(const int &initialTime, const int &destinationTime,
                         const int &noOFHours, const list<int> &path)
  :currentTime(initialTime), finalTime(destinationTime), hoursOnDial(noOFHours),
   pathForDestination(path){
  pathForDestination.push_back(currentTime);
}

// condition to check whether the conditions are met or not.
bool ClockPuzzle::IsPuzzleComplete() const{
  return currentTime == finalTime;
}

// Returns the trace of path for solution.
list<int> ClockPuzzle::pathForSolution() const{
  return pathForDestination;
}
  
// Returns the possible moves for that point.
void ClockPuzzle::getPossibleMoves(list<ClockPuzzle>  & possibleMoves){

  if(currentTime == 1)
  {  
    ClockPuzzle front(currentTime + 1, finalTime, hoursOnDial, pathForDestination);
    possibleMoves.push_back(front); 
    ClockPuzzle back(hoursOnDial, finalTime, hoursOnDial, pathForDestination);
    possibleMoves.push_back(back);
  }
  else if(currentTime == hoursOnDial)
  {
    ClockPuzzle front(1, finalTime, hoursOnDial, pathForDestination);
    possibleMoves.push_back(front);
    ClockPuzzle back(currentTime - 1, finalTime, hoursOnDial, pathForDestination);
    possibleMoves.push_back(back);
  }
  else
  {
    ClockPuzzle front(currentTime + 1, finalTime, hoursOnDial, pathForDestination);
    possibleMoves.push_back(front); 
    ClockPuzzle back(currentTime - 1, finalTime, hoursOnDial, pathForDestination);
    possibleMoves.push_back(back);
  }
}

// Overloaded == operator for compairsion.
bool ClockPuzzle::operator==(ClockPuzzle & check) const{
  return currentTime == check.currentTime;
}

// Overloaded < operator for comparision.
bool ClockPuzzle::operator<(const ClockPuzzle & check) const{
  return currentTime < check.currentTime;
}

// Destructor.
ClockPuzzle::~ClockPuzzle(){
}
