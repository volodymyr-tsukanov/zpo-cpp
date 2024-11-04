#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include <iostream>
#include <memory>
#include <vector>

using namespace std;


class Warehouse {
private:
    string productName;
    int quantity;

public:
    Warehouse(const string& name, int qty) : productName(name), quantity(qty) {
        cout << "Konstruktor Warehouse: " << productName << ", ilość: " << quantity << endl;
    }
    ~Warehouse() {
        cout << "Destruktor Warehouse: " << productName << endl;
    }

    void setProductName(const string& name) {
        productName = name;
    }
    string getProductName() const {
        return productName;
    }
    void setQuantity(int qty) {
        quantity = qty;
    }
    int getQuantity() const {
        return quantity;
    }

    void display() const {
        cout << "Towar: " << productName << ", Ilość: " << quantity << endl;
    }
};


class Shop {
private:
    string shopName;
    vector<shared_ptr<Warehouse>> warehouses; // Lista magazynów

public:
    Shop(const string& name) : shopName(name) {
        cout << "Konstruktor Shop: " << shopName << endl;
    }
    ~Shop() {
        cout << "Destruktor Shop: " << shopName << endl;
    }

    void addWarehouse(const shared_ptr<Warehouse>& warehouse) {
        warehouses.push_back(warehouse);
        cout << "Dodano magazyn do sklepu: " << shopName << endl;
    }
    void sellProduct(const string& productName, int qty) {
        for (const auto& warehouse : warehouses) {
            if (warehouse->getProductName() == productName && warehouse->getQuantity() >= qty) {
                warehouse->setQuantity(warehouse->getQuantity() - qty);
                cout << "Sprzedano " << qty << " sztuk towaru: " << productName 
                          << " z magazynu. Pozostała ilość: " 
                          << warehouse->getQuantity() << endl;
                return; // Zakończ po sprzedaży
            }
        }
        cout << "Brak wystarczającej ilości towaru: " << productName << endl;
    }

    void displayWarehouses() const {
        cout << "Magazyny w sklepie: " << shopName << endl;
        for (const auto& warehouse : warehouses) {
            warehouse->display();
        }
    }
    void displayShopName() const {
        cout << "Nazwa sklepu: " << shopName << endl;
    }
};

#endif // WAREHOUSE_H
