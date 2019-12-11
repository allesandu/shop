#include <iostream>
#include "Item.h"

Item::Item(Category* category, const std::string& itemName) : ParentClass(itemName){
    gItemID += 1;
    
    // this->ID = category->getGlobalID();// common ID for all of objects - WORKS
    this->ID = gItemID;
    this->Name = itemName;
    this->cat = category;
    this->cat->addItem(this);
    itemList.insert(this);
}

Item::~Item() {
    // std::cout << "Cust desrt []" << std::endl;
}

const std::string& Item::getName() const {
    // std::cout << "{class <Item>}";
    return this->Name;
}

int Item::getUnicID() const {
    return classUnicID;
}

void Item::linkToOrder(const std::string& ordName) {
    this->usedOrders.insert(ordName);
}

void Item::getUsedOrders() {
    std::set<std::string>::iterator it = this->usedOrders.begin();
    
    if ( it == this->usedOrders.end() ) {
        std::cout << "+++++++++++++++ Oops! This ITEM has not used yet!" << std::endl;
    } else {
        std::cout << "======= Orders where Item [ " << *this << " } was used:=======" << std::endl;
        for ( ; it != this->usedOrders.end(); it++ ) {
            std::cout << *it << std::endl;
        }
        std::cout << "======================================================================" << std::endl;
    }
}

int Item::gItemID = 0;

std::set<ParentClass*> Item::itemList;

void Item::getItemList() {
    std::set<ParentClass*>::iterator it;
    
    std::cout << "==================== Items List <class Item> ====================" << std::endl;
    for ( it = itemList.begin(); it != itemList.end(); it++ ) {
        std::cout << **it << std::endl;
    }
    
    std::cout << "======================================================================" << std::endl;
}
