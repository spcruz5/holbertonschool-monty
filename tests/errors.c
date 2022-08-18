	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY)
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	for (i = 0; flag != EOF; i++)
	{
		flag = getline(&lineptr, &n, fd);
		lineno++;
		if (flag > 0)
			purse = tokenize(lineptr);
		for (j = 0; purse[j]; j++)
		{
			ptr = matchf(purse[j]);
			if (ptr)
			{
				if (check == 1)
				{
					ares = atoi(purse[j + 1]);
					if(ares !=  0)
						ptr(&head, ares);
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", lineno);
						exit(EXIT_FAILURE);
					}
				}
				else
					ptr(&head, lineno);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction\n", lineno);
				exit(EXIT_FAILURE);
			}
		}
	}
return (0);
