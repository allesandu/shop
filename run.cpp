#include <iostream>
#include "Customer.h"
#include "Category.h"
#include "Order.h"
#include "Item.h"

int main() {
    Category* p1 = new Category("SmatPhones");
    // p1->getObjList();
    // std::cout << "=====================================" << std::endl;
    // std::cout << "-----------------------------------" << std::endl;
    // std::cout << *p1 << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    Item* i1 = new Item(p1, "Mi4");
    Item* i2 = new Item(p1, "Mi9");
    Item* i3 = new Item(p1, "Mi6");
    Item* i4 = new Item(p1, "Mi8_Lite");
    Item* i5 = new Item(p1, "Iphone 11 Pro");
    
    // p1->getObjList();
    
    // p1->getItemList();
    
    // std::cout << "-----------------------------------" << std::endl;
    
    // p1->deleteItem(i3);
    // p1->getItemList();
    // std::cout << "====================================\n\n\n" << std::endl;
    
    Customer* c1 = new Customer("TarasKo");
    
    Order* o1 = new Order(c1, i4, "First ordero");
    Order* o2 = new Order(c1, i5, "Bingo order");
    Order* o3 = new Order(new Customer("Major"), i4, "Last order");
    
    o1->addItem(i1);
    o1->addItem(i1);
    o1->addItem(i4);
    
    // o1->deleteItem(i4);
    // o1->deleteItem(i4);
    // o1->deleteItem(i4);
    // i1->getUsedOrders();
    // i4->getUsedOrders();
    
    // std::cout << "-----------------------------------" << std::endl;
    // o1->getItemList();
    // std::cout << "-----------------------------------" << std::endl;
    
    // o1->deleteItem(i1);
    
    
    // o1->getObjList();
    // std::cout << "-----------------------------------" << std::endl;
    // p1->getCatList();
    // std::cout << "-----------------------------------" << std::endl;
    // i1->getItemList();
    // std::cout << "-----------------------------------" << std::endl;
    // c1->getObjList();
    // std::cout << "-----------------------------------" << std::endl;
    // o1->getObjList();
    
    // std::cout << "-----------------------------------" << std::endl;
    // o2->getOrderList();
    // std::cout << "-----------------------------------" << std::endl;
    // o1->getItemList();
    
    // c1->addOrder(o1);
    // c1->addOrder(o2);
    
    std::cout << "-----------------------------------" << std::endl;
    c1->getOrderList();
    // c1->deleteItem(o1);
    std::cout << "-----------------------------------" << std::endl;
    // c1->getOrderList();
    // sd1->addRecord();
    // sd1->addRecord(1, p2);
    // sd1->addRecord(2, p3);
    
    // sd1->getSaleDB();
    
    // std::cout << "----------------------------------------------" << std::endl;
    // std::cout << "Certain element:" << *(sd1->getCertainRecord(1)) << std::endl;
    
    delete p1;
    delete i1;
    delete i2;
    delete i3;
    delete i4;
    delete i5;
    
    delete c1;
    delete o1;
    delete o2;
    // delete o3;
    
    return 0;
}
