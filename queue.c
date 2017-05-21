#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

executor_t *e_setup(int argc, arg_t *args, void *f){
    executor_t *e = calloc(1, sizeof(executor_t));
    //puts("alloc'd executor_t");
    e->argc = argc;
    e->args = args;
    e->callee = f;
    return e;
}


queue_t *e_queue_setup(int n){
    queue_t *q = calloc(1, sizeof(queue_t));
    //puts("alloc'd queue_t");
    q->queue = calloc(1, sizeof(executor_t) * n);
    //puts("alloc'd queue");
    q->n = n;
    q->index = 0;
    return q;
}


queue_t *e_enqueue(queue_t *q, executor_t *e){
    if(q->n - q->index < 5){
        executor_t *tmp = realloc(q->queue, (q->n + 5) * sizeof(executor_t));
        q->n += 5;
        //puts("realloc'd");
        if(tmp != NULL){
            q->queue = tmp;
        }
    }
    q->queue[q->index].argc = e->argc;
    q->queue[q->index].args = e->args;
    q->queue[q->index++].callee = e->callee;
    free(e);
    return q;
}


int e_run(queue_t *q){
    int i = 0;
    for(i = 0; i < q->index; i++){
        q->queue[i].callee(q->queue[i].args);
    }
    return i;
}

int e_free(queue_t *q){
    if(q != NULL){
        for(int i = 0; i < q->index; i++){
            for(int x = 0; x < q->queue[i].argc; x++){
                switch(q->queue[i].args[x].type){
                    case charp:
                        free(q->queue[i].args[x].data.charp);
                        break;
                    case intp:
                        free(q->queue[i].args[x].data.intp);
                        break;
                    case floatp:
                        free(q->queue[i].args[x].data.floatp);
                        break;
                    case longp:
                        free(q->queue[i].args[x].data.longp);
                        break;
                    case doublep:
                        free(q->queue[i].args[x].data.doublep);
                        break;
                    case shortp:
                        free(q->queue[i].args[x].data.shortp);
                        break;
                    case voidp:                    
                        free(q->queue[i].args[x].data.voidp);                        
                        break;
                    default:
                        break;
                }
                q->queue[i].callee = NULL;
            }
        }
        for(int i = 0; i < q->index; i++){
            free(q->queue[i].args);
        }
        free(q->queue);
        free(q);
        return 0;
    }
    else {
        return 1;
    }
}

