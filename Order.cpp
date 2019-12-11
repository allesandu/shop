#include <iostream>
#include "Order.h"


Order::Order(Customer* customer, Item* item, const std::string& ordName) : ParentClass(ordName) {
    gOrderID += 1;
    
    this->ID = gOrderID;
    this->Name = ordName;
    this->ordCustomer = customer;
    this->ordItem = new std::set<Item*>();
    
    this->addItem(item);
    // recordList.insert(this);// reconsider and maybe remove at all
    
    orderList.insert(this);
}

Order::~Order() {
    // std::cout << "destr of order!" << std::endl;
}

const std::string& Order::getName() const {
    std::cout << "{class <Order>}";
    return this->Name;
}

int Order::getUnicID() const {
    return classUnicID;
}

void Order::addItem(Item* item) {
    this->ordItem->insert(item);
    item->linkToOrder(this->getName()); // orderName where the item was added
}

void Order::deleteItem(Item* item) {
    this->ordItem->erase(item);
    // maybe delete order name from list in item
}

Customer* Order::getOrderCustomer() {// maybe not necessary 
    return this->ordCustomer;
}

const std::string& Order::getCustomer() const {
    return this->ordCustomer->getName();
}

void Order::getItemList() {
    std::set<Item*>::iterator it;
    
    for ( it = this->ordItem->begin(); it != this->ordItem->end(); it++ ) {
        std::cout << "Cust. <" << this->getCustomer() << ">";
        std::cout << " ord. [" << this->getName() << "]";
        std::cout << " with: " << **it << std::endl;
    }
}

// void Order::getOrderList() { // Ne sovsem chto nujno !!
//     std::cout << "============================== MAP INFO <class Order> =============================" << std::endl;
    
//     std::set<Order*>::iterator it;
    
//     for ( it = recordList.begin(); it != recordList.end(); it++ ) {
//         std::cout << *((*it)->getOrderCustomer()) << std::endl;
//     }
// }

int Order::gOrderID = 0;

// std::set<Order*> Order::recordList;// = new std::set<Order*>(); // Ne sovsem chto nujno !!

std::set<ParentClass*> Order::orderList;

void Order::getOrderList() {
    std::set<ParentClass*>::iterator it;
    
    std::cout << "==================== Orders List <class Order> ====================" << std::endl;
    for ( it = orderList.begin(); it != orderList.end(); it++ ) {
        std::cout << **it << std::endl;
    }
    std::cout << "===================================================================" << std::endl;
}
