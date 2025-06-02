/*
    File: main.cpp 
    Description: This application manages and sorts a list of pizza orders using C++ structs and lambda functions.It demonstrates sorting by size, name, and price using STL algorithms, emphasizing the use of lambdas for custom logic. Outputs are printed in a user-friendly format to simulate a real pizza order system.
    Author: Yusuf Midou
    Email: yusufm3487@student.vvc.edu
    Course#: cis202
    Section#: 30001
    Date: June 1 2025
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Struct without price
struct PizzaOrder {
    string name;
    int size;
};

// Struct with price
struct PizzaOrderWithPrice {
    string name;
    int size;
    double price;
};

// Print helpers
void printOrders(const vector<PizzaOrder>& orders) {
    for (size_t i = 0; i < orders.size(); ++i) {
        cout << orders[i].name << " " << orders[i].size << " inches";
        if (i != orders.size() - 1) cout << "\n";
    }
}


void printOrdersWithPrice(const vector<PizzaOrderWithPrice>& orders) {
    for (size_t i = 0; i < orders.size(); ++i) {
        cout << orders[i].name << " " << orders[i].size << " inches $" << orders[i].price;
        if (i != orders.size() - 1) cout << "\n";
    }
}


int main() {
    cout << endl; 

    // Base pizza order data
    vector<PizzaOrder> pizzaOrders = {
        {"Alice", 12},
        {"Bob", 16},
        {"Charlie", 10},
        {"Diana", 14}
    };

    cout << "Original Pizza Orders:\n";
    printOrders(pizzaOrders); cout<<endl;

    // Challenge 1: Sort by size (ascending)
    sort(pizzaOrders.begin(), pizzaOrders.end(), [](const PizzaOrder& a, const PizzaOrder& b) {
        return a.size < b.size;
    });
    cout << "\nSorted by Size (Ascending):\n";
    printOrders(pizzaOrders);cout<<endl;

    // Challenge 2: Sort by name (alphabetically)
    sort(pizzaOrders.begin(), pizzaOrders.end(), [](const PizzaOrder& a, const PizzaOrder& b) {
        return a.name < b.name;
    });
    cout << "\nSorted by Name (Alphabetical):\n";
    printOrders(pizzaOrders);cout<<endl;

    // Challenge 3: New data with price
    vector<PizzaOrderWithPrice> pricedOrders = {
        {"Charlie", 10, 9.99},
        {"Alice", 12, 11.99},
        {"Diana", 14, 13.75},
        {"Bob", 16, 15.49}
    };

    sort(pricedOrders.begin(), pricedOrders.end(), [](const PizzaOrderWithPrice& a, const PizzaOrderWithPrice& b) {
        return a.price < b.price;
    });
    cout << "\nSorted by Price (Ascending):\n";
    printOrdersWithPrice(pricedOrders);

    return 0; 
}

