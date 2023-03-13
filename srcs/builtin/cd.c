#include "../../minishell.h"

t_envp_node	*find_envp_node(char *str, t_envp_node *node)
{
	while (node)
	{
		if (!(name_cmp(str, node->name, ft_strlen(str))))
			return (node);
		node = node->next;
	}
	return (0);
}

char	*change_home_dir(t_envp_node *head)
{
	t_envp_node	*node;
	char		*path;

	node = find_envp_node("HOME", head);
	if (!node)
	{
		printf("minishell: cd: HOME not set\n");
		return (0);
	}
	path = node->value;
	return (path);
}

void	change_pwd(t_envp_node *head)
{
	t_envp_node	*node;
	t_envp_node	*oldpwd;

	node = find_envp_node("PWD", head);
	oldpwd = find_envp_node("OLDPWD", head);
	if (oldpwd->value)
		free(oldpwd->value);
	oldpwd->value = node->value;
	node->value = getcwd(0, 0);
}

void	command_cd(char **arr, t_envp_node *head)
{
	char *path;

	if (!arr[1])
		path = change_home_dir(head);
	else
		path = arr[1];
	if (!path)
		return ;
	if (chdir(path))
	{
		printf("minishell: cd: %s: No such file or directory\n", path);
		return ;
	}
	change_pwd(head);
}