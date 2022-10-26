#include "ft_lstadd.h"

void    initialize_environ(t_list **lst, char **environ)
{
    char **c_env;
    char **temp;

    c_env = environ;
    while (*c_env)
    {
        temp = ft_split(*c_env, '=');
        add_environ(lst, temp[0], temp[1], 0);
        ft_coin_free(temp);
        c_env++;
    }
}

void    add_environ(t_list **lst, char *name, char *value,int the_end)
{
    t_env *x;

    x = (t_env*)malloc(sizeof(t_env));
    x->name = ft_strdup(name);
    x->value = ft_strdup(value);
    if (the_end == 0)
        ft_lst_add(lst, ft_lstnew(x, 0));
    else
        ft_lst_end(lst, ft_lstnew(x, 0));
}