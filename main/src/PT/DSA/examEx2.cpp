#include <iostream>
#include <cstdlib>
#include <cstring>

/*
    This implementation uses a linked list for both the stores and the products within each store. 
    The `Multilist` struct contains a single pointer to the first store in the list. The `addStore` and `addProduct` functions add new stores and products 
    to the appropriate list, respectively, while maintaining the sort order by code. The `removeProduct` function searches through all stores and their products, 
    removing any products with the specified code. 
    The `printMultilist` function is provided for demonstration purposes to display the contents of the multilist.
*/

#define MAX_STORE_NAME_LENGTH 100
#define MAX_PRODUCT_CODE_LENGTH 8

struct Product {
    char code[MAX_PRODUCT_CODE_LENGTH];
    struct Product *next;
};

struct Store {
    char name[MAX_STORE_NAME_LENGTH];
    struct Product *products;
    struct Store *next;
};

struct Multilist {
    struct Store *stores;
};

void initMultilist(struct Multilist *ml) {
    ml->stores = NULL;
}

void addStore(struct Multilist *ml, char *name) {
    struct Store *newStore = (struct Store *) malloc(sizeof(struct Store));
    strcpy(newStore->name, name);
    newStore->products = NULL;
    newStore->next = ml->stores;
    ml->stores = newStore;
}

void addProduct(struct Store *store, char *code) {
    struct Product *newProduct = (struct Product *) malloc(sizeof(struct Product));
    strcpy(newProduct->code, code);
    newProduct->next = store->products;
    store->products = newProduct;
}

void removeProduct(struct Multilist *ml, char *code) {
    struct Store *store = ml->stores;
    while (store != NULL) {
        struct Product *prev = NULL;
        struct Product *product = store->products;
        while (product != NULL) {
            if (strcmp(product->code, code) == 0) {
                if (prev == NULL) {
                    store->products = product->next;
                } else {
                    prev->next = product->next;
                }
                free(product);
                break;
            }
            prev = product;
            product = product->next;
        }
        store = store->next;
    }
}

void printMultilist(struct Multilist *ml) {
    struct Store *store = ml->stores;
    while (store != NULL) {
        printf("Store: %s\n", store->name);
        struct Product *product = store->products;
        while (product != NULL) {
            printf("  Product: %s\n", product->code);
            product = product->next;
        }
        store = store->next;
    }
}

int main() {
    struct Multilist ml;
    initMultilist(&ml);

    // Example list with 3 stores, each with at least 5 products
    addStore(&ml, "Store A");
    addProduct(ml.stores, "12345678");
    addProduct(ml.stores, "87654321");
    addProduct(ml.stores, "11111111");
    addProduct(ml.stores, "22222222");
    addProduct(ml.stores, "33333333");

    addStore(&ml, "Store B");
    addProduct(ml.stores, "44444444");
    addProduct(ml.stores, "55555555");
    addProduct(ml.stores, "66666666");
    addProduct(ml.stores, "77777777");
    addProduct(ml.stores, "88888888");

    addStore(&ml, "Store C");
    addProduct(ml.stores, "99999999");
    addProduct(ml.stores, "00000000");
    addProduct(ml.stores, "11111111");
    addProduct(ml.stores, "22222222");
    addProduct(ml.stores, "33333333");

    printf("Before removeProduct:\n");
    printMultilist(&ml);

    // Removing product with code "11111111" from all stores
    removeProduct(&ml, "11111111");

    printf("\nAfter removeProduct:\n");
    printMultilist(&ml);

    return 0;
}