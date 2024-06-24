/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** init_menu.c
*/

#include "../../include/my_rpg.h"

static void init_escape_back(hud_t **hud)
{
    (*hud)->menu->back = sfTexture_createFromFile(BACKGROUND, NULL);
    (*hud)->menu->back_sprite = sfSprite_create();
    sfSprite_setScale((*hud)->menu->back_sprite, (sfVector2f) {1.1, 1.1});
    sfSprite_setTexture((*hud)->menu->back_sprite, (*hud)->menu->back, 0);
}

static void init_resume(hud_t **hud, sfVector2f pos)
{
    (*hud)->menu->iresume_eng = sfTexture_createFromFile(I_RESUME_ENG, NULL);
    (*hud)->menu->hresume_eng = sfTexture_createFromFile(H_RESUME_ENG, NULL);
    (*hud)->menu->presume_eng = sfTexture_createFromFile(P_RESUME_ENG, NULL);
    (*hud)->menu->iresume_fr = sfTexture_createFromFile(I_RESUME_FR, NULL);
    (*hud)->menu->iresume_fr = sfTexture_createFromFile(I_RESUME_FR, NULL);
    (*hud)->menu->iresume_fr = sfTexture_createFromFile(I_RESUME_FR, NULL);
    (*hud)->menu->iresume_fr = sfTexture_createFromFile(I_RESUME_FR, NULL);
    (*hud)->menu->iresume_fr = sfTexture_createFromFile(I_RESUME_FR, NULL);
    (*hud)->menu->hresume_fr = sfTexture_createFromFile(H_RESUME_FR, NULL);
    (*hud)->menu->presume_fr = sfTexture_createFromFile(P_RESUME_FR, NULL);
    (*hud)->menu->resume_sprite = sfSprite_create();
    sfSprite_setTexture((*hud)->menu->resume_sprite,
        (*hud)->menu->iresume_eng, 0);
    sfSprite_setOrigin((*hud)->menu->resume_sprite, (sfVector2f) {115, 35.5});
    sfSprite_setPosition((*hud)->menu->resume_sprite, pos);
    (*hud)->menu->r_rect = sfRectangleShape_create();
    sfRectangleShape_setSize((*hud)->menu->r_rect, (sfVector2f) {229, 71});
    sfRectangleShape_setOrigin((*hud)->menu->r_rect, (sfVector2f) {115, 35.5});
    sfRectangleShape_setPosition((*hud)->menu->r_rect, pos);
    sfRectangleShape_setFillColor((*hud)->menu->r_rect, sfTransparent);
}

void init_escape_menu(hud_t **hud, rpg_t *rpg)
{
    sfVector2u size = sfRenderWindow_getSize(rpg->window);
    sfVector2f pos = {size.x / 2, size.y / 1.7};

    (*hud)->menu->escape = false;
    init_escape_back(hud);
    init_resume(hud, pos);
}
