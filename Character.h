#ifndef M2OEP_CLASS_RELATIONSHIPS_NFLAWREN_CHARACTER_H
#define M2OEP_CLASS_RELATIONSHIPS_NFLAWREN_CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using std::string;
using std::vector;
using std::ostream;

/*
 * Character class has two string fields for character name and the movie they are in
 * This class has getters for use during the quiz class
 */

class Character {
private:
    string name;
    string movie;
public:
    Character();

    Character(string name, string movie);

    string getName() const;

    string getMovie() const;
};
//takes a filename and a vector of characters
//reads the characters in from the file and writes them into the vector of characters
void getCharactersFromFile(string filename, vector<Character> &characters);




#endif //M2OEP_CLASS_RELATIONSHIPS_NFLAWREN_CHARACTER_H
