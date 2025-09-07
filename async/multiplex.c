#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/event.h>

#define MAX_C 2
#define MAX_E 4

int bsds(){
    int k = kqueue();
    if ( k < 0) exit(1);

    int si = STDIN_FILENO;
    struct kevent ev[MAX_C];
    for (int  i = 0; i < MAX_C; ++i) 
        EV_SET(&ev[i], si, EVFILT_READ, EV_ADD | EV_ENABLE, 0,0, NULL);
    
    while(1) {
        struct kevent es[MAX_E];
        int ne = kevent(k, ev, MAX_C , es, MAX_E, NULL);
        if (ne < 0) exit(1);
    }

}