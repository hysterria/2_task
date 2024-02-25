#pragma once

#include "menu.hpp"

namespace ABel {

    const MenuItem* show_menu(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);

    const MenuItem* read_pushkin(const MenuItem* current);
    const MenuItem* read_lermontov(const MenuItem* current);
    const MenuItem* read_krylov(const MenuItem* current);
    
    const MenuItem* pushkin_dubrovsky_read(const MenuItem* current);
    const MenuItem* pushkin_onegin_read(const MenuItem* current);
    const MenuItem* pushkin_winter_read(const MenuItem* current);

    const MenuItem* go_back(const MenuItem* current);

}
