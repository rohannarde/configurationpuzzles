// File:         $Id: Solver.h,v 1.2 2011/05/06 00:12:43 rsn5770 Exp $
// Author:       Anand Rathod
// Description:	 Provides the methods for generic problem solver.
// Revisions:
//              $Log: Solver.h,v $
//              Revision 1.2  2011/05/06 00:12:43  rsn5770
//              Indentations checked.
//
//              Revision 1.1  2011/04/21 22:22:13  p334-70c
//              Initial revision
//
//              Revision 1.1  2011/04/21 19:32:34  agr5046
//              Initial revision
//
//              Revision 1.1  2011/04/03 18:25:05  agr5046
//              Initial revision
//
//


#ifndef SOLVER_H
#define SOLVER_H

#include <list>
#include <set>
#include <vector>
#include <queue>
using namespace std;
// Templates
template<class T>
class Solver{

	private:
		queue<T> possibleMoves;  //Keeps track of possible moves.
		vector<T> movesParsed;      // Keeps track of moves that are encountered.
		T move;                  // the Move that we are solving.
		bool IsCompleted;        // Keeps track whether the solver is finished or not.
		list<T> nextMove;        // The next move
		
		bool checked(T puzzle);  // used to keep track of configurations
						         // that are already encountered.

	public: 
		Solver(T puzzle);
		~Solver();
		T solve();
};


// Creating a Solver and Initializing the values with completed as false.
template<class T>
Solver<T>::Solver(T puzzle):move(puzzle), IsCompleted(false){  
	possibleMoves.push(move); //push the move to possible moves quque.
	movesParsed.push_back(move); // Insert move in set once it is parse.
}

// used to keep track of configurations
template <class T>
bool Solver<T>::checked(T puzzle){ 

	// returns false if the condition is already encountered, else returns true by default. 
	int flag =0;
	for(unsigned int i=0; i<movesParsed.size(); i++)
	{
		if(movesParsed.at(i) == puzzle)
		{
			flag =1;
			break;
		}
	}

	if(flag==0)
	{
		movesParsed.push_back(puzzle);
		return false;
	}
	else
		return true;
}

template<class T>
T Solver<T>::solve(){

  // executes until we have reached the end of possible Moves.
  while(!possibleMoves.empty()  &&  !IsCompleted){
    if(possibleMoves.front().IsPuzzleComplete()){
      IsCompleted = true;  // returns true and breaks if puzzle is solved.
      break;
    }
    else{
     // If winning condition is not reached, go to next move.
      possibleMoves.front().getPossibleMoves(nextMove); 
      possibleMoves.pop();

      // Iterator for parsing through list.
      for( typename list<T>::iterator iterator = nextMove.begin(); iterator != nextMove.end(); ++iterator){
        if(!Solver::checked(*iterator)){
          possibleMoves.push(*iterator);
        }
      }

	  // clears next move.
      nextMove.clear();
    }
  }

  // Checks whether we have competed solving the puzzle or not. If yes returns the front or else
  // returns the move.
  if(IsCompleted)
    return possibleMoves.front();
  else
    return move;
}

// Destructor
template<class T>
Solver<T>::~Solver()
{
}

#endif
