#ifndef ITEM_H
#define ITEM_H
#include "Category.h"
#include "Order.h"
#include "ParentClass.h"

class Category;
class Order;

class Item : public ParentClass {
    private:
        Category* itemCategory;
        std::set<Order*> linkedOrders;
        
    public:
        Item(Category* category, const std::string& itemName);
        virtual ~Item();
        
        virtual const std::string& getName() const;
        
        virtual int getUnicID() const;
        
        void linkToOrder(Order* order);
        void getLinkedOrders();
        
        static int gItemID;
        static std::set<ParentClass*> itemList;
        static void getItemList();
        
        static const int classUnicID = 200;
};

#endif // ITEM_H
