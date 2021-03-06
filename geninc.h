#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <unistd.h>
/**********PCB**
* should be used to created the pcb and
* hold the ustilities that the pcb will be using
* each process will have a PCB
***************/
struct PCB{
  int priority;
  int cpu_burst[];
  int io_burst[];
  int cpu;
  int io;
  int Wtime;
};

FILE * file_open();
struct PCB init_PCB();
void error_exit(char*, int);
void *reading(FILE *, struct PCB []);
void sjf();
void fifo(FILE *);
void rr();
void pr();
void decision_time(FILE * fp); //name to be changed at a later date
void check_args(int, char *args[]);

char *get_next_word(FILE *);
