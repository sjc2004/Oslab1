#include<stdio.h>
#include <stdlib.h>

void reframe(int * frame, int frames, int index) {
    /* send the current index to the end of the array */
    int k, temp;
    for (k = index; k < frames - 1; k++) { //iterate frame
        temp = * (frame + k);
        *(frame + k) = * (frame + k + 1);
        *(frame + k + 1) = temp;
        //printf("%d ",*(frame+k));
    }
    //printf("\n");
}

int lru(int csno, int * controlstring, int frames) {
    int pf = 1, * frame, i, j = 0, k, avail = 0, index;
    frame = calloc(sizeof(int), frames);
    for (i = 0; i < csno; i++) {
        /*iterate cntro string */
        avail = 0;
        for (k = 0; k < frames; k++) { //iterate frame
            printf("%d ", *(frame + k));
            if ( * (frame + k) == * (controlstring + i)) {
                avail = 1;
                index = k;
            }
        }
        // printf("\n");
        if (avail == 1) {
            /*if element available in frame */
            reframe(frame, frames, index);
        } else {
            /*element not available in frame */
            *(frame + 0) = * (controlstring + i);
            reframe(frame, frames, 0);
            pf++;
        }
        printf("\n");
    }
    for (k = 0; k < frames; k++)
        printf("%d ", *(frame + k));
    return pf;
}
int main() {
    int csno, i, * controlstring, frames, pf;
    printf("enter the no of control strings:");
    scanf("%d", & csno);

    controlstring = malloc(sizeof(int) * csno);

    printf("enter the control strings:");
    for (i = 0; i < csno; i++) {
        scanf("%d", controlstring + i);
    }

    printf("enter the no of frames:");
    scanf("%d", & frames);

    pf = lru(csno, controlstring, frames);

    printf("no of page fault is %d", pf);
    return 0;
}
