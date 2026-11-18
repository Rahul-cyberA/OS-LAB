#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int pipe_fds[2];

	if (pipe(pipe_fds) == -1) {
		perror("pipe");
		return EXIT_FAILURE;
	}

	pid_t child = fork();
	if (child == -1) {
		perror("fork");
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		return EXIT_FAILURE;
	}

	if (child == 0) {
		close(pipe_fds[0]);

		for (int number = 2; number <= 20; number += 2) {
			if (write(pipe_fds[1], &number, sizeof(number)) != sizeof(number)) {
				perror("write");
				close(pipe_fds[1]);
				_exit(EXIT_FAILURE);
			}
		}

		close(pipe_fds[1]);
		_exit(EXIT_SUCCESS);
	}

	close(pipe_fds[1]);
	printf("Even numbers received from child: ");

	int number;
	ssize_t bytes_read;
	int result = EXIT_SUCCESS;
	while ((bytes_read = read(pipe_fds[0], &number, sizeof(number))) > 0) {
		if (bytes_read != sizeof(number)) {
			fprintf(stderr, "Incomplete number received through pipe\n");
			result = EXIT_FAILURE;
			break;
		}
		printf("%d ", number);
	}

	if (bytes_read == -1) {
		perror("read");
		result = EXIT_FAILURE;
	}

	close(pipe_fds[0]);

	int status;
	if (waitpid(child, &status, 0) == -1) {
		perror("waitpid");
		return EXIT_FAILURE;
	}

	putchar('\n');
	if (!WIFEXITED(status) || WEXITSTATUS(status) != EXIT_SUCCESS)
		result = EXIT_FAILURE;
	return result;
}
