#include "../minishell.h"

char	**make_envbox(t_envp_node *head)
{
	size_t		i;
	size_t		j;
	t_envp_node	*tmp;
	char		**rtn;

	i = 0;
	j = 0;
	tmp = head;
	while (head)
	{
		i++;
		head = head->next;
	}
	rtn = (char **)malloc(sizeof(char *) * (i + 1));
	rtn[i] = 0;
	while (j < i && tmp)
	{
		rtn[j++] = join_n_free(ft_strjoin(tmp->name, "="), \
								ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (rtn);
}

void	make_info(t_envp_node *node, char *envp)
{
	int		idx;
	char	**arr;

	idx = 0;
	arr = ft_split(envp, '=');
	node->name = ft_strdup(arr[0]);
	if (arr[1])
		node->value = ft_strdup(arr[1]);
	free_box(arr);
}

t_envp_node	*make_node(t_envp_node *head, char *envp)
{
	t_envp_node	*node;
	t_envp_node	*temp;

	node = malloc(sizeof(t_envp_node));
	ft_bzero(node, sizeof(t_envp_node));
	make_info(node, envp);
	if (!head)
		return (node);
	else
	{
		temp = head;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
	return (head);
}

t_envp_node	*get_envp(char **envp)
{
	int			idx;
	t_envp_node	*head;

	idx = 0;
	head = NULL;
	while (envp[idx])
	{
		head = make_node(head, envp[idx]);
		idx++;
	}
	return (head);
}
