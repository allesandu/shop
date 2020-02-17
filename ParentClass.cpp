#include "ParentClass.h"
#include <set>

ParentClass::ParentClass(const std::string& name) {
            globalID += 1;
            objList.insert(this);
            this->Name = name;
            this->ID = globalID;
        }

ParentClass::~ParentClass() {};

int ParentClass::getID() const {
    return this->ID;
}

const std::string& ParentClass::getName() const {
    return this->Name;
}

int ParentClass::getUnicID() const {};

int ParentClass::globalID = 0;

int  ParentClass::getGlobalID() {
    return globalID;
}

std::set<ParentClass*> ParentClass::objList;

void ParentClass::getObjList() {
    std::set<ParentClass*>::iterator it;
    
    for ( it = objList.begin(); it != objList.end(); it++ ) {
        std::cout << **it << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const ParentClass& obj) {
    out << obj.getName();
    out << " [classID=" << obj.getUnicID() << "]" << std::endl;
    
    return out;
}
