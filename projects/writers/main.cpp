#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_items.hpp"

int main() {
    const ABel::MenuItem* current = &ABel::MAIN;
    do {
        current = current->func(current);
    } while (true);
    return 0;
}
