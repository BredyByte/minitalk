/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:55:04 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/19 12:27:36 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

/* void	fn_createproc(void)
{
	pid_t	pid;
	int		t;
	pid_t	pid;
	pid_t	pid;
	pid_t	pid;

	pid = fork();
	srand(getpid());
	t = rand() % 4;
	printf("children pid: %d, my pid: %d\n", pid, getpid());
	sleep(30);
	printf("finished: %d\n", getpid());
} */
/* void	fn_childproc_execfunc(void)
{
	pid = fork();
	if (pid == 0)
	{
		printf("succed, my pid: %d", getpid());
		exit(pid);
	}
} */
/* void	fn_check_ifprocescreated(void)
{
	pid_t	pid;

	pid = fork();
	if (-1 == pid)
	{
		perrot("Error ocurred");
		exit(1);
	}
	else if (0 == pid)
	{
		printf("im child, here is my code!\n");
		exit(pid);
	}
	else
		printf("My pid: %d, im parent of %d\n", getpid(), pid);
} */

/* void	fd_parent_child_communication(void)
{
	pid_t	pid;
	int		status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		printf("CHILD: my pid: %d\n", getpid());
		printf("CHILD: muy parent's pid: %d\n", getppid());
		printf("CHILD: put return code pls: \n");
		scanf("%d", &status);
		printf("CHILD: bye...\n");
		exit(status);
	}
	else
	{
		printf("PARENT: my pid: %d\n", getpid());
		printf("PARENT: my child's pid: %d\n", pid);
		printf("PARENT: im waiting for the moment"
			"until my descendent calls the exit()commad\n");
		if (wait(&status) == -1)
			perror("wait() error");
		else if (WIFEXITED(status))
			printf("PARENT: returned code is: %d\n", WEXITSTATUS(status));
		else
			perror("PARENT: descendent returned error\n");
	}
	printf("Finish!");
	// WIFEXITED not equal to zero if the child process has completed successfully
} */

/* void	fn_signal_handler(int signum)
{
	printf("Signal received SIGINT\n");
	printf("Exit the program...\n");
	printf("hello: %i\n", signum);
	exit(signum);
}

int	fn_signal_caller(void)
{
	char	input[100];

	signal(SIGINT, fn_signal_handler);
	printf("The program is running. To exit, press Ctrl+C.\n");
	while (1)
	{
		printf("Enter the text:");
		fgets(input, sizeof(input), stdin);
		printf("You entered: %s\n", input);
	}
	return (0);
} */

int	main(void)
{
	// fn_createproc();
	// fn_childproc_execfunc();
	// fn_check_ifprocescreated();
	// fd_parent_child_communication();
	// fn_signal_caller();
	return (0);
}
