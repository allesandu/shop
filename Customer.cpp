#include <iostream>
#include "Customer.h"

Customer::Customer(const std::string& custName) : ParentClass(custName) {
    gCustlID += 1;
    
    this->ID = gCustlID;
    this->Name = custName;
    this->ordersList = new std::set<Order*>();
    
    customerList.insert(this);
}

Customer::~Customer() {
    this->ordersList->clear();
    delete this->ordersList;
    customerList.erase(this);
}

void Customer::addOrder(Order* order) {
    this->ordersList->insert(order);
}

void Customer::getCustomerOrders() {
    std::set<Order*>::iterator it = this->ordersList->begin();
    
    if ( it == this->ordersList->end() ) {
        std::cout << "No one ORDER created!" << std::endl;
    } else {
        for ( ; it != this->ordersList->end(); it++ ) {
            std::cout << "order: " << (*it)->getName() << std::endl;
        }
    }
}

int Customer::getUnicID() const {
    return classUnicID;
}

int Customer::gCustlID = 0;

std::set<ParentClass*> Customer::customerList;

void Customer::getCustomerList() {
    std::set<ParentClass*>::iterator it = customerList.begin();
    
    for ( ; it != customerList.end(); it++ ) {
        std::cout << **it << std::endl;
    }
}
