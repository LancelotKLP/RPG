/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** handle_key_pressed
*/

#include "my_rpg.h"

void handle_escape(hud_t *hud)
{
    if (hud->display == false) {
        hud->display = true;
        hud->menu->escape = true;
        return;
    }
}

static void other_key_pressed(rpg_t *rpg, sfEvent *event)
{
    switch (event->key.code) {
        case sfKeyE:
            rpg->inventory.show = !rpg->inventory.show;
            break;
        case sfKeyLShift:
            if (rpg->player.quest < MOVE2)
                return;
            rpg->player.speed.x += 0.6;
            rpg->player.speed.y += 0.6;
            break;
        case sfKeyL:
            rpg->player.hp = 100;
            break;
        case sfKeyR:
            if (rpg->player.state == IS_DEAD)
                load_progression(rpg);
            break;
        default:
            break;
    }
}

void key_pressed_event(rpg_t *rpg, sfEvent *event, hud_t *hud)
{
    if (event->type == sfEvtKeyPressed) {
        switch (event->key.code) {
            case sfKeyEscape:
                handle_escape(hud);
                break;
            case sfKeyK:
                rpg->weather->autumn = !rpg->weather->autumn;
                break;
            case sfKeyN:
                rpg->weather->night = !rpg->weather->night;
                break;
            case sfKeyJ:
                rpg->rebuilt = !rpg->rebuilt;
                break;
            default:
                other_key_pressed(rpg, event);
                break;
        }
    }
}
