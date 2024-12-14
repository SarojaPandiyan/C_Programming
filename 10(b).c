#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BRAND_LENGTH 50
#define MAX_MODEL_LENGTH 50
#define MAX_PHONES 10

typedef struct {
    char brand[MAX_BRAND_LENGTH];
    char model[MAX_MODEL_LENGTH];
    int ram;
    int storage;
    int frontCamera;
    int backCamera;
    float price;
} MobilePhone;

void displayPhoneDetails(MobilePhone phone) {
    printf("Brand: %s\n", phone.brand);
    printf("Model: %s\n", phone.model);
    printf("RAM: %d GB\n", phone.ram);
    printf("Storage: %d GB\n", phone.storage);
    printf("Front Camera: %d MP\n", phone.frontCamera);
    printf("Back Camera: %d MP\n", phone.backCamera);
    printf("Price: $%.2f\n", phone.price);
    printf("-----------------------\n");
}

void displayPhonePricesByModel(MobilePhone* phones[], int numPhones, char modelName[]) {
    printf("Price details of %s:\n", modelName);
    for (int i = 0; i < numPhones; i++) {
        if (strcmp(phones[i]->model, modelName) == 0) {
            printf("Brand: %s, Price: $%.2f\n", phones[i]->brand, phones[i]->price);
        }
    }
    printf("-----------------------\n");
}

int compareBrands(const void* a, const void* b) {
    MobilePhone** phoneA = (MobilePhone**)a;
    MobilePhone** phoneB = (MobilePhone**)b;
    return strcmp((*phoneA)->brand, (*phoneB)->brand);
}

void displayBrandsInAlphabeticalOrder(MobilePhone* phones[], int numPhones) {
    printf("Brands in alphabetical order:\n");
    qsort(phones, numPhones, sizeof(MobilePhone*), compareBrands);
    for (int i = 0; i < numPhones; i++) {
        printf("%s\n", phones[i]->brand);
    }
    printf("-----------------------\n");
}

int findHighestFrontCameraResolution(MobilePhone* phones[], int numPhones) {
    int highestResolution = -1;
    for (int i = 0; i < numPhones; i++) {
        if (phones[i]->frontCamera > highestResolution) {
            highestResolution = phones[i]->frontCamera;
        }
    }
    return highestResolution;
}

void displayPhonesGreaterThanRAM(MobilePhone* phones[], int numPhones, int ram) {
    printf("Mobile phones with RAM greater than %d GB:\n", ram);
    for (int i = 0; i < numPhones; i++) {
        if (phones[i]->ram > ram) {
            displayPhoneDetails(*phones[i]);
        }
    }
}

int comparePrices(const void* a, const void* b) {
    MobilePhone** phoneA = (MobilePhone**)a;
    MobilePhone** phoneB = (MobilePhone**)b;
    if ((*phoneA)->price < (*phoneB)->price) {
        return -1;
    } else if ((*phoneA)->price > (*phoneB)->price) {
        return 1;
    }
    return 0;
}

void displayPhonesByBrandSortedByPrice(MobilePhone* phones[], int numPhones, char brand[]) {
    printf("Mobile phones of brand %s sorted by price:\n", brand);
    int brandCount = 0;
    for (int i = 0; i < numPhones; i++) {
        if (strcmp(phones[i]->brand, brand) == 0) {
            brandCount++;
        }
    }
    MobilePhone** brandPhones = (MobilePhone*)malloc(brandCount * sizeof(MobilePhone));
    int index = 0;
    for (int i = 0; i < numPhones; i++) {
        if (strcmp(phones[i]->brand, brand) == 0) {
            brandPhones[index++] = phones[i];
        }
    }
    qsort(brandPhones, brandCount, sizeof(MobilePhone*), comparePrices);

    // Save the sorted phones to a file
    FILE* file = fopen("sorted_prices.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    for (int i = 0; i < brandCount; i++) {
        fprintf(file, "Brand: %s\n", brandPhones[i]->brand);
        fprintf(file, "Model: %s\n", brandPhones[i]->model);
        fprintf(file, "RAM: %d GB\n", brandPhones[i]->ram);
        fprintf(file, "Storage: %d GB\n", brandPhones[i]->storage);
        fprintf(file, "Front Camera: %d MP\n", brandPhones[i]->frontCamera);
        fprintf(file, "Back Camera: %d MP\n", brandPhones[i]->backCamera);
        fprintf(file, "Price: $%.2f\n", brandPhones[i]->price);
        fprintf(file, "-----------------------\n");
    }

    fclose(file);
    free(brandPhones);
}

int main() {
    MobilePhone phones[MAX_PHONES];
    MobilePhone* phonePointers[MAX_PHONES];

    printf("Enter mobile phone details:\n");
    for (int i = 0; i < MAX_PHONES; i++) {
        MobilePhone phone;
        printf("Phone %d:\n", i + 1);

        printf("Brand: ");
        fgets(phone.brand, MAX_BRAND_LENGTH, stdin);

        printf("Model: ");
        fgets(phone.model, MAX_MODEL_LENGTH, stdin);

        printf("RAM (GB): ");
        scanf("%d", &phone.ram);

        printf("Storage (GB): ");
        scanf("%d", &phone.storage);

        printf("Front Camera (MP): ");
        scanf("%d", &phone.frontCamera);

        printf("Back Camera (MP): ");
        scanf("%d", &phone.backCamera);

        printf("Price: $");
        scanf("%f", &phone.price);

        char dummy[10]; // To consume the newline character after scanf
        fgets(dummy, sizeof(dummy), stdin); // Consume the newline character
        printf("-----------------------\n");

        phones[i] = phone;
        phonePointers[i] = &phones[i];
    }

    printf("\n");

    char modelName[MAX_MODEL_LENGTH];
    printf("Enter a model name to display its price details: ");
    fgets(modelName, MAX_MODEL_LENGTH, stdin);
    strtok(modelName, "\n");
    displayPhonePricesByModel(phonePointers, MAX_PHONES, modelName);
    printf("\n");

    displayBrandsInAlphabeticalOrder(phonePointers, MAX_PHONES);
    printf("\n");

    int highestResolution = findHighestFrontCameraResolution(phonePointers, MAX_PHONES);
    printf("Highest front camera resolution: %d MP\n", highestResolution);
    printf("-----------------------\n");

    int ram;
    printf("Enter a RAM value to display phones with greater RAM: ");
    scanf("%d", &ram);
    displayPhonesGreaterThanRAM(phonePointers, MAX_PHONES, ram);
    printf("\n");

    char brand[MAX_BRAND_LENGTH];
    printf("Enter a brand name to display phones with sorted prices: ");
    fgets(brand, MAX_BRAND_LENGTH, stdin);
    strtok(brand, "\n");
    displayPhonesByBrandSortedByPrice(phonePointers, MAX_PHONES, brand);

    return 0;
}
