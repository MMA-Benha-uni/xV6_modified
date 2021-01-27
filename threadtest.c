#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#define NULL (void *)(0)

void twahod(void *a, void *b){

    printf(1, "Hello twahod\n");
    printf(1, "%d \n%d\n", *(int*) a, *(int*) b);
    exit();
}

void print_numbers(int n) {
	if(n == 0) return;
	print_numbers(n - 1);
	printf(1, "%d ", n);
}

void fu(void* a, void* b){
	printf(1, "The numbers from 1 to 10 is:\n");
	print_numbers(10);
	printf(1, "\n");
  thread_create(&twahod, a, b);
  thread_join();
  exit();
}

int
main(int argc, char *argv[])
{
  int first = 100, second = 200;
  printf(1, "Create thread\n");
  thread_create(&fu, (void *)&first, (void *)&second);
  thread_join();
  thread_create(&twahod, (void *)&first, (void *)&second);
  thread_join();
  printf(1, "done\n");
  exit();

}
