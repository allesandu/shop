#include "SaleDB.h"

SaleDB::SaleDB() {
    this->saleDB = new std::map<int, Category*>();
    this->categoryList = new std::set<Category*>();
    
    std::cout << "-------+++++++ DB is created ++++++-------" << std::endl;
}

SaleDB::~SaleDB() {
    delete this->saleDB;
    delete this->categoryList;
}

void SaleDB::addRecord(int id, Category* cat) {
    // std::cout << "-------+++++++ adding a record ++++++-------" << std::endl;
    
    this->saleDB->insert(std::pair<int, Category*>(id, cat));
    this->categoryList->insert(cat);
}
        
void SaleDB::getSaleDB() {
    // std::cout << "-------+++++++ try to print list ++++++-------" << std::endl;
    
    std::map<int, Category*>::iterator it;
    std::set<Category*>::iterator itS;
    
    for ( it = this->saleDB->begin(); it != this->saleDB->end(); it++ ) {
        std::cout << "M A P _ info ::::::: ID = " << it->first;
        std::cout << " Name = " << it->second->getName() << std::endl;
        }
    
        std::cout << "++++++++++++++++++++++++++++++++++++++-" << std::endl;
        
        for ( itS = this->categoryList->begin(); itS != this->categoryList->end(); itS++ ) {
            std::cout << "S E T _ info ::::::: Name = " << **itS << std::endl;
        }
}

Category* SaleDB::getCertainRecord(int key) const {
    return this->saleDB->at(key);
}
