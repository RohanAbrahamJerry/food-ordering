# food-ordering
to order food and drinks
#include <stdio.h>
#include <string.h>

struct foods {
    char food[100];
    char first_food[20];
    char second_food[20];
    char third_food[20];
    int first, second, third;
};

struct foods m[3]; // Adjusted to use proper indexing (0,1,2)

void food_initialize();
void search_by_foods();
void cart();
void food_sel(int food_choice);

int total = 0; // Global total for cart

int main() {
    search_by_foods();
    return 0;
}

void food_initialize() {
    strcpy(m[0].food, "BIRIYANI");
    strcpy(m[0].first_food, "Chicken Biriyani");
    strcpy(m[0].second_food, "Mutton Biriyani");
    strcpy(m[0].third_food, "Vegetable Biriyani");
    m[0].first = 90;
    m[0].second = 120;
    m[0].third = 70;

    strcpy(m[1].food, "DRINKS");
    strcpy(m[1].first_food, "Tea");
    strcpy(m[1].second_food, "Coffee");
    strcpy(m[1].third_food, "Pepsi");
    m[1].first = 12;
    m[1].second = 15;
    m[1].third = 20;

    strcpy(m[2].food, "SNACKS");
    strcpy(m[2].first_food, "Samosa");
    strcpy(m[2].second_food, "Egg Puffs");
    strcpy(m[2].third_food, "Burger");
    m[2].first = 15;
    m[2].second = 20;
    m[2].third = 45;
}

void search_by_foods() {
    int food_choice;
    food_initialize();

    printf("\n\nPlease Choose the Food Type:\n");
    printf("1) %s\n2) %s\n3) %s\n", m[0].food, m[1].food, m[2].food);
    printf("\nEnter option: ");
    scanf("%d", &food_choice);

    if (food_choice < 1 || food_choice > 3) {
        printf("Invalid choice! Try again.\n");
        search_by_foods();
    } else {
        food_sel(food_choice-1);
    }
}

void food_sel(int food_choice) {
    int option, n, back;

    while (1) {
        printf("\n\nList of foods available in %s\n", m[food_choice].food);
        printf("1) %s\tRs: %d\n", m[food_choice].first_food, m[food_choice].first);
        printf("2) %s\tRs: %d\n", m[food_choice].second_food, m[food_choice].second);
        printf("3) %s\tRs: %d\n", m[food_choice].third_food, m[food_choice].third);
        printf("4) View Cart\n5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("Enter quantity for %s: ", m[food_choice].first_food);
            scanf("%d", &n);
            total += n * m[food_choice].first;
        } else if (option == 2) {
            printf("Enter quantity for %s: ", m[food_choice].second_food);
            scanf("%d", &n);
            total += n * m[food_choice].second;
        } else if (option == 3) {
            printf("Enter quantity for %s: ", m[food_choice].third_food);
            scanf("%d", &n);
            total += n * m[food_choice].third;
        } else if (option == 4) {
            cart();
        } else if (option == 5) {
            printf("Exiting...\n");
            getchar() ;
            cart() ;
            printf("Do you want to continue ordering(yes-press 1, no-press 0:");
            scanf("%d", &back) ;
            if (back==1){
               search_by_foods() ; }
            else{
                cart() ;
                exit(0);
                }
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
}

void cart() {
    printf("\n-------------- Cart ----------------\n");
    printf("Total Order Amount: Rs %d\n", total);
}
