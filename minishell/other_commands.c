#include "minishell.h"

char    **list_changed(t_list *list)
{
    t_list  *temp;
    char    **str;
    int     i;

    i = 0;
    temp = list;
    str = malloc(sizeof(char **) * ft_listsize(list) + 1);
    while (temp != NULL)
    {
        str[i] = ft_strdup(temp->content);
        temp = temp->next;
        i++;
    }
    str[i] = NULL;
    return(str);
}

void    exec_func(char *path, char **arg)
{
    if (execve(path, arg, shell->environ) == -1)
    {
        printf("zsh: command not found\n");
        free(path);
        exit(0);
    }
}

char    *func_path(char **arg)
{
    char    **path;
    char    *temp;
    int     i;

    i = 0;
    temp = getenv("PATH");
    if (access(arg[0], F_OK) == 0)
        return(arg[0]);
    path = ft_split(temp, ':');
    while (path[i])
    {
        path[i] = ft_strjoin(path[i], "/");
        path[i] = ft_strjoin(path[i], arg[0]);
        if (access(path[i], F_OK) == 0)
            break;
        i++;
    }
    return(path[i]);
}

void    other_commands(char **arg)
{
    int pid;

    pid = fork();
    if (pid == 0) // ->child process olusursa.
         exec_func(func_path(arg), arg);
    wait(NULL);
    free(arg);
}
