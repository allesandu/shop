#include <iostream>
#include "Customer.h"

Customer::Customer(const std::string& custName) : ParentClass(custName) {
// std::cout << "Cust constr done!" << std::endl;
    gCustlID += 1;
    
    this->ID = gCustlID;
    this->Name = custName;
    this->orderList = new std::map<int, Order*>();
}

Customer::~Customer() {
    // std::cout << "Cust desrt []" << std::endl;
    delete this->orderList;
}

const std::string& Customer::getName() const {
    // std::cout << "{class <Customer>}";
    return this->Name;
}

void Customer::addOrder(Order* order) {
    this->orderList->insert(std::pair<int, Order*>(order->getID(), order));
}
void Customer::getOrderList() {
    std::map<int, Order*>::iterator it = this->orderList->begin();
    
    if ( it == orderList->end() ) {
        std::cout << "+++++++++++++++ Oops! No one ORDER yet" << std::endl;
    } else {
        for ( ; it != this->orderList->end(); it++ ) {
            std::cout << "Cust <" << this->getName();
            std::cout << "> : buy " << it->first;
            std::cout << " and " << *(it->second);
        }
    }
}

int Customer::getUnicID() const {
    return classUnicID;
}

int Customer::gCustlID = 0;
