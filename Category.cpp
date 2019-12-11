#include "Category.h"

Category::Category(const std::string& cName) : ParentClass(cName) {
    // std::cout << "Cat constr done!" << std::endl;
    gCatlID += 1;
    
    this->ID = gCatlID;
    this->Name = cName;
    this->itemList = new std::set<Item*>();
    catList.insert(this);
}

Category::~Category() {
    // std::cout << "Cat desrt []" << std::endl;
    // delete this->itemList; ||| FOR-om erase all of ITEMS ---- > then clear content |||
}

const std::string& Category::getName() const {
    std::cout << "{class <Category>}";
    return this->Name;
}

void Category::addItem(Item* item) {
    this->itemList->insert(item);
}

void Category::deleteItem(Item* dItem) {
    this->itemList->erase(dItem);
}

void Category::getItemList() {
    std::set<Item*>::iterator it;
    // std::map<int, Item*>::iterator it;
    
    for ( it = this->itemList->begin(); it != this->itemList->end(); it++ ) {
        std::cout << "item: " << **it << std::endl;// DONT WORK (**it)!!! print only address throught *it
        // std::cout << "Category <" << this->getName();
        // std::cout << "> : with item_" << it->first;
        // std::cout << *(it->second) << std::endl;
    }
}

int Category::getUnicID() const {
    return classUnicID;
}

int Category::gCatlID = 0;

std::set<ParentClass*> Category::catList;

void Category::getCatList() {
    std::set<ParentClass*>::iterator it;
    
    std::cout << "==================== Categories List <class Category> ====================" << std::endl;
    for ( it = catList.begin(); it != catList.end(); it++ ) {
        std::cout << **it << std::endl;
    }
    
    std::cout << "======================================================================" << std::endl;
}

// std::ostream& operator<<(std::ostream& out, const ParentClass& obj) {// ERROR multiole definition of 'operator<<(std::ostream& out, const Category& obj)'
//     out << "[class <Category>] | ";
//     out << "obj_number: " << obj.getID();
//     // out << "_<GlobalID=" << obj.getGlobalID();
//     out << ": " << obj.getName() << std::endl;
    
//     return out;
// }
