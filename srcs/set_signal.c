#include "../minishell.h"

/*
void	signal_exit(int statloc)
{
	if ()
		printf();
	else if ()
		printf("Quit: 3\n");
}
*/

void	signal_heredoc(void)
{
	//signal(SIGINT, do_signal_heredoc);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_dfl(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	signal_ign(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signal(void)
{
	terminal_no_print();
	signal(SIGINT, do_sigint);
	signal(SIGQUIT, SIG_IGN);
}
