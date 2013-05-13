//
// Revisions:
// $Log: progstyle-cpp-2009.html,v $




#include <list>
#include "WordPuzzle.h"
using namespace std;




//
//	WordPuzzle
//
WordPuzzle::WordPuzzle(const string startWord,
                       const string _finalWord,
                       const vector<string> & path,const set<string > &dic)
    : initialWord(startWord),
    finalWord(_finalWord), pathForDestination(path),wordSet(dic)
{
}


//
//	getPossibleMoves
//
void WordPuzzle::getPossibleMoves(list<WordPuzzle>
                                  & possibleMoves) const
{
    
    const int sizeOfWord = initialWord.size();
    const int sizeOfaToz = toCheck.size();
    //cout<<"to check "<<toCheck<<endl;
    for(unsigned int i=0; i < sizeOfaToz ; ++i)
    {
        for(int j=0; j < sizeOfWord; ++j)
        {
            string tempString = initialWord;
            tempString[j] = toCheck[i];
	    //if(wordSet.find(tempString) != wordSet.end())	
            if(checkValidWord(tempString))
            {

                WordPuzzle
                move(tempString,finalWord,pathForDestination,wordSet);
                move.addMove(tempString);
                possibleMoves.push_back(move);

            }
        }

    }
}



//
//	~WordPuzzle
//
WordPuzzle::~WordPuzzle()
{
}



//
//	checkValidWord
//
bool WordPuzzle::checkValidWord( const string check) const
{
    //cout<<"wordset "<<wordSet.size()<<endl;
    if(wordSet.find(check) != wordSet.end())
        return true;
    else
        return false;
}