#include "ft_lstadd.h"

int main(int argc, char **argv, char **environ)
{
    (void)argc;
    (void)argv;
    t_list *env;
    t_list *lst;

    lst = NULL;
    env = NULL;
    initialize_env(&env, environ);
    initialize_builtin(&lst);
}