#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_envp_node	*env;
	t_token		*head;

	if (argc > 1 && argv[1])
		return (0);
	env = get_envp(envp);
	set_signal();
	while (1)
	{
		line = readline("minishell$  ");
		if (!line)
			do_sigterm();
		head = parse_token(line, env);
		add_history(line);
		free(line);
		printf("aaa");
	}
}
