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
int getthebug(Vector3 playerPos, Vector2 facing, Vector3 bugPos, int bugType) {

int minBugX = bugPos.x - 0.2f;
int minBugY = bugPos.y - 0.2f;
int minBugZ = bugPos.z - 0.2f;

int maxBugX = bugPos.x + 0.2f;
int maxBugY = bugPos.y + 0.2f;
int maxBugZ = bugPos.z + 0.2f;


// the actual function logic stuff
if(bugPos.x > minBugX && bugPos.x < maxBugX && bugPos.y > minBugY && bugPos.y < maxBugY && bugPos.z > minBugZ && bugPos.z < maxBugZ)
{ bugsList[bugType].didyagetit = 1; return bugType; }

} // end of int getthebug 



#endif
