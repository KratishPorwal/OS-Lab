#include <stdio.h>

#define MAX 100

void printFrames(int frame[], int frames) {
    for (int i = 0; i < frames; i++) {
        if (frame[i] == -1)
            printf("- ");
        else
            printf("%d ", frame[i]);
    }
    printf("\n");
}

int isInFrame(int frame[], int frames, int page) {
    for (int i = 0; i < frames; i++)
        if (frame[i] == page)
            return 1;
    return 0;
}

void fifo(int pages[], int n, int frames) {
    int frame[frames];
    int pointer = 0, faults = 0;

    for (int i = 0; i < frames; i++) frame[i] = -1;

    printf("\nFIFO Page Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        if (!isInFrame(frame, frames, pages[i])) {
            frame[pointer] = pages[i];
            pointer = (pointer + 1) % frames;
            faults++;
            printf("PF No. %d: ", faults);
            printFrames(frame, frames);
        }
    }

    printf("FIFO Page Faults: %d\n", faults);
}

void lru(int pages[], int n, int frames) {
    int frame[frames], time[frames];
    int count = 0, faults = 0;

    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        count++;
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                time[j] = count;
                found = 1;
                break;
            }
        }

        if (!found) {
            int lru = 0;
            for (int j = 1; j < frames; j++) {
                if (time[j] < time[lru])
                    lru = j;
            }
            frame[lru] = pages[i];
            time[lru] = count;
            faults++;
            printf("PF No. %d: ", faults);
            printFrames(frame, frames);
        }
    }

    printf("LRU Page Faults: %d\n", faults);
}

void optimal(int pages[], int n, int frames) {
    int frame[frames];
    int faults = 0;

    for (int i = 0; i < frames; i++) frame[i] = -1;

    printf("\nOptimal Page Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        if (!isInFrame(frame, frames, pages[i])) {
            int pos = -1, farthest = i;
            for (int j = 0; j < frames; j++) {
                int k;
                for (k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k]) break;
                }
                if (k > farthest) {
                    farthest = k;
                    pos = j;
                }
                if (k == n) {
                    pos = j;
                    break;
                }
            }
            if (pos == -1) {
                for (int j = 0; j < frames; j++) {
                    if (frame[j] == -1) {
                        pos = j;
                        break;
                    }
                }
            }
            frame[pos] = pages[i];
            faults++;
            printf("PF No. %d: ", faults);
            printFrames(frame, frames);
        }
    }

    printf("Optimal Page Faults: %d\n", faults);
}

int main() {
    int frames, n, pages[MAX];

    printf("Enter the number of Frames: ");
    scanf("%d", &frames);
    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    fifo(pages, n, frames);
    lru(pages, n, frames);
    optimal(pages, n, frames);

    return 0;
}
