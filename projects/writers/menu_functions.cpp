#include <cstdlib>
#include <iostream>

#include "menu_functions.hpp"

const ABel::MenuItem* ABel::show_menu(const MenuItem* current) {
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "¬вод > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const ABel::MenuItem* ABel::exit(const MenuItem* current) {
    std::exit(0);
}

const ABel::MenuItem* ABel::go_back(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

const ABel::MenuItem* ABel::read_pushkin(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const ABel::MenuItem* ABel::read_lermontov(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const ABel::MenuItem* ABel::read_krylov(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const ABel::MenuItem* ABel::pushkin_dubrovsky_read(const MenuItem* current) {
    std::cout << "что-то про ƒубровского....." << std::endl;
    return current->parent;
}

const ABel::MenuItem* ABel::pushkin_onegin_read(const MenuItem* current) {
    std::cout << "€ вам пишу, чего же боле, что € ещЄ могу сказать....." << std::endl;
    return current->parent;
}

const ABel::MenuItem* ABel::pushkin_winter_read(const MenuItem* current) {
    std::cout << "что то про зимний вечер....." << std::endl;
    return current->parent;
}


