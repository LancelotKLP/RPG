/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** display_menu.c
*/

#include "display.h"

void display_back_button(hud_t *hud, rpg_t *rpg)
{
    if (hud->chars->display == true || hud->sett->display == true)
        sfRenderWindow_drawSprite(rpg->window, hud->back_sprite, NULL);
}

void display_menu(hud_t *hud, rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    sfRenderWindow_drawSprite(rpg->window, hud->menu->back_sprite, NULL);
    display_back_button(hud, rpg);
    if (hud->menu->escape == true) {
        display_escape_menu(hud, rpg);
        return;
    }
    if (hud->chars->display == true) {
        display_player_choose(rpg, hud);
        return;
    }
    if (hud->sett->display == true) {
        display_settings_hud(rpg, hud);
        return;
    }
    sfRenderWindow_drawSprite(rpg->window, hud->menu->ngame_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, hud->menu->lgame_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, hud->menu->settings_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, hud->menu->exit_sprite, NULL);
    sfRenderWindow_display(rpg->window);
}
