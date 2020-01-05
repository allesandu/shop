#include "Category.h"

Category::Category(const std::string& cName) : ParentClass(cName) {
    gCatlID += 1;
    
    this->ID = gCatlID;
    this->Name = cName;
    this->itemList = new std::set<Item*>();
    
    catList.insert(this);
}

Category::~Category() {
    std::cout << "[                                   Category DESTR 1(4)   ]" << std::endl;
    this->itemList->clear();
    
    std::cout << "[                                   Category DESTR 2(4)   ]" << std::endl;
    std::set<Item*>::iterator it = itemList->begin();
    if ( it == itemList->end() ) {
        delete this->itemList;
    }
    
    std::cout << "[                                   Category DESTR 3(4)   ]" << std::endl;
    catList.erase(this);
    
    std::cout << "[                                   Category DESTR 4(4)   ]" << std::endl;
}

void Category::addItem(Item* item) {
    this->itemList->insert(item);
}

void Category::deleteItem(Item* dItem) {
    this->itemList->erase(dItem);
}

void Category::getItemList() {
    std::set<Item*>::iterator it;
    
    for ( it = this->itemList->begin(); it != this->itemList->end(); it++ ) {
        std::cout << "item: " << **it << std::endl;
    }
}

int Category::getUnicID() const {
    return classUnicID;
}

int Category::gCatlID = 0;

std::set<ParentClass*> Category::catList;

void Category::getCatList() {
    std::set<ParentClass*>::iterator it;
    
    std::cout << "======= Categories List =======" << std::endl;
    for ( it = catList.begin(); it != catList.end(); it++ ) {
        std::cout << **it << std::endl;
    }
    
    std::cout << "==================================" << std::endl;
}
