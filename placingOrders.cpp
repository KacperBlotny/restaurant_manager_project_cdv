#include <iostream>
#include "./importowanie.cpp"
using namespace std;


void displayOrder(string allDishes[1000], int orderedAmount[1000], int allDishesLength){
    float cost = 0.0, currCost;

    for(int i = 0; i < allDishesLength; i++){
        if(orderedAmount[i] != 0) {
            currCost = orderedAmount[i] * stof(
                    allDishes[i*3+2]);    // stof() - string to float
            cout << allDishes[i*3+1] << " x" << orderedAmount[i] << " = " << currCost << endl;
            cost += currCost;
        }

    }
    cout << "Suma: " << cost << endl;
    cout << endl;
}



void onConfirm(string dishes[1000], int dishesAmount[1000], int allDishesLength){

    string history[1000];
    string order[6];
    int historyElementCounter = 0;
    readFile(history, historyElementCounter, "./data/orders.txt");
    string date = "22.01.2022";
    int sameDateCounter = 0;

    for(int i = 0; i < historyElementCounter; i++){
        if (history[i] == date){
            sameDateCounter++;
        }
    }

    sameDateCounter++;

    if (sameDateCounter > 9) {
        order[0] = to_string(sameDateCounter);
    } else{
        order[0] = '0' + to_string(sameDateCounter);
    }

    order[1] = date;
    order[2] = "ID" + order[0];
    order[3] = "";  // Nazwy
    order[4] = "";  // Ceny
    order[5] = "";  // Ilosc

    for(int i = 0; i < allDishesLength; i++){

        if(dishesAmount[i] != 0) {
            order[3] += dishes[i*3+1];
            order[3] += ",";

            order[4] += dishes[i*3+2];
            order[4] += ",";

            order[5] += to_string(dishesAmount[i]);
            order[5] += ",";
        }
    }

    writeToFile(order, "./data/orders.txt");
}

void changeOrders(string dishes[1000], int dishesAmount[1000], int allDishesLength){
    int selection;
    bool isConfirmed = true;

    while(isConfirmed){
    cout << "Prosze zweryfikowac czy zamowienie sie zgadza i wybrac odpowednia opcje." << endl;
    cout << "[1] Zaakceptuj zamowienie" << endl;
    cout << "[2] Usun pozycje z zamowienia" << endl;
    cout << "[3] Dodaj pozycje do zamowienia" << endl;
    cout << endl;
    cout << "Prosze wybrac opcje: ";
    cin >> selection;
    cout << endl;

        switch (selection) {
            case 1:
                cout << endl;
                cout << "Zamowienie przyjete" << endl;
                isConfirmed = false;
                onConfirm(dishes, dishesAmount, allDishesLength);
                break;
            case 2:

                int delete_id;
                cout << "Podaj numer id dania do usuniecia: ";
                cin >> delete_id;
                cout << endl;
                dishesAmount[delete_id - 1] -= 1;

                displayOrder(dishes, dishesAmount, allDishesLength);
                break;
            case 3:

                int add_id;
                cout << "Podaj numer id dania do usuniecia: ";
                cin >> add_id;
                cout << endl;
                dishesAmount[add_id - 1] += 1;

                displayOrder(dishes, dishesAmount, allDishesLength);
                break;
            default:
                cout << "Nie ma takiej opcji" << endl;
                break;
        }
    }

}

void addToOrder(string allDishes[1000], int allDishesLength) {

    int orderedAmount[1000];

    for(int i = 0; i < 1000; i++){
        orderedAmount[i] = 0;
    }

    cout << "Prosze podac numery id dan jakie maja zostac dodane do zamowienia," << endl
         << "wpisanie 0 spowoduje przejscie do nastepnego kroku." << endl << endl;


    string dish;
    int selection;
    for(int i = 0; i < 10; i++){
        cout << "Prosze podac numer id dania: ";
        selection = 0;
        cin >> selection;
        cout << endl;

        if (selection == 0){
            break;
        }

        orderedAmount[selection - 1] += 1;
    }

    displayOrder(allDishes, orderedAmount, allDishesLength);

    changeOrders(allDishes, orderedAmount, allDishesLength);
}

void placeOrder() {

    string PIZZA[1000], DRINKS[1000], BURGERS[1000], ALL[1000];

    int pizzaElementCounter, drinksElementCounter, burgersElementCounter, allElementCounter = 0;

    readFile(PIZZA, pizzaElementCounter, "./data/menu/pizza.txt");
    readFile(DRINKS, drinksElementCounter, "./data/menu/drinks.txt");
    readFile(BURGERS, burgersElementCounter, "./data/menu/burger.txt");

    cout << "Menu" << endl;
    for (int i = 0; i < burgersElementCounter; i += 3) {
        cout << BURGERS[i] << " " << BURGERS[i + 1] << " " << BURGERS[i + 2] << endl;
        ALL[allElementCounter] = BURGERS[i];
        ALL[allElementCounter+1] = BURGERS[i + 1];
        ALL[allElementCounter+2] = BURGERS[i + 2];
        allElementCounter += 3;
    }
    cout << endl;

    for (int i = 0; i < pizzaElementCounter; i += 3) {
        cout << PIZZA[i] << " " << PIZZA[i + 1] << " " << PIZZA[i + 2] << endl;
        ALL[allElementCounter] = PIZZA[i];
        ALL[allElementCounter+1] = PIZZA[i + 1];
        ALL[allElementCounter+2] = PIZZA[i + 2];
        allElementCounter += 3;
    }
    cout << endl;

    for (int i = 0; i < drinksElementCounter; i += 3) {
        cout << DRINKS[i] << " " << DRINKS[i + 1] << " " << DRINKS[i + 2] << endl;
        ALL[allElementCounter] = DRINKS[i];
        ALL[allElementCounter+1] = DRINKS[i + 1];
        ALL[allElementCounter+2] = DRINKS[i + 2];
        allElementCounter += 3;
    }
    cout << endl;
    addToOrder(ALL, allElementCounter);
}

int main() {
    placeOrder();
    return 0;
}
