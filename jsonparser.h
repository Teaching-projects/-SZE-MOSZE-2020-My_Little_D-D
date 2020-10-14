#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>


class Parser{
    private:
    std::string rName;
    double rHealth;
    double rDamage;
    public:
    std::string getName() const;
    double getHealth() const;
    double getDamage() const;
    void JsonParser(const std::string filename);
    void JsonParser(std::istream inputStream);
    //static Unit JsonParser(FILE);
    Parser();
};
#endif
