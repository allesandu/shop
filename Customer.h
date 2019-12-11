#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ParentClass.h"
#include <map>
#include "Order.h"

class Order;

class Customer : public ParentClass {
    private:
        std::map<int, Order*>* orderList;
        
    public:
        Customer(const std::string& custName = "Init_customer0");
        virtual ~Customer();
        
        virtual const std::string& getName() const;
        
        void addOrder(Order* order);
        void getOrderList();
        
        virtual int getUnicID() const;
        
        static int gCustlID;
        static const int classUnicID = 400;
};

#endif // CUSTOMER_H
