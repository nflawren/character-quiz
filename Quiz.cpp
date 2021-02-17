#include "Quiz.h"
#include <ctime>
#include <memory>
#include <time.h>

using namespace std;

Quiz::Quiz(){
    //read in characters from file into vectors
    getCharactersFromFile("pixarcharacters.csv",characters);
    bool flag = false;
    //populate movie vector
    for (int i=0; i<characters.size(); ++i){
        for (int j = 0; j<movies.size(); ++j){
            if (movies[j] == characters[i].getMovie()){
                flag = true;
            }
        }
        if (!flag){
            movies.push_back(characters[i].getMovie());
        }
        flag = false;
    }
    sb = Scoreboard(movies);
}

//print menu choices for user
void Quiz::printOptions(){
    cout<<"Press (m) to play Guess What Movie, (s) for set players, (r) for rules, (g) for get results, or (e) to exit: ";
}

void Quiz::play(){
    srand(time(NULL));
    char playerInput = 'a',playerCont;

    while (playerInput != 'e') {

        int nextPlayer = 0;
        this->printOptions();
        cin >> playerInput;

        //invalid input
        while (playerInput != 'm' && playerInput != 'e' && playerInput != 'r' && playerInput != 'g' && playerInput != 's') {
            cout << endl << "Invalid option. " << endl;
            printOptions();
            cin >> playerInput;
        }

        //valid input
        switch (playerInput) {
            case 'm': {
                //clear scoreboard when game restarts
                sb.clear();
                //continues in this game while user inputs 'c'
                playerCont = 'c';
                while(playerCont =='c'){
                    string playerAnswer = "";
                    random_shuffle(characters.begin(), characters.end());
                    int index = 0;
                    Character thing = characters[index];
                    //player gets three tries
                    cout<<endl<<"Player "<< nextPlayer+1<<"'s Turn:"<<endl;
                    cout << "What movie is " << characters[index].getName() << " from? " << endl;
                    cin.ignore();
                    getline(cin, playerAnswer);
                    if (playerAnswer == characters[index].getMovie()) {
                        cout << "Correct!" << endl;
                        //set/print scores
                        sb.setScore(nextPlayer, characters[index].getMovie(), 1) ;
                        sb.printScores(cout);
                        //set next player
                        nextPlayer = sb.getNextPlayer(nextPlayer);
                    } else {
                        // try 2
                        cout << "Incorrect, 2 tries left" << endl << "What movie is " << characters[index].getName()
                             << " from? " << endl;
                        getline(cin, playerAnswer);
                        if (playerAnswer == characters[index].getMovie()) {
                            cout << "Correct!" << endl;
                            //set/print scores
                            sb.setScore(nextPlayer, characters[index].getMovie(), 1);
                            sb.printScores(cout);
                            //set next player
                            nextPlayer = sb.getNextPlayer(nextPlayer);
                        } else {
                            //try 3
                            cout << "Incorrect, 1 try left" << endl << "What movie is " << characters[index].getName()
                                 << " from? " << endl;
                            getline(cin, playerAnswer);
                            if (playerAnswer == characters[index].getMovie()) {
                                cout << "Correct!" << endl;
                                //set/print scores
                                sb.setScore(nextPlayer, characters[index].getMovie(), 1);
                                sb.printScores(cout);
                                //set next player
                                nextPlayer = sb.getNextPlayer(nextPlayer);
                            } else {
                                cout << "Incorrect, " << characters[index].getName() << " is from "
                                     << characters[index].getMovie() << endl;
                                //print scores
                                sb.printScores(cout);
                                //set next player
                                nextPlayer = sb.getNextPlayer(nextPlayer);
                            }
                        }
                    }
                    //prompt user for continuing game or choosing another option
                    cout<<"Enter (c) to continue game, or any other key to exit back to main menu"<<endl;
                    cin >> playerCont;
                    cin.clear();
                }
                //print out final scores and clear scoreboard
                cout<<"Final Scores: "<<endl;
                sb.printScores(cout);
                break;
            }
            case 'r': {
                //prints rules
                cout << "Guess what movie the given characters are from"<<endl;
                break;
            }
            case 's': {
                //set number of players
                int players;
                cout<< "How many players are playing? ";
                //validate input
                while(!(cin>>players)){
                    string junk;
                    getline(cin, junk);
                    cout<<"Invalid input, please input integer."<<endl<<"How many players are playing? ";
                }
                sb.setNumPlayers(players);
                break;
            }
            case 'g': {
                string command = "py ../graphResults.py ";
                command.append(to_string((movies.size())+1) + " ");
                command.append(to_string(sb.getNumPlayers())+ " ");
                for (int i=0; i<movies.size(); ++i){
                    string movie = movies[i];
                    while (movie.find(' ')!=string::npos){
                        movie.erase(movie.find(' '),1);
                    }
                    command.append(movie+" ");
                }
                command.append("Total ");
                for(int i=0; i<sb.getNumPlayers(); ++i) {
                    for (int j = 0; j <= movies.size(); ++j) {
                        command.append(to_string(sb.getScore(i,j))+ " ");
                    }
                }
                system(command.c_str());
            }
        }
    }
}