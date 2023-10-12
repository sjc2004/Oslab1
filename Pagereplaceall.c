#include <stdio.h>
#include <stdbool.h>

// Function for FIFO page replacement
void fifo(int frames, int pages, int incomingStream[]) {
    int frame[frames];
    int i, j;
    int pageFaults = 0;

    for (i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames with -1 indicating they are empty.
    }

    printf("Incoming \t");

    for (i = 1; i <= frames; i++) {
        printf("Frame %d \t", i);
    }

    for (i = 0; i < pages; i++) {
        bool isPageFault = true;

        for (j = 0; j < frames; j++) {
            if (frame[j] == incomingStream[i]) {
                isPageFault = false;
                break;
            }
        }

        if (isPageFault) {
            frame[pageFaults % frames] = incomingStream[i];
            pageFaults++;
        }

        printf("\n%d\t\t\t", incomingStream[i]);

        for (j = 0; j < frames; j++) {
            if (frame[j] != -1) {
                printf(" %d\t\t\t", frame[j]);
            } else {
                printf(" - \t\t\t");
            }
        }
    }

    printf("\nTotal Page Faults (FIFO):\t%d\n", pageFaults);
}

// Function for LRU page replacement
void lru(int frames, int pages, int incomingStream[]) {
    int frame[frames];
    int counter[frames];
    int i, j, k;
    int pageFaults = 0;

    for (i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames with -1 indicating they are empty.
        counter[i] = 0; // Initialize counters for each frame.
    }

    printf("Incoming \t");

    for (i = 1; i <= frames; i++) {
        printf("Frame %d \t", i);
    }

    for (i = 0; i < pages; i++) {
        bool isPageFault = true;

        for (j = 0; j < frames; j++) {
            if (frame[j] == incomingStream[i]) {
                counter[j] = i; // Update the counter for the used page.
                isPageFault = false;
            }
        }

        if (isPageFault) {
            int min = counter[0];
            int replaceIndex = 0;

            for (k = 1; k < frames; k++) {
                if (counter[k] < min) {
                    min = counter[k];
                    replaceIndex = k;
                }
            }

            frame[replaceIndex] = incomingStream[i]; // Replace the least recently used page.
            counter[replaceIndex] = i;
            pageFaults++;
        }

        printf("\n%d\t\t\t", incomingStream[i]);

        for (j = 0; j < frames; j++) {
            if (frame[j] != -1) {
                printf(" %d\t\t\t", frame[j]);
            } else {
                printf(" - \t\t\t");
            }
        }
    }

    printf("\nTotal Page Faults (LRU):\t%d\n", pageFaults);
}

// Function for Optimal page replacement
void optimal(int frames, int pages, int incomingStream[]) {
    int frame[frames];
    int i, j, k;
    int pageFaults = 0;

    for (i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames with -1 indicating they are empty.
    }

    printf("Incoming \t");

    for (i = 1; i <= frames; i++) {
        printf("Frame %d \t", i);
    }

    for (i = 0; i < pages; i++) {
        bool isPageFault = true;

        for (j = 0; j < frames; j++) {
            if (frame[j] == incomingStream[i]) {
                isPageFault = false;
                break;
            }
        }

        if (isPageFault) {
            int pageToReplace = -1;
            int farthestUse = -1;

            for (j = 0; j < frames; j++) {
                int nextPageUse = 0;

                for (k = i + 1; k < pages; k++) {
                    if (incomingStream[k] == frame[j]) {
                        nextPageUse = k;
                        break;
                    }
                }

                if (nextPageUse == 0) {
                    pageToReplace = j;
                    break;
                }

                if (nextPageUse > farthestUse) {
                    farthestUse = nextPageUse;
                    pageToReplace = j;
                }
            }

            frame[pageToReplace] = incomingStream[i]; // Replace the page that won't be used for the longest time in the future.
            pageFaults++;
        }

        printf("\n%d\t\t\t", incomingStream[i]);

        for (j = 0; j < frames; j++) {
            if (frame[j] != -1) {
                printf(" %d\t\t\t", frame[j]);
            } else {
                printf(" - \t\t\t");
            }
        }
    }

    printf("\nTotal Page Faults (Optimal):\t%d\n", pageFaults);
}

// Function for MRU page replacement
void mru(int frames, int pages, int incomingStream[]) {
    int frame[frames];
    int i, j;
    int pageFaults = 0;

    for (i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames with -1 indicating they are empty.
    }

    printf("Incoming \t");

    for (i = 1; i <= frames; i++) {
        printf("Frame %d \t", i);
    }

    for (i = 0; i < pages; i++) {
        bool isPageFault = true;

        for (j = 0; j < frames; j++) {
            if (frame[j] == incomingStream[i]) {
                isPageFault = false;
                // Move the recently used page to the front of the frame.
                int temp = frame[j];
                for (int k = j; k > 0; k--) {
                    frame[k] = frame[k - 1];
                }
                frame[0] = temp;
                break;
            }
        }

        if (isPageFault) {
            for (j = frames - 1; j > 0; j--) {
                frame[j] = frame[j - 1];
            }
            frame[0] = incomingStream[i]; // Place the newly requested page in the most recently used frame.
            pageFaults++;
        }

        printf("\n%d\t\t\t", incomingStream[i]);

        for (j = 0; j < frames; j++) {
            if (frame[j] != -1) {
                printf(" %d\t\t\t", frame[j]);
            }
            if (frame[j] != -1) {
                printf(" %d\t\t\t", frame[j]);
            } else {
                printf(" - \t\t\t");
            }
        }
    }

    printf("\nTotal Page Faults (MRU):\t%d\n", pageFaults);
}

int main() {
    int frames, pages;

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    printf("Enter the number of elements in the incoming page reference stream: ");
    scanf("%d", &pages);

    int incomingStream[pages];

    printf("Enter the elements in the incoming page reference stream:\n");
    for (int m = 0; m < pages; m++) {
        scanf("%d", &incomingStream[m]);
    }

    int choice;

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. FIFO\n");
        printf("2. LRU\n");
        printf("3. Optimal\n");
        printf("4. MRU\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fifo(frames, pages, incomingStream);
                break;
            case 2:
                lru(frames, pages, incomingStream);
                break;
            case 3:
                optimal(frames, pages, incomingStream);
                break;
            case 4:
                mru(frames, pages, incomingStream);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
