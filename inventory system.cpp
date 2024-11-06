#include <iostream>
#include <string>
using namespace std;
struct Item {
    int id;
    string name;
    int quantity;
    double price;
};
class Inventory {
    Item items[100];  // Fixed-size array to hold items, assuming max 100 items
    int itemCount = 0;  // Tracks the number of items in inventory

public:
    void addItem(int id, const string &name, int quantity, double price) {
        if (itemCount < 100) {
            items[itemCount] = {id, name, quantity, price};
            itemCount++;
            cout << "Item added.\n";
        } else {
            cout << "Inventory is full.\n";
        }
    }
    void viewItems() const {
        if (itemCount == 0) {
            cout << "Inventory is empty.\n";
            return;
        }
        cout << "ID\tName\tQuantity\tPrice\n";
        for (int i = 0; i < itemCount; i++) {
            cout << items[i].id << "\t" << items[i].name << "\t" 
                 << items[i].quantity << "\t" << items[i].price << "\n";
        }
    }
    Item* searchItem(int id) {
        for (int i = 0; i < itemCount; i++) {
            if (items[i].id == id) return &items[i];
        }
        return nullptr;
    }
    void updateItem(int id, int quantity, double price) {
        Item* item = searchItem(id);
        if (item) {
            item->quantity = quantity;
            item->price = price;
            cout << "Item updated.\n";
        } else {
            cout << "Item not found.\n";
        }
    }
    void removeItem(int id) {
        int index = -1;
        for (int i = 0; i < itemCount; i++) {
            if (items[i].id == id) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            // Shift items left to fill the gap
            for (int i = index; i < itemCount - 1; i++) {
                items[i] = items[i + 1];
            }
            itemCount--;
            cout << "Item removed.\n";
        } else {
            cout << "Item not found.\n";
        }
    }
};
int main() {
    Inventory inventory;
    int choice;
    do {
        cout << "\n1. Add Item\n2. View Items\n3. Search Item\n4. Update Item\n5. Remove Item\n6. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) {
            int id, quantity;
            string name;
            double price;
            cout << "Enter ID, Name, Quantity, Price: ";
            cin >> id >> name >> quantity >> price;
            inventory.addItem(id, name, quantity, price);
        } else if (choice == 2) {
            inventory.viewItems();
        } else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            Item* item = inventory.searchItem(id);
            if (item) cout << "Found: " << item->name << "\n";
            else cout << "Item not found.\n";
        } else if (choice == 4) {
            int id, quantity;
            double price;
            cout << "Enter ID, New Quantity, New Price: ";
            cin >> id >> quantity >> price;
            inventory.updateItem(id, quantity, price);
        } else if (choice == 5) {
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;
            inventory.removeItem(id);
        } else if (choice != 6) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    cout << "Exiting...\n";
    return 0;
}
