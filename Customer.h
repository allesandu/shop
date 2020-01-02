#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ParentClass.h"
#include <set>
#include "Order.h"

class Order;

class Customer : public ParentClass {
    private:
        std::set<Order*>* ordersList;
        
    public:
        Customer(const std::string& custName = "initialCustomer");
        virtual ~Customer();
        
        virtual const std::string& getName() const;
        
        void addOrder(Order* order);
        void getCustOrders();
        
        virtual int getUnicID() const;
        
        static int gCustlID;
        static std::set<ParentClass*> customerList;
        static void getCustomerList();
        
        static const int classUnicID = 400;
};

#endif // CUSTOMER_H
