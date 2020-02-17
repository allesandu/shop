#include <iostream>
#include "Customer.h"
#include "Category.h"
#include "Order.h"
#include "Item.h"

int main() {
    
    Category* cat1 = new Category("SmatPhones");
    Category* cat2 = new Category();
    // cat1->getObjList();
    
    Item* i1 = new Item(cat1, "Iphone 5S");
    Item* i2 = new Item(cat1, "Mi9");
    Item* i3 = new Item(cat2, "Xiaomi Mi LapTop");
    Item* i4 = new Item(cat1, "Mi8_Lite");
    Item* i5 = new Item(cat1, "Iphone 11 Pro");
    Item* i6 = new Item(cat2, "Dell Inspiron");
    
    Customer* c1 = new Customer("TarasKo");
    Customer* c2 = new Customer("Nata");
    
    Order* o1 = new Order(c1, i4, "First ordero");
    Order* o2 = new Order(c1, i5, "Bingo order");
    Order* o3 = new Order(new Customer("Major"), i4, "Last order");
    
    o1->addItem(i1);
    o1->addItem(i1);
    o1->addItem(i4);
    o1->deleteItem(i4);
    o1->deleteItem(i4);
    o1->deleteItem(i4);
    
    i1->getLinkedOrders();
    i4->getLinkedOrders();
    
    // std::cout << "------------- ORDER----------------------" << std::endl;
    // o1->getOrderItems();
    // std::cout << "-----------------------------------" << std::endl;
    
    // std::cout << "-----------------------------------" << std::endl;
    cat1->getCatList();
    i1->getItemList();
    o3->getOrderList();
    c1->getCustomerList();
    // std::cout << "- - - - - - - - item  - - -  - - - - - - - - - - - - - - - " << std::endl;
    // 
    // std::cout << "- - - - - - - - - - - - - -  - - - - - - - - - - - - - - - " << std::endl;
    // std::cout << "-----------category------------------------" << std::endl;
    // cat2->getCategoryItems();    
    // std::cout << "-----------------------------------" << std::endl;
    // o2->getOrderItems();
    // std::cout << "-----------------------------------" << std::endl;
    // o1->getOrderItems();
    // c1->addOrder(o1);
    // c1->addOrder(o2);
    
    std::cout << "- - - - - - - -getCustomerOrders - - - - - - - - - - - - - " << std::endl;
    c1->getCustomerOrders();
    std::cout << "- - - - - - - - - - - - - -  - - - - - - - - - - - - - - - " << std::endl;
    // c1->getObjList();
    
    
    delete cat1;
    delete cat2;
    
    delete i1;
    delete i2;
    delete i3;
    delete i4;
    delete i5;
    delete i6;
    
    delete c1;
    delete c2;
    
    delete o1;
    delete o2;
    delete o3;
    
    return 0;
}
