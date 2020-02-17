#include "Category.h"

Category::Category(const std::string& cName) : ParentClass(cName) {
    gCatlID += 1;
    
    this->ID = gCatlID;
    this->Name = cName;
    this->itemList = new std::set<Item*>();
    
    catList.insert(this);
}

Category::~Category() {
    this->itemList->clear();
    
    std::set<Item*>::iterator it = itemList->begin();
    if ( it == itemList->end() ) {
        delete this->itemList;
    }

    catList.erase(this);
}

void Category::addItem(Item* item) {
    this->itemList->insert(item);
}

void Category::deleteItem(Item* dItem) {
    this->itemList->erase(dItem);
}

void Category::getCategoryItems() {
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
}
