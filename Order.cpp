#include <iostream>
#include "Order.h"


Order::Order(Customer* customer, Item* item, const std::string& ordName) : ParentClass(ordName) {
    gOrderID += 1;
    
    this->ID = gOrderID;
    this->Name = ordName;
    this->newClient = customer;
    this->orderedItems = new std::map<Item*, int>();
    
    this->addItem(item);
    
    customer->addOrder(this);
    item->linkToOrder(this);
}

Order::~Order() {
    // std::cout << "destr of order!" << std::endl;
}

const std::string& Order::getName() const {
    // std::cout << "{class <Order>}";
    return this->Name;
}

int Order::getUnicID() const {
    return classUnicID;
}

void Order::addItem(Item* item) {
    if ( this->orderedItems->find(item) == this->orderedItems->end() ) {
        this->orderedItems->insert(std::pair<Item*, int>(item, 0));
    }
    this->orderedItems->at(item) += 1;
    
    item->linkToOrder(this);// maybe delete thisorder when item will be ecompletely removed from it
}

void Order::deleteItem(Item* item) {
    std::map<Item*, int>::iterator it = this->orderedItems->find(item);
    
    if ( it != this->orderedItems->end() ) {
        if ( it->second == 1 ) {
            this->orderedItems->erase(item);
        } else {
            this->orderedItems->at(item) -= 1;
        }
    }
}

Customer* Order::getOrderCustomer() {// maybe not necessary 
    return this->newClient;
}

const std::string& Order::getCustomer() const {
    return this->newClient->getName();
}

void Order::getItemList() {
    std::cout << "======= Item List MAP ++++++++" << std::endl;
    std::map<Item*, int>::iterator it = this->orderedItems->begin();
    
    for ( ; it != this->orderedItems->end(); it++ ) {
        std::cout << "item = " << it->first->getName();
        std::cout << " amount = " << it->second << std::endl;
    }
    std::cout << "++++++++++++++++++++++++++++++" << std::endl;
}

int Order::gOrderID = 0;
