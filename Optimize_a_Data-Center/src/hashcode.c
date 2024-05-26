#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashcode.h"

int R, S, U, P, M;
int unavailableSlots[MAX_R][MAX_S];
Server servers[MAX_M];

void read_input() {
    scanf("%d %d %d %d %d", &R, &S, &U, &P, &M);

    memset(unavailableSlots, 0, sizeof(unavailableSlots));

    for (int i = 0; i < U; i++) {
        int r, s;
        scanf("%d %d", &r, &s);
        unavailableSlots[r][s] = 1;
    }

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &servers[i].size, &servers[i].capacity);
        servers[i].allocated = 0;
    }
}

int can_place_server(int row, int slot, int size) {
    for (int i = 0; i < size; i++) {
        if (slot + i >= S || unavailableSlots[row][slot + i] == 1) {
            return 0;
        }
    }
    return 1;
}

void allocate_servers() {
    int pool = 0;
    for (int i = 0; i < M; i++) {
        int placed = 0;
        for (int r = 0; r < R && !placed; r++) {
            for (int s = 0; s <= S - servers[i].size; s++) {
                if (can_place_server(r, s, servers[i].size)) {
                    servers[i].row = r;
                    servers[i].slot = s;
                    servers[i].pool = pool;
                    servers[i].allocated = 1;
                    for (int j = 0; j < servers[i].size; j++) {
                        unavailableSlots[r][s + j] = 1;
                    }
                    placed = 1;
                    pool = (pool + 1) % P;
                    break;
                }
            }
        }
        if (!placed) {
            servers[i].allocated = 0;
        }
    }
}

void output_solution() {
    for (int i = 0; i < M; i++) {
        if (servers[i].allocated) {
            printf("%d %d %d\n", servers[i].row, servers[i].slot, servers[i].pool);
        } else {
            printf("x\n");
        }
    }
}
