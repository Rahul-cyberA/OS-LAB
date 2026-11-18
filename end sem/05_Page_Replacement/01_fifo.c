#include <stdio.h>

int main()
{
    int n, f, pages[100], frame[20], faults = 0, next = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    if (n < 1 || n > 100 || f < 1 || f > 20) return 1;

    printf("Enter page reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);
    for (int i = 0; i < f; i++) frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++)
            if (frame[j] == pages[i]) found = 1;

        if (!found) {
            frame[next] = pages[i];
            next = (next + 1) % f;
            faults++;
        }

        printf("%d: ", pages[i]);
        for (int j = 0; j < f; j++) {
            if (frame[j] == -1) printf("- ");
            else printf("%d ", frame[j]);
        }
        if (found) printf("Hit");
        else printf("Fault");
        printf("\n");
    }
    printf("Total page faults = %d\n", faults);
    return 0;
}
