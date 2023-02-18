#include <stdio.h>
#include <stdlib.h>

struct data {
    int ref_counter;
    char *value;
} typedef watched_counter;

int get_counter(watched_counter *item) {
    return item->ref_counter;
}

void set_counter(watched_counter *item, int value) {
    item->ref_counter = value;
}

void increment_counter(watched_counter *item) {
    int new_counter = get_counter(item) + 1;
    set_counter(item, new_counter);
}

void decrement_counter(watched_counter *item) {
    int new_counter = get_counter(item) - 1;
    if (new_counter == 0) {
        free(item);
        return;
    }
    set_counter(item, new_counter);
}

// gets pointer to desired function as second argument 
void handle_ref_update(watched_counter *item, void (*function)() ) {
    increment_counter(item);
    (*function)();
    decrement_counter(item);
}

void your_function_here(watched_counter item) {
    // change this to whatever you need that uses previously allocated memspace.
    // for now, it only prints something that has absolutely nothing to do with this.    
    // for the sake of teh lulz(tm).
    printf("You've just lost The Game :-)\n");
    // it should update the data somehow, like so:
    // item.value[0] = 'h';
}

watched_counter * allocate(int size, char * value) {
    // must allocate enough space (in bytes) for counter as well
    int total_mem_size = size + 2;
    watched_counter *item;

    item = (watched_counter *) malloc(sizeof(struct data));
    item->ref_counter = 0;
    item->value = value;
    return item;
}

int main(int argc, char **argv) {
    watched_counter *item;

    item = allocate(32678, "testString");
    handle_ref_update(item, your_function_here);

    return 0;
}