
#ifndef HASHCODE_H
#define HASHCODE_H

#define MAX_R 1000
#define MAX_S 1000
#define MAX_M 1000
#define MAX_P 1000

typedef struct {
    int size;
    int capacity;
    int row;
    int slot;
    int pool;
    int allocated;
} Server;

extern int R, S, U, P, M;
extern int unavailableSlots[MAX_R][MAX_S];
extern Server servers[MAX_M];

void read_input();
int can_place_server(int row, int slot, int size);
void allocate_servers();
void output_solution();

#endif // HASHCODE_H
