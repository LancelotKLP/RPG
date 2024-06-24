/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** init_resolution.c
*/

#include "my_rpg.h"

static void init_resolution(settings_t **sett, sfVector2f pos)
{
    (*sett)->res_sprite[0][0] = sfSprite_create();
    (*sett)->res_round = sfTexture_createFromFile(RES_ROUND, NULL);
    sfSprite_setTexture((*sett)->res_sprite[0][0], (*sett)->res_round, 0);
    sfSprite_setOrigin((*sett)->res_sprite[0][0], (sfVector2f) {273, 85});
    sfSprite_setPosition((*sett)->res_sprite[0][0], pos);
    sfSprite_setScale((*sett)->res_sprite[0][0], (sfVector2f) {0.45, 0.45});
    init_fps_settings(*sett, pos);
    (*sett)->triangle_sprite[0] = sfSprite_create();
    (*sett)->triangle = sfTexture_createFromFile(TRIANGLE, NULL);
    sfSprite_setTexture((*sett)->triangle_sprite[0], (*sett)->triangle, 0);
    sfSprite_setOrigin((*sett)->triangle_sprite[0], (sfVector2f) {542, 468});
    pos.x += 85;
    pos.y += 4;
    sfSprite_setPosition((*sett)->triangle_sprite[0], pos);
    sfSprite_setScale((*sett)->triangle_sprite[0], (sfVector2f) {0.03, 0.03});
}

static void init_resolution_string(settings_t **sett, sfVector2f pos)
{
    (*sett)->res_choosed = sfText_create();
    sfText_setFont((*sett)->res_choosed, (*sett)->font);
    sfText_setString((*sett)->res_choosed, "1920x1080");
    pos.x -= 20;
    pos.y -= 13;
    sfText_setPosition((*sett)->res_choosed, pos);
    sfText_setColor((*sett)->res_choosed, sfBlack);
    sfText_setOrigin((*sett)->res_choosed, (sfVector2f) {70, 5});
    (*sett)->resolution = sfText_create();
    sfText_setFont((*sett)->resolution, (*sett)->font);
    sfText_setString((*sett)->resolution, "Resolution");
    pos.x += 25;
    pos.y -= 100;
    sfText_setPosition((*sett)->resolution, pos);
    sfText_setColor((*sett)->resolution, sfBlack);
    sfText_setOrigin((*sett)->resolution, (sfVector2f) {80, 5});
    pos.x = DFLT_HEIGHT / 2 + 200;
    init_position(NULL, pos, (sfVector2f) {0, 0}, &(*sett)->fps);
}

void init_sprite(sfSprite **s, sfTexture **t, sfVector2f scale, char *path)
{
    *s = sfSprite_create();
    *t = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(*s, *t, 0);
    sfSprite_setScale(*s, scale);
    sfSprite_setPosition(*s, (sfVector2f) {0, 0});
}

void init_position(sfSprite **s, sfVector2f pos, sfVector2f orig, sfText **t)
{
    if (s != NULL) {
        sfSprite_setOrigin(*s, orig);
        sfSprite_setPosition(*s, pos);
    }
    if (t != NULL) {
        sfText_setPosition(*t, pos);
    }
}

void init_text_res(sfText **t, char *str, settings_t *sett, sfVector2f origin)
{
    *t = sfText_create();
    sfText_setFont(*t, sett->font);
    sfText_setString(*t, str);
    sfText_setColor(*t, sfBlack);
    sfText_setOrigin(*t, origin);
}

void init_all_res(settings_t **sett, sfVector2f pos)
{
    settings_t *set = *sett;

    set->res_sprite[0] = malloc(sizeof(sfSprite *) * 3);
    init_resolution(sett, pos);
    init_resolution_string(sett, pos);
    pos.y += 78;
    init_sprite(&set->res_sprite[0][1], &set->res_round,
        (sfVector2f) {0.45, 0.45}, RES_ROUND);
    init_position(&set->res_sprite[0][1], pos, (sfVector2f) {273, 85}, NULL);
    pos.y -= 16;
    init_text_res(&set->resfull, "Fullscreen", *sett, (sfVector2f) {90, 5});
    init_position(NULL, pos, (sfVector2f) {273, 85}, &set->resfull);
    pos.y += 94;
    init_sprite(&set->res_sprite[0][2], &set->res_round,
        (sfVector2f) {0.45, 0.45}, RES_ROUND);
    init_position(&set->res_sprite[0][2], pos, (sfVector2f) {273, 85}, NULL);
    pos.y -= 16;
    init_text_res(&set->res1920, "1920x1080", *sett, (sfVector2f) {90, 5});
    init_position(NULL, pos, (sfVector2f) {273, 85}, &set->res1920);
}
