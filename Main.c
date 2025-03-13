#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define MAX_CART 10

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

typedef struct {
    Product product;
    int quantity;
} CartItem;

Product products[MAX_PRODUCTS] = {
    {1, "Laptop", 50000},
    {2, "Smartphone", 25000},
    {3, "Headphones", 2000},
    {4, "Smartwatch", 5000},
    {5, "Tablet", 30000}
};

CartItem cart[MAX_CART];
int cartSize = 0;

void displayProducts() {
    printf("\nAvailable Products:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%d. %s - Rs.%.2f\n", products[i].id, products[i].name, products[i].price);
    }
}

void addToCart(int productId, int quantity) {
    if (cartSize >= MAX_CART) {
        printf("\nCart is full!\n");
        return;
    }
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].id == productId) {
            cart[cartSize].product = products[i];
            cart[cartSize].quantity = quantity;
            cartSize++;
            printf("\nAdded %d x %s to cart.\n ", quantity, products[i].name);
            return;
        }
    }
    printf("\nInvalid product ID!\n");
}

void viewCart() {
    if (cartSize == 0) {
        printf("\nYour cart is empty!\n");
        return;
    }
    printf("\nYour Cart:\n");
    float total = 0;
    for (int i = 0; i < cartSize; i++) {
        printf("%d x %s - Rs.%.2f\n", cart[i].quantity, cart[i].product.name, cart[i].product.price * cart[i].quantity);
        total += cart[i].product.price * cart[i].quantity;
    }
    printf("Total: Rs.%.2f\n", total);
}

void checkout() {
    if (cartSize == 0) {
        printf("\nCart is empty. Cannot proceed to checkout.\n");
        return;
    }
    viewCart();
    printf("\nCheckout successful! Thank you for shopping.\n");
    cartSize = 0;
}

int main() {
    int choice, productId, quantity;
    printf("\nOnline Shopping System\n");
        printf("1. View Products\n");
        printf("2. Add to Cart\n");
        printf("3. View Cart\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayProducts();
                break;
            case 2:
                printf("Enter product ID to add to cart: ");
                scanf("%d", &productId);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                addToCart(productId, quantity);
                break;
            case 3:
                viewCart();
                break;
            case 4:
                checkout();
                break;
            case 5:
                printf("\nThank you for using Online Shopping System. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}
