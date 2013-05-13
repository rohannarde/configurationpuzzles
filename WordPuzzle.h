// $Id: WordPuzzle.h,v 1.3 2011/05/14 00:10:38 rsn5770 Exp rsn5770 $
//
// Revisions:
// $Log: WordPuzzle.h,v $
// Revision 1.3  2011/05/14 00:10:38  rsn5770
// Commented properly
// vector sued for checked visited
//




#ifndef WORD_PUZZLE_H
#define WORD_PUZZLE_H


#include <iostream>
#include <string>


#include <vector>
#include <algorithm>
#include <set>
#include <list>


static std::string toCheck = "abcdefghijklmnopqrstuvwxyz";
/**
 * The class that models the word ladder puzzle
 *
 * @author  Rohan Narde
 *
 */

class WordPuzzle
{

private:
    // The initial word
    std::string initialWord;
	int x;
	int y;
	std::vector<int> validMoves;
    // The final word
    std::string finalWord;
    // The path
    std::vector <std::string> pathForDestination;
    // The wordset
    std::set < std::string > wordSet;

public:
    /**
     *
     *  Adds a string to the move list
     * @param  the string to add to the object
     * @return none
     * @pre none
     * @post none
     * @throws none
     */
    void addMove(std::string temp);
public:
    /**
     *	WordPuzzle initalizer with startword , final word
     * the path and the dictionary
     * @param the current word
    * @param the final word
    * @param the path
    * @param  the dictionary
     * @return none
     * @pre none
     * @post none
     * @throws none
     */
    WordPuzzle(const std::string startWord, const std::string finalWord,
               const std::vector< std::string > & path,
               const std::set<std::string > &dictionary);

public:
    /**
     *   Checks for puzzle completion
     *
     * @param none
     * @return true if final word == current word
     * @pre none
     * @post none
     * @throws none
     */
    // Check for puzzle completion
    bool IsPuzzleComplete() const;
public:
    /**
     *   Checks if the word is there in the wordSet dictionary
     *
     * @param the string to check with
     * @return true if it is a valid word
     * @pre none
     * @post none
     * @throws none
     */
    // used to check the dictionary for valid words
    bool checkValidWord(const std::string check) const;
public:
    /**
     *
     *
     * @param
     * @return
     * @pre
     * @post
     * @throws
     */
    // Returns the trace of path for the solution.
    std::vector< std::string > pathForSolution() const;
public:
    /**
     *  get next moves in the list
     *
     * @param the list containing current moves
     * @return none
     * @pre none
     * @post none
     * @throws none
     */
    // Returns the possible moves for that point.
    void getPossibleMoves(std::list<WordPuzzle> & possibleMoves) const;
public:
    /**
     * overloaded == operator
     *
     * @param the object to check with
     * @return true if they are equal
     * @pre none
     * @post none
     * @throws none
     */
    // Overloaded == operator.
    bool operator==(const WordPuzzle & check) const;
public:
    /**
     *	overloaded < operator
     *
     * @param the object to check
     * @return true if calling object is greater
     * @pre none
     * @post none
     * @throws none
     */
    // Overloaded < operator.
    bool operator<(const WordPuzzle & check) const;
public:
    /**
     *	destructor
     *
     * @param none
     * @return none
     * @pre none
     * @post none
     * @throws none
     */
    ~WordPuzzle();

public:
    /**
     *  sets the word set with the dictionary
     *
     * @param the set to initialize with
     * @return none
     * @pre none
     * @post none
     * @throws none
     */
    void setWordSet(std::set<std::string> saa);
public:
    /**
     *	sets the string from a-z
     *
     * @param the string from a-z
     * @return none
     * @pre none
     * @post none
     * @throws none
     */
    void setCheck(std::string s);
};
//
//	setCheck
//
inline void WordPuzzle::setCheck(std::string s)
{
    toCheck = s;
}

//
//	addMove
//
inline void WordPuzzle::addMove(std::string temp)
{
    pathForDestination.push_back(temp);
}

//
//	isPuzzleComplete
//
inline bool WordPuzzle::IsPuzzleComplete() const
{
    return initialWord == finalWord;
}

//
//	pathForSolution
//
inline std::vector<std::string> WordPuzzle::pathForSolution() const
{
    return pathForDestination;
}

//
//	operator==
//
inline bool WordPuzzle::operator==(const WordPuzzle & check) const
{
    return initialWord == check.initialWord;
}

//
//	operator <
//
inline bool WordPuzzle::operator<(const WordPuzzle & check) const
{
    return initialWord < check.initialWord;
}

//
//	setWordSet
//
inline void WordPuzzle::setWordSet(std::set<std::string> saa)
{
    wordSet = saa;
}

#endif

