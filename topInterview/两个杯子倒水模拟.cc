#include <bits/stdc++.h>
using namespace std;
/*
两个杯子，一个盛三升水，一个盛四升水，要得到两升水
*/
// 其实就是表示当前的状态，然后进行状态的bfs
typedef struct state{
    int a, b;
    const struct state* parent;
    const char* action;
}state_t;

#define M 3
#define N 4

#define R 2
int visited[M + 1][N + 1];
state_t q[(M + 1) * (N + 1)];

int front = 0, back = 0;

void enqueue(int a, int b, const state_t* parent, const char* action) {
    if (!visited[a][b]) {
        state_t s = {a, b, parent, action};
        q[back++] = s;
        visited[a][b] = 1;
    }
}

void backtrace(const state_t* s) {
    if(s){
        backtrace(s->parent);
        printf("(%d, %d) %s\n", s->a, s->b, s->action);
    }
}
int main() {
    enqueue(0, 0, NULL, "Initialize");
    while(front < back) {
        state_t* s = &q[front++];
        if (s->a == R || s->b == R) {
            backtrace(s);
            printf("\n");
            continue;
        }

        enqueue(0, s->b, s, "Clear A");
        enqueue(s->a, 0, s, "Clear B");
        enqueue(M, s->b, s, "Fill A");
        enqueue(s->a, N, s, "Fill B");
        int t1 = ::min(s->b, M - s->a);
        int t2 = ::min(s->a, N - s->b);
        enqueue(s->a + t1, s->b - t1, s, "Fill A by B");
        enqueue(s->a - t2, s->b + t2, s, "Fill B by A");
    }
}
