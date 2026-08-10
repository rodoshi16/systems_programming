#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

/*

1. What does it print if no interrupt, we dont press ctrl+c -> start outside 7
2. If interrput at Pos A: start

At pos A, we only have the default signal which is to quit and that is executed

3. If interupt at Pos B: start inside 8 outside 10

It will execute the handler then come back where it left off and finish - like your doy function

4. If interrupt at pos C: start inside 10 outside 10 

X already increments and then when we get back just print outside 10




*/


int x = 5;

void handler(int sig) {
    x += 3;
    fprintf(stderr, "inside %d ", x);
}

int main() {
    fprintf(stderr, "start ");
    //                             POSITION A
    struct sigaction act;
    act.sa_handler = handler;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGINT,&act,NULL);

    //                             POSITION B
    x += 2;

    //                             POSITION C
    fprintf(stderr, "outside %d", x);

    return 0;
}
