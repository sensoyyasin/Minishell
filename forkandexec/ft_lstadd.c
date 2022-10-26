#include "ft_lstadd.h"

void    ft_lstadd(t_list **head, t_list *new)
{
    if (head == NULL || new == NULL)
        return ;
        new->next = *head;
        *head = new;
}

static void add_builtin(t_list **lst, char *cmd, void (*f)())
{
    t_builtin *builts;

    builts = (t_builtin*)malloc(sizeof(t_builtin));
    builts->cmd = (char *)malloc(sizeof(char) * (ft_strlen(cmd) + 1));
    ft_strcpy(builts->cmd, cmd);
    builts->f = f;
    ft_lstadd(lst, ft_lstnew(builts, 0));
}

void		init_builtin(t_list **lst)
{
	add_builtin(lst, "echo", &ft_echo);
	add_builtin(lst, "cd", &ft_cd);
	add_builtin(lst, "env", &ft_env);
	add_builtin(lst, "pwd", &ft_pwd);
	add_builtin(lst, "setenv", &ft_setenv);
	add_builtin(lst, "unsetenv", &ft_unsetenv);
}