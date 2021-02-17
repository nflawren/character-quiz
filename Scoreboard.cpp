#include "Scoreboard.h"

using std::endl;
//default is 1 player
Scoreboard::Scoreboard(){
    numPlayers = 1;
    vector<int> temp;
    for (int j=0; j<=movies.size(); ++j){
        temp.push_back(0);
    }
    scores.push_back(temp);
}
Scoreboard::Scoreboard(int numPlayers){
    this->numPlayers = numPlayers;
    for (int i = 0; i<numPlayers; ++i){
        vector<int> temp;
        for (int j=0; j<=movies.size(); ++j){
            temp.push_back(0);
        }
        scores.push_back(temp);
    }
}
Scoreboard::Scoreboard(vector<string> m){
    movies = m;
    numPlayers = 1;
    vector<int> temp;
    for (int j=0; j<=movies.size(); ++j){
        temp.push_back(0);
    }
    scores.push_back(temp);
}

//setting number of players requires clearing the vector and pushing 0 in for each player
void Scoreboard::setNumPlayers(int numPlayers){
    //validate input
    if (numPlayers>0) {
        this->numPlayers = numPlayers;
        scores.clear();
        for (int i = 0; i < numPlayers; ++i) {
            vector<int> temp;
            for(int j=0; j<=movies.size(); ++j) {
                temp.push_back(0);
            }
            scores.push_back(temp);
        }
    } else {
        //set number of players to 1
        this->numPlayers = 1;
        scores.clear();
        vector<int> temp;
        for(int j=0; j<=movies.size(); ++j) {
            temp.push_back(0);
        }
        scores.push_back(temp);
    }
}

//set score, adds input score to input player's score
//this would allow for multipoint questions
void Scoreboard::setScore(int player, string movie, int score) {
    int index = 0;
    int totalIndex = movies.size();
    for (int i=0; i<movies.size(); ++i){
        if (movies[i]==movie){
            index = i;
        }
    }
    if (score > 0) {
        scores[player][index] += score;
        scores[player][totalIndex] += score;
    }
}

//print everyone's scores
void Scoreboard::printScores(ostream& outs){
    outs<<endl;
    int totalIndex = movies.size();
    for (int i = 0; i<numPlayers; ++i){
        int j = i+1;
        if (scores[i][totalIndex]==1) {
            outs << "Player " << j << ": " << scores[i][totalIndex] << " point" << endl;
        } else {
            outs << "Player " << j << ": " << scores[i][totalIndex] << " points" << endl;
        }
    }
    outs<<endl;
}

//given a player integer, returns appropriate next player
int Scoreboard::getNextPlayer(int player) {
    //if the player is the last player in the vector, return index 0 (player 1)
    if (player == numPlayers - 1){
        return 0;
    } else {
        return player+1;
    }
}

//given a player integer and a movie index, returns appropriate score
int Scoreboard::getScore(int player, int movieIndex){
    return this->scores[player][movieIndex];
}

//returns number of players
int Scoreboard::getNumPlayers() {
    return this->numPlayers;
}

//set all players to 0
void Scoreboard::clear() {
    for (int i = 0; i<numPlayers; ++i){
        for (int j = 0; j<=movies.size(); ++j) {
            scores[i][j] = 0;
        }
    }
}