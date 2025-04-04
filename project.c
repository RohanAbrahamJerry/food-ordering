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
