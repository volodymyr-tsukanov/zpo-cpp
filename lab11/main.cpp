#include <iostream>
#include <vector>
#include "Buffer.h"

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
            // Kontener na wskaźniki do buforów
            vector<unique_ptr<Buffer>> buffers;

            // Tworzenie buforów
            buffers.push_back(make_unique<BufferArr>(5));
            buffers.push_back(make_unique<BufferFile>("output.txt"));
            
            // Dodawanie danych do buforów
            buffers[0]->add(10);
            buffers[0]->add(20);
            
            buffers[1]->add(30);
            buffers[1]->add(40);

            // Wyświetlanie danych z buforów
            for (const auto& buffer : buffers) {
                buffer->write();
            }

            // Dodawanie więcej danych do tablicy
            buffers[0]->add(50);
            buffers[0]->add(60); // To powinno wywołać komunikat o pełnej tablicy

            // Wyświetlanie danych ponownie
            for (const auto& buffer : buffers) {
                buffer->write();
            }
        }
        break;
        case 2:
        {
        }
        break;
        case 3:
        {
        }
        break;
        case 4:
        {
        }
        break;
        default:
        break;
        }

        cout << "\n\n*-*-*-*-{-----<*****[-----|-\\_/-|-----]*****>-----}-*-*-*-*\n\n" << endl;
    }

    return 0;
}
