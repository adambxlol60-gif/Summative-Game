#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

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

    float Pathx[] = {0, 320, 320, 640, 640, 960, 960, 1280};
    float Pathy[] = {480, 480, 240, 240, 720, 720, 480, 480};
    int pointCount = 8;

    float x = Pathx[0];
    float y = Pathy[0];
}