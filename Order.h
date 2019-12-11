#ifndef ORDER_H
#define ORDER_H
#include <set>
#include "Customer.h"
#include "Item.h"
#include "ParentClass.h"

class Customer;
class Item;

class Order : public ParentClass {
    private:
        Customer* newClient;
        std::map<Item*, int>* orderedItems;
        
    public:
        Order(Customer* customer, Item* item, const std::string& ordName = "Init_order");
        virtual ~Order();
        
        virtual const std::string& getName() const;
        
        virtual int getUnicID() const;
        
        void addItem(Item* item);
        void deleteItem(Item* item);
        
        Customer* getOrderCustomer();// maybe not necessary 
        const std::string& getCustomer() const;
        
        void getItemList();
        
        static int gOrderID;
        static std::set<Order*> recordList;
        
        static const int classUnicID = 300;
};

#endif // ORDER_H 
