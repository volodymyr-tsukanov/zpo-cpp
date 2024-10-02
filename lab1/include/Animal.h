#ifndef ANIMAL_H
#define ANIMAL_H


class Animal
{
private:
    int limbNr;
    string name;

protected:
    bool protectedAnimal = true;

public:
    Animal();
    Animal(bool _protectedAnimal, int _limbNr, string _name);

    string getName();
    int getLimbNr();
    bool getProtectedAnimal();

    void setName(string _name);
    void setLimbNr(int _limbNr);
    void setProtectedAnimal(bool _protectedAnimal);
};


• metodę giveVoice()– wyświetla na konsolę ciąg znaków „Chrum, miau, hau, piiiii”;
• metodę info() – wyświetla dane składowe na konsole.

#endif // ANIMAL_H
