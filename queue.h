#ifndef __libapi_QUEUE_H_
#define __libapi_QUEUE_H_


enum arg_type {
    integer,
    character,
    floating,
    long_int,
    double_float,
    short_int,
    charp,
    intp,
    floatp,
    longp,
    doublep,
    shortp,
    voidp
};

typedef struct {
    enum arg_type type;
    union Data {
        int integer;
        char character;
        float floating;
        long int lint;
        double dfloat;
        short sint;
        char *charp;
        int *intp;
        float *floatp;
        long int *longp;
        double *doublep;
        short *shortp;
        void *voidp;
    } data;
} arg_t;

typedef struct {
    int argc;
    arg_t *args;
    void (*callee)(arg_t*);
} executor_t;

typedef struct {
    int index;
    int n;
    executor_t *queue;
} queue_t;


executor_t *e_setup(int argc, arg_t *args, void *f);
queue_t *e_queue_setup(int n);
queue_t *e_enqueue(queue_t *q, executor_t *e);
int e_run(queue_t *q);
int e_free(queue_t *q);


#endif
