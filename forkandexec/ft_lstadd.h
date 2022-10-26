#ifndef HEADER
# define HEADER

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_list
{
    void    *content;
    struct s_list *next;
}       t_list;

typedef struct s_env
{
    char *name;
    char *value;
}       t_env;

typedef struct s_builtin
{
    char *cmd;
    void (*f)();
}       t_builtin;


#endif