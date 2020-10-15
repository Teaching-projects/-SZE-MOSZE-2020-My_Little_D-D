#include "Unit.h"

  /**
  *\brief osztaly az egyseg keszitesehez
  *\param name az egyseg neve
  *\param health az egyseg HP-ja
  *\param damage az egyseg sebzesi kepessege
  *\param pAttackspeed a csata sebesseget befolyasolo parameter, a sebzesek bevitele kozotti ido alapjan
  */
Unit::Unit(std::string pName,double pHealth, double pDamage, double pAttackspeed) : 
    Name(pName),
    Damage(pDamage),
    Health(pHealth),
    Attackspeed(pAttackspeed){};

  ///az egyseg nevevel visszatero getter
  ///\return name
std::string Unit::getName() const{
    return Name;
}
  ///az egyseg HP-jat lekero getter
  ///\return Health
double Unit::getHealth() const{
    return Health;
}
  ///az egyseg sebzeset lekero getter
  ///\return Damage
double Unit::getDamage() const{
    return Damage;
}
  /// ket sebzes bevitele kozott eltelt ido
  ///\return Attackspeed
double Unit::getAttackSpeed() const{
    return Attackspeed;
}

    /// a tamadast levezenylo fuggveny
void Unit::getAttacked(const Unit* unitAttacker){
    Health -= unitAttacker->getDamage();
    if(Health < 0){
        Health = 0;
    }
}

    /// konstruktor
Unit::Unit(const Unit& alpha):
    Name(alpha.getName()),
    Damage(alpha.getDamage()),
    Health(alpha.getHealth()),
    Attackspeed(alpha.getAttackSpeed())
    {}

    /// a tamadast levezenylo fuggveny, amely a sebzesi idokozoket is lekezeli
void Unit::attack(const Unit &unitDefender){
    double fightDuration = 0.00;
    Unit UnitDefender = unitDefender;
    //Initial attacks
    UnitDefender.getAttacked(this);
    this->getAttacked(&UnitDefender);
    //Timed fight sequence
    while(this->getHealth() > 0 && UnitDefender.getHealth() > 0){
        if(fmod(fightDuration,this->getAttackSpeed())<0.01){
            UnitDefender.getAttacked(this);
            if(UnitDefender.getHealth()<=0){
                break;
            }
            fightDuration += 0.01;
            continue;
        }
        if(fmod(fightDuration,UnitDefender.getAttackSpeed())<0.01){
            this->getAttacked(&UnitDefender);
            if(this->getHealth()<=0){
                break;
            }
            fightDuration += 0.01;
            continue;
        }
        fightDuration += 0.01;
    }
    if(this->getHealth()<=0){
        std::cout << UnitDefender.getName() << " wins. Remaining HP:" << UnitDefender.getHealth()<< std::endl; 
    }
    if(UnitDefender.getHealth()<=0){
        std::cout << this->getName() << " wins. Remaining HP:" << this->getHealth()<< std::endl; 
    }
}

  /// parseUnit fuggveny,  ami parameterkent var egy fajlnevet, es ha abban az alabbi JSON formatumnak megfeleloen le van irva, amennyiben a file nem letezik, azt lekezeli
  ///@param a parameter egy txt file JSON formatumban
  ///@return outputUnit visszater a kimeneti fajllal

Unit Unit::parseUnit(const std::string fileName){
    std::string tmpString, name = "";
    double health, damage, attackspeed = 0.0;
    std::string line = "" , searchTerm;
    std::size_t searchResult;
    std::ifstream file(fileName);
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
        searchTerm ="\"attackspeed\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
            tmpString = line.substr(searchResult+searchTerm.size());
            attackspeed = std::stod(tmpString);
        }
        searchTerm = "\"hp\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
            tmpString = line.substr(searchResult+searchTerm.size());
            health = std::stod(tmpString);
        }
        linecounter++;
    }
    
    file.close();
    if(health == 0.0 || damage == 0.0 || attackspeed == 0.0 ||tmpString.empty()||name.empty() ){
        throw "Stats missing!";
    }
    Unit outputUnit(name,health,damage,attackspeed);
    return outputUnit;
}
