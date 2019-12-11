#include <iostream>
#include "Customer.h"

Customer::Customer(const std::string& custName) : ParentClass(custName) {
// std::cout << "Cust constr done!" << std::endl;
    gCustlID += 1;
    
    this->ID = gCustlID;
    this->Name = custName;
    this->ordersList = new std::set<Order*>();
}

Customer::~Customer() {
    // std::cout << "Cust desrt []" << std::endl;
    delete this->ordersList; // reconsider
}

const std::string& Customer::getName() const {
    // std::cout << "{class <Customer>}";
    return this->Name;
}

void Customer::addOrder(Order* order) {
    this->ordersList->insert(order);
}

void Customer::getOrderList() {
    std::cout << "+++ ======= ORDER List SET ====== +++" << std::endl;
    
    std::set<Order*>::iterator it = this->ordersList->begin();
    
    if ( it == this->ordersList->end() ) {
        std::cout << "I N F O   !!! No one ORDER created !!!" << std::endl;
    } else {
        for ( ; it != this->ordersList->end(); it++ ) {
            // std::cout << "o r d e r : " << (*it)->getName() << std::endl;// show only name
            std::cout << "o r d e r : " << **it << std::endl;// operator<< overloaded
        }
    }
    
    std::cout << "+++ =================================== +++" << std::endl;
}

int Customer::getUnicID() const {
    return classUnicID;
}

int Customer::gCustlID = 0;
