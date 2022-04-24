#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

typedef struct s_data
{
	char	*name;
	int		age;
}				t_data;

void	*do_something(void *arg)
{
	t_data	*data;

	data = arg;
	data->age = 100;
	free(data->name);
	data->name = strdup("old_jimpei");
	usleep(1000);
	return (NULL);
}

int	main(void)
{
	pthread_t	tid;
	t_data		data;

	data.age = 0;
	data.name = strdup("jimpei");
	printf("age=%d\nname=%s\n", data.age, data.name);
	pthread_create(&tid, NULL, do_something, (void*)&data);
	printf("age=%d\nname=%s\n", data.age, data.name);
	pthread_join(tid, NULL);
	printf("age=%d\nname=%s\n", data.age, data.name);
	free(data.name);
	return (0);
}