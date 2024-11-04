#include <iostream>
#include <vector>
#include "Buffer.h"
#include "Warehouse.h"
#include "List.h"

using namespace std;


int main()
{
    int zadN = 1;
    while(zadN != 0){
        printf("n?: ");
        cin >> zadN;

        switch(zadN){
        case 1:
        {
            vector<unique_ptr<Buffer>> buffers;
            buffers.push_back(make_unique<BufferArr>(5));
            buffers.push_back(make_unique<BufferFile>("output.txt"));
            cout << endl;
            buffers[0]->add(10);
            buffers[0]->add(20);
            buffers[1]->add(30);
            buffers[1]->add(40);

            for (const auto& buffer : buffers) {
                buffer->write();
            }

            buffers[0]->add(50);
            buffers[0]->add(60); // to powinno wywołać komunikat o pełnej tablicy

            for (const auto& buffer : buffers) {
                buffer->write();
            }
            cout << endl;
        }
        break;
        case 2:
        {
            auto warehouse1 = make_shared<Warehouse>("Książki", 50);
            auto warehouse2 = make_shared<Warehouse>("Komputery", 20);
            cout << endl;
            Shop shop1("Sklep Książkowy");
            Shop shop2("Sklep Elektroniczny");
            shop1.addWarehouse(warehouse1);
            shop2.addWarehouse(warehouse2);

            shop1.sellProduct("Książki", 5);
            shop2.sellProduct("Komputery", 2);

            shop1.displayWarehouses();
            shop2.displayWarehouses();

            shop1.sellProduct("Książki", 60); // to powinno wywołać komunikat o braku towaru
            cout << endl;
        }
        break;
        case 3:
        {
            DoublyLinkedList<int> list;

            list.addBack(10);
            list.addBack(20);
            list.addFront(5);

            list.display();

            list.removeFront();
            list.display();
            list.removeBack();
            list.display();
            list.removeBack();

            list.removeBack(); // próba usunięcia z pustej listy
            cout << endl;

            // Testowanie listy dla string
            DoublyLinkedList<std::string> stringList;

            stringList.addBack("Apple");
            stringList.addBack("Banana");
            stringList.addFront("Cherry");

            stringList.display();

            stringList.removeFront();
            stringList.display();
            stringList.removeBack();
            stringList.display();
            stringList.removeBack();

            stringList.removeBack();
        }
        break;
        default:
        break;
        }

        cout << "\n\n*-*-*-*-{-----<*****[-----|-\\_/-|-----]*****>-----}-*-*-*-*\n\n" << endl;
    }

    return 0;
}
