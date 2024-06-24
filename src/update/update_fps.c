/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** update_fps.c
*/

#include "my_rpg.h"

void update_ims(settings_t *sett, rpg_t *rpg)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(rpg->window);
    sfFloatRect pos = sfRectangleShape_getGlobalBounds(sett->english_rect);

    pos = sfSprite_getGlobalBounds(sett->res_sprite[1][0]);
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        if (sett->display_fps == false) {
            sett->display_fps = true;
            return;
        } else {
            sett->display_fps = false;
            return;
        }
    }
}

void update_fps(settings_t *sett, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    pos = sfSprite_getGlobalBounds(sett->res_sprite[1][1]);
    if (sett->display_fps == true && sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        sett->display_fps = false;
        if (strcmp(sfText_getString(sett->fps_choosed), "60") == 0) {
            sfText_setString(sett->fps_choosed, "144");
            sfText_setString(sett->fps144, "60");
            sfRenderWindow_setFramerateLimit(rpg->window, 144);
            return;
        }
        if (strcmp(sfText_getString(sett->fps_choosed), "144") == 0) {
            sfText_setString(sett->fps_choosed, "60");
            sfText_setString(sett->fps144, "144");
            sfRenderWindow_setFramerateLimit(rpg->window, 60);
            return;
        }
    }
}
