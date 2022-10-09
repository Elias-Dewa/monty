#include "monty.h"

global_t global;
/**
 * main - main function for monty code
 * @argc: number of arguments
 * @argv: file location
 *
 * Return - 0 for success
 */
int main(int argc, char *argv[])
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	process_file(argv[1], &stack);
	free_all(stack);
	return (0);
}

/**
 * process_file - function to reads a bytecode file
 * @file_name: name of the file
 * @stack: pointer to head of the stack
 *
 * Return: nothing
 */
void process_file(char *file_name, stack_t **stack)
{
	size_t num = 0;
	int read, num_line = 1;
	char *content;
	instruction_fun str;



	global.file = fopen(file_name, "r");
	if (!global.file)
	{
		fprintf(stderr, "Error: can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&global.buffer, &num, global.file)) != -1)
	{
		content = content_fun(global.buffer, stack, num_line);
		if (!content)
		{
			num_line++;
			continue;
		}

		str = op_fun(content);
		if (!str)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", num_line, content);
			exit(EXIT_FAILURE);
		}
		str(stack, num_line);
		num_line++;
	}
	free(global.buffer);
	fclose(global.file);

}

/**
 * content_fun - function to parse a line
 * @content: the line content to parse
 * @stack: pointer to head of stack
 * @num_line: the number of line
 *
 * Return: opcode or null
 */
char *content_fun(char *content, stack_t **stack, unsigned int num_line)
{
	char *op_code, *push = "push", *arg;
	(void)stack;

	op_code = strtok(content, "\n ");
	if (!op_code)
		return (NULL);
	if (!strcmp(op_code, push))
	{
		arg = strtok(NULL, "\n ");
		if (arg != NULL && isnum(arg) == 1)
		{
			global.push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", num_line);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}

/**
 * op_fun - get the required function for opcode
 * @str: opcode
 *
 * Return: a function or Null
 */
instruction_fun op_fun(char *str)
{
	int i = 0;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"nop", _nop},
	};
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
		i++;
	return (instruct[i].f);
}

/**
 * free - function for free memory allocated
 *
 * Return: Nothing
 */
void free_all(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
