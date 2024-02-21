#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

int handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("the %d key has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("The key %d has been pressed", keysym);
	return (0)
}

int main(void)
{
	t_mlx_data data;

	data.mlx_ptr = mlx_init();	//establishing connection with mlx server
	if (data.mlx_ptr == NULL)
		return (1);

	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 800, "Hello");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}

	mlx_key_hook(data.win_ptr, handle_input, &data);


	mlx_loop(data.mlx_ptr);
}
