/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** init_fps_settings.c
*/

#include "my_rpg.h"

void init_fps144(settings_t *sett, sfVector2f p)
{
    init_sprite(&sett->res_sprite[1][1], &sett->res_round,
        (sfVector2f) {0.45, 0.45}, RES_ROUND);
    init_position(&sett->res_sprite[1][1], p, (sfVector2f) {273, 85}, NULL);
    init_text_res(&sett->fps144, "144", sett, (sfVector2f) {25, 5});
    p.y -= 13;
    init_position(NULL, p, (sfVector2f) {0, 0}, &sett->fps144);
}

void init_fps_settings(settings_t *sett, sfVector2f p)
{
    sett->res_sprite[1] = malloc(sizeof(sfSprite *) * 2);
    sett->triangle_sprite = malloc(sizeof(sfSprite *) * 2);
    sett->display_fps = false;
    p.x = DFLT_HEIGHT / 2 + 200;
    init_text_res(&sett->fps, "FPS", sett, (sfVector2f) {25, 5});
    init_sprite(&sett->res_sprite[1][0], &sett->res_round,
        (sfVector2f) {0.45, 0.45}, RES_ROUND);
    init_position(&sett->res_sprite[1][0], p, (sfVector2f) {273, 85}, NULL);
    init_sprite(&sett->triangle_sprite[1], &sett->triangle,
        (sfVector2f) {0.03, 0.03}, TRIANGLE);
    p.x += 85;
    init_position(&sett->triangle_sprite[1], p, (sfVector2f) {542, 468}, NULL);
    p.x -= 85;
    init_text_res(&sett->fps_choosed, "60", sett, (sfVector2f) {17, 5});
    p.y -= 13;
    init_position(NULL, p, (sfVector2f) {0, 0}, &sett->fps_choosed);
    p.y += 91;
    init_fps144(sett, p);
}
