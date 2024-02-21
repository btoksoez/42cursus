#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

int     button_press(int button, int x, int y, t_mlx_data *data)
{
    if (button == 1)
        printf("Left mouse button pressed at (%d, %d)!\n", x, y);
    else if (button == 3)
        printf("Right mouse button pressed at (%d, %d)!\n", x, y);

    return (0);
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

	 mlx_hook(data.win_ptr,
            ButtonPress,
            ButtonPressMask,
            &button_press,
            &data);


	mlx_loop(data.mlx_ptr);
}
