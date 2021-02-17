#ifndef M2OEP_CLASS_RELATIONSHIPS_NFLAWREN_QUIZ_H
#define M2OEP_CLASS_RELATIONSHIPS_NFLAWREN_QUIZ_H

#include "Character.cpp"
#include "Scoreboard.cpp"

/*
 * Quiz class has a scoreboard and two vectors for characters and harry potter characters
 * Holds all of the logic for playing the game
 * Has a method to print the options to the console
 */

class Quiz{
private:
    Scoreboard sb;
    vector<Character> characters;
    vector<string> movies;
public:
    Quiz();

    void printOptions();

    void play();
};


#endif //M2OEP_CLASS_RELATIONSHIPS_NFLAWREN_QUIZ_H
