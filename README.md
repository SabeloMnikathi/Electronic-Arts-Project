# Inventory Management System

## Overview
This is a simple yet robust **Inventory Management System** implemented in C++ for managing items in an inventory. The program allows users to add items, sell items, and list all items in the inventory. It has been designed with modern C++ best practices to ensure memory safety, scalability, and ease of use.

## Features
- **Add Items:** Add new items to the inventory with their name, quantity, and price.
- **Sell Items:** Sell items by specifying their name and the quantity to be sold. The system ensures that the quantity does not exceed the current stock.
- **Automatic Item Removal:** When the quantity of an item reaches zero, it is automatically removed from the inventory.
- **List Items:** Display all items in the inventory with their details, including name, quantity, and price.
- **Dynamic Storage:** Uses `std::vector` for dynamic resizing of the inventory to handle an arbitrary number of items efficiently.
- **Memory Safety:** Implements `std::unique_ptr` to manage items, ensuring no memory leaks and automatic cleanup of resources.

## Design Decisions
1. **Data Structure Upgrade:**
   - Replaced the fixed-size raw array (`Item *items[20]`) with a `std::vector<std::unique_ptr<Item>>` for improved flexibility, memory safety, and modern C++ standards compliance.
   - This allows the inventory to grow or shrink dynamically as items are added or removed.

2. **Item Removal Logic:**
   - Enhanced the `remove_item()` function to fully remove items from the inventory when their quantity reaches zero. This prevents unnecessary clutter and improves system efficiency.

3. **Code Cleanup:**
   - Improved the readability and maintainability of the code by removing redundant variables, simplifying logic, and adding meaningful comments.

4. **Modern C++ Practices:**
   - Leveraged `std::unique_ptr` for automatic memory management, eliminating the need for explicit deletion and reducing the risk of memory leaks.
   - Used `std::vector` for dynamic resizing and bounds checking, replacing manual array size tracking.

## How It Works
1. **Add New Item:**
   - Enter the item's name, quantity, and price.
   - The system stores the item dynamically in the inventory.

2. **Sell Item:**
   - Enter the name of the item to sell.
   - Specify the quantity to sell. If the quantity after selling becomes zero, the item is automatically removed from the inventory.

3. **List Items:**
   - Display all the items in the inventory along with their details.

4. **Exit:**
   - Exit the program.

## Code Highlights
### Memory Safety
Using `std::unique_ptr` ensures that item objects are automatically deallocated when removed from the inventory or when the program exits:
```cpp
std::vector<std::unique_ptr<Item>> items;
```

### Dynamic Inventory Management
`std::vector` provides the flexibility to handle an arbitrary number of items:
```cpp
items.push_back(std::make_unique<Item>(name, quantity, price));
```

### Item Removal
Automatically removes items with zero quantity to maintain a clean and accurate inventory:
```cpp
if (item.get_quantity() == 0) {
    items.erase(items.begin() + item_index);
}
```

## How to Run
1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/inventory-management-system.git
   ```
2. Navigate to the project directory:
   ```bash
   cd inventory-management-system
   ```
3. Compile the program using a C++ compiler (e.g., `g++`):
   ```bash
   g++ -o inventory main.cpp
   ```
4. Run the program:
   ```bash
   ./inventory
   ```

## Future Improvements
- **Case-Insensitive Matching:** Improve user experience by implementing case-insensitive string matching for item names.
- **Input Validation:** Add robust validation for numeric inputs to handle invalid data gracefully.
- **Persistent Storage:** Enable saving and loading the inventory data to/from a file for data persistence.

## Contributions
Contributions, bug reports, and feature suggestions are welcome! Feel free to open an issue or submit a pull request.

## License
This project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute it as per the license terms.

---

Thank you for checking out this project! If you find it useful, feel free to star the repository ⭐ on GitHub.
