#ifndef M2OEP_CLASS_RELATIONSHIPS_NFLAWREN_SCOREBOARD_H
#define M2OEP_CLASS_RELATIONSHIPS_NFLAWREN_SCOREBOARD_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::ostream;
using std::vector;

/*
 * Scoreboard class has two fields: number of players and a vector of integers that holds each player's scores
 * Scoreboard has setters and methods for printing the scores, getting the next player in the vector, and clearing the scores
 */

class Scoreboard {
private:
    int numPlayers;
    vector<vector<int>> scores;
    vector<string> movies;
public:
    Scoreboard();
    Scoreboard(int numPlayers);
    Scoreboard(vector<string> m);

    void setNumPlayers(int numPlayers);

    void setScore(int player, string movie, int score);

    void printScores(ostream& outs);

    int getNextPlayer(int player);

    int getNumPlayers();

    int getScore(int player, int movieIndex);

    void clear();

};


#endif //M2OEP_CLASS_RELATIONSHIPS_NFLAWREN_SCOREBOARD_H
