#include <stdio.h>

union Insect {
    int legs;
    int wings;
    int eyes;
};

int main() {
    union Insect insect1;
    insect1.legs = 6;
    
    printf("Legs: %d\n", insect1.legs);

    insect1.wings = 2;
    printf("Wings: %d\n", insect1.wings);

    return 0;
}
