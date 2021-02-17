//
// Created by nicol on 10/5/2020.
//

#include "Character.h"
#include <string>
#include <vector>
#include <fstream>

using std::endl;
using std::ifstream;
using std::ostream;
using std::string;
using std::vector;

//constructors
Character::Character(){
    name = "No Name";
    movie = "No Movie";
}

Character::Character(string name, string movie) {
    this->name = name;
    this->movie = movie;
}

//getters
string Character::getName() const {
    return this->name;
}

string Character::getMovie() const {
    return this->movie;
}

//reads characters into a vector from a given file
void getCharactersFromFile(string filename, vector<Character> &characters) {
    ifstream inFile;
    inFile.open("../"+filename);

    string name="",movie="",header="";

    getline(inFile,header);

    while(inFile && inFile.peek() != EOF) {
        getline(inFile, movie, ',');

        getline(inFile, name);

        characters.push_back(Character(name, movie));
    }
    inFile.close();
}