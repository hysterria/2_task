#include "menu_items.hpp"

#include "menu_functions.hpp"

const ABel::MenuItem ABel::PUSHKIN_DUBROVSKY = {
        "1 - Дубровский", ABel::pushkin_dubrovsky_read, &ABel::READ_PUSHKIN
};
const ABel::MenuItem ABel::PUSHKIN_ONEGIN = {
        "2 - Евгений Онегин", ABel::pushkin_onegin_read, &ABel::READ_PUSHKIN
};
const ABel::MenuItem ABel::PUSHKIN_WINTER = {
        "3 - Зимний вечер", ABel::pushkin_winter_read, &ABel::READ_PUSHKIN
};
const ABel::MenuItem ABel::GO_BACK = {
        "0 - Выйти в предыдущее меню", ABel::go_back, &ABel::READ_PUSHKIN
};

namespace {
    const ABel::MenuItem* const pushkin_children[] = {
            &ABel::GO_BACK,
            &ABel::PUSHKIN_DUBROVSKY,
            &ABel::PUSHKIN_ONEGIN,
            &ABel::PUSHKIN_WINTER
    };
    const int push_size = sizeof(pushkin_children) / sizeof(pushkin_children[0]);
}


const ABel::MenuItem ABel::READ_PUSHKIN = {
        "1 - Читать Пушкина", ABel::show_menu, &ABel::READ, pushkin_children, push_size
};
const ABel::MenuItem ABel::READ_LERMONTOV = {
        "2 - Читать Лермонтова", ABel::read_lermontov, &ABel::READ
};
const ABel::MenuItem ABel::READ_KRYLOV = {
        "3 - Читать Крылова", ABel::read_krylov, &ABel::READ
};
const ABel::MenuItem ABel::GO_BACK_READ = {
        "0 - Выйти в главное меню", ABel::go_back, &ABel::READ
};

namespace {
    const ABel::MenuItem* const read_children[] = {
            &ABel::GO_BACK_READ,
            &ABel::READ_PUSHKIN,
            &ABel::READ_LERMONTOV,
            &ABel::READ_KRYLOV
    };
    const int read_size = sizeof(read_children) / sizeof(read_children[0]);
}



const ABel::MenuItem ABel::READ = {
        "1 - Русские писатели", ABel::show_menu, &ABel::MAIN, read_children,read_size
};
const ABel::MenuItem ABel::EXIT = {
        "0 - Завершить чтение", ABel::exit, &ABel::MAIN
};

namespace {
    const ABel::MenuItem* const main_children[] = {
            &ABel::EXIT,
            &ABel::READ
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const ABel::MenuItem ABel::MAIN = {
        nullptr, ABel::show_menu, nullptr, main_children, main_size
};
