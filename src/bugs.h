#ifndef bugsH
#define bugsH

#include "stdio.h"
#include <time.h>
#include <stdlib.h>
#include "raylib.h"

#define BUG_COUNT 6


typedef struct {
        int bugType;
        int didyagetit;
        Vector3 pos;

} bugsarrayvar;

typedef enum{
    BEE,
    BEETLE,
    EARTHWORM,
    FIREFLY,
    FOLIAGE,
    STICKBUG,
    BUG_TYPE_COUNT
}bugs ;

Texture2D BEE_TEXTURE;
Texture2D BEETLE_TEXTURE;
Texture2D EARTHWORM_TEXTURE;
Texture2D FIREFLY_TEXTURE;
Texture2D STICKBUG_TEXTURE;

// our bug list, tracks all the bugs and whether we've caught them or nay
// bug ID and bugsList index is the same for simplicity
bugsarrayvar bugsList[BUG_COUNT];

void init_bugs(){
    for(int i = 0; i < BUG_COUNT; i++){
        bugsarrayvar* b = &bugsList[i];

        b->pos.x = (rand() % 40) - 20;
        b->pos.y = 0.5;
        b->pos.z = (rand() % 40) - 20;
        b->bugType = rand() % BUG_TYPE_COUNT;
        b->didyagetit = false;
    }

    BEE_TEXTURE = LoadTexture("resources/bee.png");
    BEETLE_TEXTURE = LoadTexture("resources/beetle.png");
    EARTHWORM_TEXTURE = LoadTexture("resources/earthworm.png");
    FIREFLY_TEXTURE = LoadTexture("resources/firefly.png");
    STICKBUG_TEXTURE = LoadTexture("resources/stickbug.png");
}

// returns the caught bug maybe
int getthebug(Vector3 playerPos, Vector3 cameraPos) {

for(int i = 0; i < BUG_COUNT; i++) {

        

        int minBugX = bugsList[i].pos.x - 0.2f;
        int minBugY = bugsList[i].pos.y - 0.2f;
        int minBugZ = bugsList[i].pos.z - 0.2f;

        int maxBugX = bugsList[i].pos.x + 0.2f;
        int maxBugY = bugsList[i].pos.y + 0.2f;
        int maxBugZ = bugsList[i].pos.z + 0.2f;

        Vector3 netPos;
        netPos.x = playerPos.x+(cameraPos.x+playerPos.x);
        netPos.y = playerPos.y+(cameraPos.y+playerPos.y);
        netPos.z = playerPos.z+(cameraPos.z+playerPos.z);

        // the actual function logic stuff
        if(netPos.x > minBugX && netPos.x < maxBugX && netPos.y > minBugY && netPos.y < maxBugY && netPos.z > minBugZ && netPos.z < maxBugZ)
        { bugsList[i].didyagetit = 1; return i; }

} // end of for BUG_COUNT
return -1;
} // end of int getthebug 



#endif
