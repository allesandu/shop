#include <iostream>
#include "Item.h"

Item::Item(Category* category, const std::string& itemName) : ParentClass(itemName){
    gItemID += 1;
    
    // this->ID = category->getGlobalID();// common ID for all of objects - WORKS
    this->ID = gItemID;
    this->Name = itemName;
    this->itemCategory = category;
    this->itemCategory->addItem(this);
    
    itemList.insert(this);
}

Item::~Item() {
    std::cout << "[               Item DESTR_start ]" << std::endl;
    
    this->itemCategory->deleteItem(this);
    
    itemList.erase(this);
    
    // std::set<ParentClass*>::iterator it = itemList.begin();//HOW to implement correct?
    // if ( it == itemList.end() ) {
    //     delete this->itemCategory;
    // }
    
    std::cout << "[               Item DESTR_end   ]" << std::endl;
}

int Item::getUnicID() const {
    return classUnicID;
}

void Item::linkToOrder(Order* order) {
    this->linkedOrders.insert(order);
}

void Item::getLinkedOrders() {
    std::set<Order*>::iterator it = this->linkedOrders.begin();
    
    if ( it == this->linkedOrders.end() ) {
        std::cout << "!!! This ITEM has not used yet!!!" << std::endl;
    } else {
        std::cout << "=== Orders where Item = " << this->Name << " was used:===" << std::endl;
        for ( ; it != this->linkedOrders.end(); it++ ) {
            std::cout << **it << std::endl;
        }
        std::cout << "======================================================" << std::endl;
    }
}

int Item::gItemID = 0;

std::set<ParentClass*> Item::itemList;

void Item::getItemList() {
    std::set<ParentClass*>::iterator it;
    
    std::cout << "======= Items List =======" << std::endl;
    for ( it = itemList.begin(); it != itemList.end(); it++ ) {
        std::cout << **it << std::endl;
    }
    
    std::cout << "==================================" << std::endl;
}
