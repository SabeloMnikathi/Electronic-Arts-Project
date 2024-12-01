#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <limits>

class Item {
private:
    std::string name;
    int quantity;
    float price;

public:
    Item(std::string name, int quantity, float price) : name{std::move(name)}, quantity{quantity}, price{price} {}

    std::string get_name() const { return name; }
    int get_quantity() const { return quantity; }
    void set_quantity(int new_quantity) { quantity = new_quantity; }
    float get_price() const { return price; }

    bool is_match(const std::string &other) const {
        return std::equal(name.begin(), name.end(), other.begin(), other.end(),
                          [](char a, char b) { return tolower(a) == tolower(b); });
    }
};

class Inventory {
private:
    std::vector<Item *> items;
    float total_money = 0;

    static void display_data(const Item &item) {
        std::cout << "\nName: " << item.get_name()
                  << "\nQuantity: " << item.get_quantity()
                  << "\nPrice: " << item.get_price() << "\n";
    }

    int get_positive_int(const std::string &prompt) {
        int value;
        while (true) {
            std::cout << prompt;
            std::cin >> value;
            if (std::cin.fail() || value < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a positive number.\n";
            } else {
                return value;
            }
        }
    }

public:
    Inventory() = default;

    ~Inventory() {
        for (auto &item : items) delete item;
    }

    void add_item() {
        std::string name;
        std::cin.ignore();
        std::cout << "\nEnter item name: ";
        std::cin >> name;
        int quantity = get_positive_int("Enter quantity: ");
        float price;
        std::cout << "Enter price: ";
        std::cin >> price;
        items.push_back(new Item(name, quantity, price));
    }

    void sell_item() {
        std::string item_to_check;
        std::cin.ignore();
        std::cout << "\nEnter item name to sell: ";
        std::cin >> item_to_check;
        for (int i = 0; i < items.size(); i++) {
            if (items[i]->is_match(item_to_check)) {
                int input_quantity = get_positive_int("\nEnter quantity to sell: ");
                if (input_quantity <= items[i]->get_quantity()) {
                    float money_earned = items[i]->get_price() * input_quantity;
                    items[i]->set_quantity(items[i]->get_quantity() - input_quantity);
                    std::cout << "\nSold " << input_quantity << " of " << items[i]->get_name()
                              << "\nMoney earned: " << money_earned << "\n";
                    total_money += money_earned;
                    if (items[i]->get_quantity() == 0) {
                        delete items[i];
                        items.erase(items.begin() + i);
                        std::cout << "Item removed from inventory.\n";
                    }
                } else {
                    std::cout << "\nNot enough items in stock to sell.\n";
                }
                return;
            }
        }
        std::cout << "\nItem not found in inventory.\n";
    }

    void list_items() const {
        if (items.empty()) {
            std::cout << "\nInventory is empty.\n";
            return;
        }
        std::cout << "\nInventory:\n------------------------------------\nName         Quantity      Price\n------------------------------------\n";
        for (const auto &item : items) {
            std::cout << item->get_name() << "         " << item->get_quantity() << "         " << item->get_price() << "\n";
        }
    }
};

int main() {
    Inventory inventory;
    int choice;
    std::cout << "Welcome to the Inventory System!";
    while (true) {
        std::cout << "\n\nMenu:\n1. Add Item\n2. Sell Item\n3. List Items\n4. Exit\nEnter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                inventory.add_item();
                break;
            case 2:
                inventory.sell_item();
                break;
            case 3:
                inventory.list_items();
                break;
            case 4:
                std::cout << "\nExiting program.\n";
                return 0;
            default:
                std::cout << "\nInvalid choice. Please try again.\n";
        }
    }
}
