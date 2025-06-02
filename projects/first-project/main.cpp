/*
    File: main.cpp 
    Description: This application showsg++ how to use structs, iterators, and lambda functions in c++ by managing and sorting pizza orders. It includes functionality to sort orders by size, name, and price using inline lambda expressions with thesort algorithm.
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

// Challenge 1 & 2: Base struct
struct PizzaOrder {
    std::string name;
    int size; // in inches
};

// Helper function to print PizzaOrder vector
void printOrders(const std::vector<PizzaOrder>& orders) {
    for (const auto& order : orders) {
        std::cout << "Name: " << order.name << ", Size: " << order.size << " inches\n";
    }
}

// Challenge 3: Struct with price
struct PizzaOrderWithPrice {
    std::string name;
    int size;
    double price;
};

// Helper function to print PizzaOrderWithPrice vector
auto printOrdersWithPrice = [](const std::vector<PizzaOrderWithPrice>& orders) {
    for (const auto& order : orders) {
        std::cout << "Name: " << order.name << ", Size: " << order.size
                  << " inches, Price: $" << order.price << '\n';
    }
};

int main() {
    std::vector<PizzaOrder> pizzaOrders = {
        {"Margherita", 12},
        {"Pepperoni", 16},
        {"Veggie", 10},
        {"Hawaiian", 14},
        {"BBQ Chicken", 12}
    };

    std::cout << "=== Challenge 1: Sort by Size (Ascending) ===\n";
    std::sort(pizzaOrders.begin(), pizzaOrders.end(), [](const PizzaOrder& a, const PizzaOrder& b) {
        return a.size < b.size;
    });
    printOrders(pizzaOrders);

    std::cout << "\n=== Challenge 2: Sort by Name (Alphabetically) ===\n";
    std::sort(pizzaOrders.begin(), pizzaOrders.end(), [](const PizzaOrder& a, const PizzaOrder& b) {
        return a.name < b.name;
    });
    printOrders(pizzaOrders);

    std::cout << "\n=== Challenge 3: Sort by Price (Ascending) ===\n";
    std::vector<PizzaOrderWithPrice> pricedOrders = {
        {"Margherita", 12, 9.99},
        {"Pepperoni", 16, 13.50},
        {"Veggie", 10, 8.75},
        {"Hawaiian", 14, 11.25},
        {"BBQ Chicken", 12, 12.00}
    };

    std::sort(pricedOrders.begin(), pricedOrders.end(), [](const PizzaOrderWithPrice& a, const PizzaOrderWithPrice& b) {
        return a.price < b.price;
    });
    printOrdersWithPrice(pricedOrders);

    return 0;
}
