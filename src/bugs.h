#IFNDEF "bugsH"
#DEFINE "bugsH"

#include "stdio.h"
#include "raylib.h"


typedef struct {
        int bugType;
        int didyagetit;
} bugsarrayvar;

// our bug list, tracks all the bugs and whether we've caught them or nay
// bug ID and bugsList index is the same for simplicity
bugsarrayvar bugsList[1];



// returns the caught bug maybe
int getthebug(Vector3 playerPos, Vector2 facing, Vector3 bugPos, int bugType) {

int minBugX = bugPos - 0.2f;
int minBugY = bugPos - 0.2f;
int minBugZ = bugPos - 0.2f;

int maxBugX = bugPos + 0.2f;
int maxBugY = bugPos + 0.2f;
int maxBugZ = bugPos + 0.2f;


// the actual function logic stuff
if(bugPos.x > minBugX && bugPos.x < maxBugX && bugPos.y > minBugY && bugPos.y < maxBugY && bugPos.z > minBugZ && bugPos.z < maxBugZ)
{ bugsList[bugType].didyagetit = 1; return bugType; }

} // end of int getthebug 



#ENDIF