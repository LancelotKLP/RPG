/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_music
*/

#include "my_rpg.h"

void launch_menu_music(rpg_t *rpg, hud_t *hud)
{
    if (hud->display && hud->menu->escape != true)
        if (sfMusic_getStatus(rpg->music.menu) != sfPlaying) {
            sfMusic_setLoop(rpg->music.menu, sfTrue);
            sfMusic_play(rpg->music.menu);
        }
}

void launch_road_music(rpg_t *rpg, hud_t *hud)
{
    if (!hud->display && sfMusic_getStatus(rpg->music.road) != sfPlaying
    && strcmp(rpg->maps.name_curr, "road") == 0) {
        sfMusic_stop(rpg->music.menu);
        sfMusic_stop(rpg->music.village);
        sfMusic_stop(rpg->music.boss);
        if (sfMusic_getStatus(rpg->music.road) != sfPlaying) {
            sfMusic_setLoop(rpg->music.road, sfTrue);
            sfMusic_play(rpg->music.road);
        }
    }
}

void launch_village_music(rpg_t *rpg, hud_t *hud)
{
    if (!hud->display && sfMusic_getStatus(rpg->music.village) != sfPlaying
    && strcmp(rpg->maps.name_curr, "village") == 0) {
        sfMusic_stop(rpg->music.menu);
        sfMusic_stop(rpg->music.road);
        sfMusic_stop(rpg->music.boss);
        if (sfMusic_getStatus(rpg->music.village) != sfPlaying) {
            sfMusic_setLoop(rpg->music.village, sfTrue);
            sfMusic_play(rpg->music.village);
        }
    }
}

void launch_boss_music(rpg_t *rpg, hud_t *hud)
{
    if (!hud->display && sfMusic_getStatus(rpg->music.boss) != sfPlaying
    && strcmp(rpg->maps.name_curr, "boss") == 0) {
        sfMusic_stop(rpg->music.menu);
        sfMusic_stop(rpg->music.road);
        sfMusic_stop(rpg->music.village);
        if (sfMusic_getStatus(rpg->music.boss) != sfPlaying) {
            sfMusic_setLoop(rpg->music.boss, sfTrue);
            sfMusic_play(rpg->music.boss);
        }
    }
}

void update_music(rpg_t *rpg, hud_t *hud)
{
    launch_menu_music(rpg, hud);
    launch_road_music(rpg, hud);
    launch_village_music(rpg, hud);
    launch_boss_music(rpg, hud);
}
