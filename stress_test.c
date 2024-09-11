#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

void* malloc(size_t size);
void* realloc(void* ptr, size_t size);
void free(void* ptr);
void* calloc(size_t num, size_t size);
size_t get_allocated_memory();
size_t get_free_memory();
void print_memory_usage();
void print_free_list();
void print_pool_status();

#define NUM_ALLOCATIONS 1000
#define MAX_ALLOCATION_SIZE 1024
#define NUM_OPERATIONS 10000

typedef struct {
    void* ptr;
    size_t size;
} Allocation;

Allocation allocations[NUM_ALLOCATIONS];

void perform_random_allocation() {
    int index = rand() % NUM_ALLOCATIONS;
    size_t size = (rand() % MAX_ALLOCATION_SIZE) + 1;
    if (allocations[index].ptr != NULL) {
        free(allocations[index].ptr);
    } allocations[index].ptr = malloc(size);
    allocations[index].size = size;
    assert(allocations[index].ptr != NULL);
    memset(allocations[index].ptr, 0xAA, size);
}

void perform_random_reallocation() {
    int index = rand() % NUM_ALLOCATIONS;
    size_t new_size = (rand() % MAX_ALLOCATION_SIZE) + 1;
    if (allocations[index].ptr != NULL) {
        void* new_ptr = realloc(allocations[index].ptr, new_size);
        assert(new_ptr != NULL);
        allocations[index].ptr = new_ptr;
        allocations[index].size = new_size;
    } else {
        allocations[index].ptr = malloc(new_size);
        assert(allocations[index].ptr != NULL);
        allocations[index].size = new_size;
    } memset(allocations[index].ptr, 0xBB, new_size);
}

void perform_random_free() {
    int index = rand() % NUM_ALLOCATIONS;
    if (allocations[index].ptr != NULL) {
        free(allocations[index].ptr);
        allocations[index].ptr = NULL;
        allocations[index].size = 0;
    }
}

int run_stress_test() {
    srand(time(NULL));
    for (int i = 0; i < NUM_ALLOCATIONS; i++) {
        allocations[i].ptr = NULL;
        allocations[i].size = 0;
    } printf("Starting stress test...\n");
    print_pool_status();
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        int operation = rand() % 3;
        switch (operation) {
            case 0:
                perform_random_allocation();
                break;
            case 1:
                perform_random_reallocation();
                break;
            case 2:
                perform_random_free();
                break;
        } if (i % 1000 == 0) {
            printf("Operation %d completed\n", i);
            print_memory_usage();
        }
    } printf("Stress test completed.\n");
    print_memory_usage();
    print_free_list();
    print_pool_status();
    for (int i = 0; i < NUM_ALLOCATIONS; i++) {
        if (allocations[i].ptr != NULL) {
            free(allocations[i].ptr);
        }
    } printf("Final state after cleanup:\n");
    print_memory_usage();
    print_free_list();
    print_pool_status();
    return 0;
}
