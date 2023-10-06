#include <stdio.h>
#include <stdbool.h>

// Define the menu items and prices
typedef struct {
    char name[50];
    float price;
} MenuItem;

MenuItem menu[] = {
    {"Burger", 5.50},
    {"Pizza", 8.99},
    {"Salad", 4.25},
    {"Pasta", 7.75},
    {"Soda", 1.50}
};

#define MENU_SIZE (sizeof(menu)/sizeof(menu[0]))

void displayMenu() {
    printf("MENU\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < MENU_SIZE; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("-------------------------------------------------\n");
}

void generateBill(int orders[], int quantities[]) {
    printf("\nBILL\n");
    printf("-------------------------------------------------\n");
    float total = 0;
    for (int i = 0; i < MENU_SIZE; i++) {
        if (quantities[i] > 0) {
            float cost = menu[i].price * quantities[i];
            printf("%s x %d - $%.2f\n", menu[i].name, quantities[i], cost);
            total += cost;
        }
    }
    printf("-------------------------------------------------\n");
    printf("TOTAL: $%.2f\n", total);
    printf("-------------------------------------------------\n");
}

int main() {
    int choice, quantity;
    int quantities[MENU_SIZE] = {0};

    while (true) {
        displayMenu();
        printf("Enter the menu item number (1-%d) or 0 to generate bill: ", MENU_SIZE);
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice < 0 || choice > MENU_SIZE) {
            printf("Invalid choice. Please choose again.\n");
            continue;
        }

        printf("Enter the quantity of %s: ", menu[choice - 1].name);
        scanf("%d", &quantity);
        quantities[choice - 1] += quantity;
    }

    generateBill(quantities, quantities);
    return 0;
}
