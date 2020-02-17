#include <iostream>
#include "Item.h"

Item::Item(Category* category, const std::string& itemName) : ParentClass(itemName){
    gItemID += 1;
    
    this->ID = gItemID;
    this->Name = itemName;
    this->itemCategory = category;
    this->itemCategory->addItem(this);
    
    itemList.insert(this);
}

Item::~Item() {
    this->itemCategory->deleteItem(this);
    itemList.erase(this);
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
        std::cout << "The item has not used yet!" << std::endl;
    } else {
        std::cout << "Orders list where the item = " << this->Name << " was used:" << std::endl;
        for ( ; it != this->linkedOrders.end(); it++ ) {
            std::cout << (*it)->getName() << std::endl;
        }
    }
}

int Item::gItemID = 0;

std::set<ParentClass*> Item::itemList;

void Item::getItemList() {
    std::set<ParentClass*>::iterator it = itemList.begin();
    
    for ( ; it != itemList.end(); it++ ) {
        std::cout << **it << std::endl;
    }
}
