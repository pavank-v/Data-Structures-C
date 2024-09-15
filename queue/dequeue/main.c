#include <stdio.h>
#include "deque.h"

int main(){
    Deque* deque = create_deque(10);

    insert_front(deque, 32);
    insert_front(deque, 23);
    printf("%d deleted from deque\n", delete_front(deque));

    insert_rear(deque, 34);
    insert_rear(deque, 34523);
    printf("%d deleted from deque\n", delete_rear(deque));

    free_deque(deque);
    return 0;
}