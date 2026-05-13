#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <math.h>

int main () {

    ALLEGRO_BITMAP* Slime = al_load_bitmap("Images/Slime.png");
    if (!Slime) {
        al_show_native_message_box(nullptr, "Error", "Error", "Failed to load Slime image!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
        
}

void moveSlime(ALLEGRO_BITMAP* slime, ALLEGRO_DISPLAY* display){

    //Waypoints the slime follows

    float pathX[] = {0, 320, 320, 640, 640, 960, 960, 1280};
    float pathY[] = {480, 480, 240, 240, 720, 720, 480, 480};
    int pointCount = 8;

    float x = pathX[0];
    float y = pathY[0];
    float speed = 2.0f;

    int w = al_get_bitmap_width(slime);
    int h = al_get_bitmap_height(slime);

    for (int i = 1; i < pointCount; i++) {
        float targetX = pathX[i];
        float targetY = pathY[i];

        while(true) {
            float dx = targetX - x;
            float dy = targetY - y;
            float dist = sqrt(dx * dx + dy * dy);
                                                                             
            if (dist <= speed) {
                x = targetX;
                y = targetY;
                break;
            }

            x += (dx / dist) * speed;
            y += (dy / dist) * speed;
                                                                                                   
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(slime, x - w / 2, y - h / 2, 0);

            al_flip_display(al_clear_to_color(al_map_rgb(0, 0, 0)))                                                                                        ;                                                                              )
        }
    }
}