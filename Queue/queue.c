#include "queue.h"
 
int main()
{
    queue Q;
    init(&Q, 10);
    printf("%d\n", isEmpty(&Q));
    printf("%d\n", isFull(&Q));
    printf("%d\n", enqueue(&Q, 10));
    printf("%d\n", enqueue(&Q, 10));
    printf("%d\n", enqueue(&Q, 10));
    printf("%d\n", enqueue(&Q, 10));
    printf("%d\n", enqueue(&Q, 10));
    printf("%d\n", enqueue(&Q, 10));
    printf("%d\n", enqueue(&Q, 10));
    printf("%d\n", enqueue(&Q, 10));
    printf("%d\n", enqueue(&Q, 10));
    printf("%d\n", enqueue(&Q, 10));
    printf("%d\n", enqueue(&Q, 10));
    display(&Q);
    return 0;
}
