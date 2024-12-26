#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("\nInventory is full. Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("\nEnter Item ID: ");
    scanf("%d", &newItem.id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == newItem.id) {
            printf("\nError: Item with this ID already exists.\n");
            return;
        }
    }

    printf("Enter Item Name: ");
    scanf(" %[^"]", newItem.name);
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    inventory[itemCount++] = newItem;
    printf("\nItem added successfully!\n");
}

void viewInventory() {
    if (itemCount == 0) {
        printf("\nInventory is empty.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%-10d %-20s %-10d %-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchItem() {
    int id;
    printf("\nEnter Item ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            printf("\nItem Found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", 
                inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("\nItem with ID %d not found.\n", id);
}

void updateItem() {
    int id;
    printf("\nEnter Item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            printf("\nEnter new name: ");
            scanf(" %[^"]", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("\nItem updated successfully!\n");
            return;
        }
    }
    printf("\nItem with ID %d not found.\n", id);
}

void deleteItem() {
    int id;
    printf("\nEnter Item ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("\nItem deleted successfully!\n");
            return;
        }
    }
    printf("\nItem with ID %d not found.\n", id);
}

void calculateTotalValue() {
    float totalValue = 0;
    for (int i = 0; i < itemCount; i++) {
        totalValue += inventory[i].quantity * inventory[i].price;
    }
    printf("\nTotal Inventory Value: %.2f\n", totalValue);
}

void exitProgram() {
    printf("\nThank you for using the Inventory Management System. Goodbye!\n");
}

void menu() {
    int choice;
    do {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. View Inventory\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Calculate Total Inventory Value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateItem();
                break;
            case 5:
                deleteItem();
                break;
            case 6:
                calculateTotalValue();
                break;
            case 7:
                exitProgram();
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 7);
}

int main() {
    menu();
    return 0;
}
