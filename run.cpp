#include <iostream>
#include "Customer.h"
#include "Category.h"
#include "Order.h"
#include "Item.h"

int main() {
    Category* cat1 = new Category("SmatPhones");
    // cat1->getObjList();
    // std::cout << "=====================================" << std::endl;
    // std::cout << "-----------------------------------" << std::endl;
    // std::cout << *cat1 << std::endl;
    // std::cout << "- - - - - - - - - - - - - -  - - - - - - - - - - - - - - - " << std::endl;
    Item* i1 = new Item(cat1, "Iphone 5S");
    Item* i2 = new Item(cat1, "Mi9");
    Item* i3 = new Item(cat1, "Mi6");
    Item* i4 = new Item(cat1, "Mi8_Lite");
    Item* i5 = new Item(cat1, "Iphone 11 Pro");
    
    // cat1->getObjList();
    
    // cat1->getItemList();
    
    // std::cout << "-----------------------------------" << std::endl;
    
    // cat1->deleteItem(i3);
    // cat1->getItemList();
    // std::cout << "====================================\n\n\n" << std::endl;
    
    Customer* c1 = new Customer("TarasKo");
    Customer* c2 = new Customer("Nata");
    
    Order* o1 = new Order(c1, i4, "First ordero");
    Order* o2 = new Order(c1, i5, "Bingo order");
    Order* o3 = new Order(new Customer("Major"), i4, "Last order");
    
    // o1->addItem(i1);
    // o1->addItem(i1);
    // o1->addItem(i4);
    
    // o1->deleteItem(i4);
    // o1->deleteItem(i4);
    // o1->deleteItem(i4);
    // i1->getLinkedOrders();
    // i4->getLinkedOrders();
    
    // std::cout << "-----------------------------------" << std::endl;
    // o1->getItemList();
    // std::cout << "-----------------------------------" << std::endl;
    
    // o1->deleteItem(i1);
    
    
    // o1->getObjList();
    // std::cout << "-----------------------------------" << std::endl;
    // cat1->getCatList();
    std::cout << "- - - - - - - - - - - - - -  - - - - - - - - - - - - - - - " << std::endl;
    i1->getItemList();
    std::cout << "- - - - - - - - - - - - - -  - - - - - - - - - - - - - - - " << std::endl;
    // c1->getObjList();
    // std::cout << "-----------------------------------" << std::endl;
    // o1->getObjList();
    
    // std::cout << "-----------------------------------" << std::endl;
    // o2->getCustOrders();
    // std::cout << "-----------------------------------" << std::endl;
    // o1->getItemList();
    
    // c1->addOrder(o1);
    // c1->addOrder(o2);
    
    std::cout << "- - - - - - - - - - - - - -  - - - - - - - - - - - - - - - " << std::endl;
    c1->getCustOrders();
    // c1->deleteItem(o1);
    o3->getOrderList();
    c1->getCustomerList();
    std::cout << "- - - - - - - - - - - - - -  - - - - - - - - - - - - - - - " << std::endl;
    c1->getObjList();
    
    
    
    delete i1;
    delete i2;
    delete i3;
    delete i4;
    delete i5;
    
    delete o1;
    delete o2;
    delete o3;
    
    delete c1;
    delete c2;
    
    delete cat1;
    
    return 0;
}
