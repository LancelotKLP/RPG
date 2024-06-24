/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_music
*/

#include "my_rpg.h"

void register_volume(rpg_t *rpg)
{
    rpg->music.volume_boss = sfMusic_getVolume(rpg->music.boss);
    rpg->music.volume_menu = sfMusic_getVolume(rpg->music.menu);
    rpg->music.volume_road = sfMusic_getVolume(rpg->music.road);
    rpg->music.volume_village = sfMusic_getVolume(rpg->music.village);
    rpg->music.volume_heal = sfMusic_getVolume(rpg->music.heal_sound);
    rpg->music.volume_swing = sfMusic_getVolume(rpg->music.swing_sound);
}

void init_music(rpg_t *rpg)
{
    rpg->music.boss = sfMusic_createFromFile(BOSS_MUSIC);
    rpg->music.road = sfMusic_createFromFile(ROAD_MUSIC);
    rpg->music.menu = sfMusic_createFromFile(MENU_MUSIC);
    rpg->music.village = sfMusic_createFromFile(VILLAGE_MUSIC);
    rpg->music.swing_sound = sfMusic_createFromFile(SWIPE_SOUND);
    rpg->music.heal_sound = sfMusic_createFromFile(HEAL_SOUND);
    sfMusic_setVolume(rpg->music.boss, 75);
    sfMusic_setVolume(rpg->music.road, 50);
    sfMusic_setVolume(rpg->music.menu, 50);
    sfMusic_setVolume(rpg->music.village, 100);
    sfMusic_setVolume(rpg->music.swing_sound, 75);
    sfMusic_setVolume(rpg->music.heal_sound, 100);
    register_volume(rpg);
}
