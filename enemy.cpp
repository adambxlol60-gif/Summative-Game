#include "enemy.h"
#include <allegro5/allegro_image.h>
#include <math.h>

static float pathX[] = {0, 250, 350, 500, 600, 750, 900, 1050, 1280};
static float pathY[] = {480, 480, 420, 420, 560, 560, 480, 480, 480};
static int pointCount = 9;

Slime initSlime(ALLEGRO_BITMAP* bitmap) {
    Slime s;
    s.bitmap = bitmap;
    s.x = pathX[0];
    s.y = pathY[0];
    s.speed = 2.0f;
    s.target = 1;
    s.done = false;
    return s;
}

void updateSlime(Slime& s) {
    if (s.done) return;

    float targetX = pathX[s.target];
    float targetY = pathY[s.target];
    float dx = targetX - s.x;
    float dy = targetY - s.y;
    float dist = sqrt(dx * dx + dy * dy);

    if (dist <= s.speed) {
        s.x = targetX;
        s.y = targetY;
        s.target++;
        if (s.target >= pointCount) s.done = true;
    } else {
        s.x += (dx / dist) * s.speed;
        s.y += (dy / dist) * s.speed;
    }
}

void drawSlime(const Slime& s) {
    if (s.done) return;
    int w = al_get_bitmap_width(s.bitmap);
    int h = al_get_bitmap_height(s.bitmap);
    const float scale = 0.1f;
    al_draw_scaled_bitmap(s.bitmap, 0, 0, w, h, s.x - (w * scale) / 2, s.y - (h * scale) / 2, w * scale, h * scale, 0);
}
