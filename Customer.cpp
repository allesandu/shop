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
    std::cout << "[                         Customer DESTR    ]" << std::endl;
}

void Customer::addOrder(Order* order) {
    this->ordersList->insert(order);
}

void Customer::getCustOrders() {
    std::cout << "======= Customer Orders List ======" << std::endl;
    
    std::set<Order*>::iterator it = this->ordersList->begin();
    
    if ( it == this->ordersList->end() ) {
        std::cout << "!!! No one ORDER created !!!" << std::endl;
    } else {
        for ( ; it != this->ordersList->end(); it++ ) {
            // std::cout << "o r d e r : " << (*it)->getName() << std::endl;// show only name
            std::cout << "order : " << **it << std::endl;// operator<< overloaded
        }
    }
    
    std::cout << "===================================" << std::endl;
}

int Customer::getUnicID() const {
    return classUnicID;
}

int Customer::gCustlID = 0;

std::set<ParentClass*> Customer::customerList;

void Customer::getCustomerList() {
    std::set<ParentClass*>::iterator it = customerList.begin();
    std::cout << "======= Customers List =======" << std::endl;
    for ( ; it != customerList.end(); it++ ) {
        std::cout << **it << std::endl;
    }
    std::cout << "==================================" << std::endl;
}
