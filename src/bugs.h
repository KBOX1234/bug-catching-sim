#ifndef bugsH
#define bugsH

#include "stdio.h"
#include "raylib.h"

#define BUG_COUNT 6


typedef struct {
        int bugType;
        int didyagetit;
        Vector3 pos;

} bugsarrayvar;

// our bug list, tracks all the bugs and whether we've caught them or nay
// bug ID and bugsList index is the same for simplicity
bugsarrayvar bugsList[BUG_COUNT];

void init_bugs(){
    for(int i = 0; i < BUG_COUNT; i++){
        bugsarrayvar* b = &bugsList[i];

        b->pos = (Vector3){0, 0, 0};
        b->bugType = 0;
        b->didyagetit = false;
    }
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
