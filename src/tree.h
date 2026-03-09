#ifndef TREE_H
#define TREE_H

#include <raylib.h>
#include <stdlib.h>
#include <time.h>

typedef struct Tree{
    Vector3 pos;
}Tree;

#define TREE_COUNT 16

Tree trees[TREE_COUNT];

Model tree_model;

void create_random_trees(){
    srand(time(NULL));

    tree_model = LoadModel("resources/tree.obj");

    for(int i = 0; i < TREE_COUNT; i++){
        trees[i].pos.x = rand() % 40;
        trees[i].pos.y = 0;
        trees[i].pos.z = rand() % 40;

        trees[i].pos.x = trees[i].pos.x - (40.0f / 2.0f);
        trees[i].pos.z = trees[i].pos.z - (40.0f / 2.0f);

    }

}

#endif // !TREE_H
