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
            // W funkcji main stwórz listę unikatowych sklepów. Sklepy mogą korzystać z tych samych magazynów
            auto warehouse1 = make_shared<Warehouse>("Książki", 50);
            auto warehouse2 = make_shared<Warehouse>("Komputery", 20);
            auto warehouse3 = make_shared<Warehouse>("Piórniki", 66);
            auto warehouse4 = make_shared<Warehouse>("Długopisy", 11);
            cout << endl;
            vector<unique_ptr<Shop>> shops;
            shops.push_back(make_unique<Shop>("Sklep AGD"));
            shops.push_back(make_unique<Shop>("Sklep Złotówka"));
            cout << endl;
            shops[0]->addWarehouse(warehouse1);
            shops[0]->addWarehouse(warehouse2);
            shops[1]->addWarehouse(warehouse1);
            shops[1]->addWarehouse(warehouse3);
            shops[1]->addWarehouse(warehouse4);

            shops[0]->sellProduct("Książki", 5);
            shops[0]->sellProduct("Komputery", 5);
            shops[1]->sellProduct("Książki", 2);
            shops[1]->sellProduct("Długopisy", 11);

            shops[0]->displayWarehouses();
            shops[1]->displayWarehouses();

            shops[0]->sellProduct("Książki", 60); // to powinno wywołać komunikat o braku towaru
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
