#include "ParentClass.h"
#include <set>

ParentClass::ParentClass(const std::string& name) {
            // std::cout << "PARENT constr done!" << std::endl;
            globalID += 1;
            objList.insert(this);// overal LIST work (3 out of 5)
            this->Name = name;
            this->ID = globalID;
        }

ParentClass::~ParentClass() {
    // std::cout << "PARENT desrt []" << std::endl;
}

int ParentClass::getID() const {
    return this->ID;
}

const std::string& ParentClass::getName() const {
    return this->Name;
}

int ParentClass::getUnicID() const {
    // do nothing redefine into child classed
};

int ParentClass::globalID = 0;

int  ParentClass::getGlobalID() {
    return globalID;
}

std::set<ParentClass*> ParentClass::objList;// overal LIST work (4 out of 5)

void ParentClass::getObjList() {// overal LIST work (5 out of 5)
    std::set<ParentClass*>::iterator it;
    
    std::cout << "==================== OBJ List <class ParentClass> ====================" << std::endl;
    
    for ( it = objList.begin(); it != objList.end(); it++ ) {
        std::cout << **it << std::endl;
    }
    
    std::cout << "======================================================================" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const ParentClass& obj) {
    out << "obj_#=" << obj.getID();
    out << "{" << obj.getUnicID() << "}";
    // out << "_<GlobalID=" << obj.getGlobalID();
    out << " title=" << obj.getName() << std::endl;
    
    return out;
}
