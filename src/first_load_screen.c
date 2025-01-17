/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** first_load_screen
*/

#include "update.h"
#include "display.h"

void load_progress(float loading_progress, sfRectangleShape *loading_bar,
    sfRectangleShape *background, rpg_t *rpg)
{
    for (int i = 0; i < 100; i += 15) {
        loading_progress = i;
        sfRectangleShape_setSize(loading_bar,
            (sfVector2f){4 * loading_progress, 50});
        sfRenderWindow_clear(rpg->window, sfBlack);
        sfRenderWindow_drawRectangleShape(rpg->window, background, NULL);
        sfRenderWindow_drawRectangleShape(rpg->window, loading_bar, NULL);
        sfRenderWindow_display(rpg->window);
        sfSleep(sfMilliseconds(100));
    }
}

int loading_screen(rpg_t *rpg, tile_t **head, hud_t **hud,
    stats_t **stats)
{
    sfRectangleShape *background;
    sfRectangleShape *loading_bar;
    float loading_progress = 0.0;

    background = sfRectangleShape_create();
    sfRectangleShape_setFillColor(background,
        sfColor_fromRGBA(50, 50, 50, 200));
    sfRectangleShape_setSize(background, (sfVector2f){400, 50});
    sfRectangleShape_setPosition(background, (sfVector2f){760, 540});
    loading_bar = sfRectangleShape_create();
    sfRectangleShape_setFillColor(loading_bar,
        sfColor_fromRGBA(100, 200, 50, 255));
    sfRectangleShape_setSize(loading_bar, (sfVector2f){0, 50});
    sfRectangleShape_setPosition(loading_bar, (sfVector2f){760, 540});
    if (init_rpg(rpg, head, hud, stats) == 84)
        return 84;
    load_progress(loading_progress, loading_bar, background, rpg);
    sfRectangleShape_destroy(background);
    sfRectangleShape_destroy(loading_bar);
    return 0;
}
