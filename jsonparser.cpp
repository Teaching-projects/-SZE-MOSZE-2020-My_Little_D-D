#include "jsonparser.h"


Parser::Parser() : rName(""), rDamage(0), rHealth(0){};

std::string Parser::getName() const{
    return rName;
}
double Parser::getHealth() const{
    return rHealth;
}
double Parser::getDamage() const{
    return rDamage;
}


void Parser::JsonParser(const std::string filename){
    std::string tmpString, name = "";
    double health, damage = 0;
    std::string line = "" , searchTerm;
    std::size_t searchResult;
    std::ifstream file(filename);
    int linecounter = 0;
    
    if(!file.is_open()){
        throw "The file is missing";
    }

    while (std::getline(file,line))
    {
        searchTerm = "\"name\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
        tmpString = line.substr((searchResult+searchTerm.size()+1));
        if(linecounter<=2){
        tmpString.resize(tmpString.size()-2);
        }
        else{
            tmpString.resize(tmpString.size()-1);
        }
        name = tmpString;
        }

        searchTerm ="\"dmg\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
            tmpString = line.substr(searchResult+searchTerm.size());
            damage = std::stod(tmpString);
        }
        searchTerm = "\"hp\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
            tmpString = line.substr(searchResult+searchTerm.size());
            health = std::stod(tmpString);
        }
        linecounter++;
    }
    rDamage=damage;
    rHealth = health;
    rName = name;
    file.close();
    
}

void Parser::JsonParser(std::istream inputStream){
std::string tmpString, name = "";
    double health, damage = 0;
    std::string line = "" , searchTerm;
    std::size_t searchResult;
    int linecounter = 0;
    
    if(!inputStream){
        throw "The file is missing";
    }

    while (std::getline(inputStream,line))
    {
        searchTerm = "\"name\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
        tmpString = line.substr((searchResult+searchTerm.size()+1));
        if(linecounter<=2){
        tmpString.resize(tmpString.size()-2);
        }
        else{
            tmpString.resize(tmpString.size()-1);
        }
        name = tmpString;
        }

        searchTerm ="\"dmg\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
            tmpString = line.substr(searchResult+searchTerm.size());
            damage = std::stod(tmpString);
        }
        searchTerm = "\"hp\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
            tmpString = line.substr(searchResult+searchTerm.size());
            health = std::stod(tmpString);
        }
        linecounter++;
    }
    
}
//Unit Parser::JsonParser(std::string String){}