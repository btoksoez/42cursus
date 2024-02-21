#include "put_pixel.h"

int button_press(int button, int x, int y, t_vars *var)
{
    if (button == 1)
	{
        printf("Left mouse button pressed at (%d, %d)!\n", x, y);
		color_screen(var, 0xff);
	}
    else if (button == 3)
	{
        printf("Right mouse button pressed at (%d, %d)!\n", x, y);
		color_screen(var, 0xff00);
	}


	return (0);
}

int close_window(t_vars *var)
{
	printf("Closing Window");
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_image(var->mlx, var->img.img_ptr);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	exit(1);
}

void color_screen(t_vars *var, int color) {
    int x, y;
    unsigned int *img_pixels = (unsigned int *)var->img.img_pixels_ptr;
    for (y = 0; y < SIDE_LEN; ++y) {
        for (x = 0; x < SIDE_LEN; ++x) {
            img_pixels[y * SIDE_LEN + x] = color; // Set pixel color directly in image data
        }
    }
    mlx_put_image_to_window(var->mlx, var->win, var->img.img_ptr, 0, 0); // Display modified image
}

int key_press(int keysym, t_vars *var)
{
	if (keysym == XK_Escape)
	{
		close_window(var);
	}
}

int main(void)
{
	t_vars var;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 800, 800, "pixel");

	var.img.img_ptr = mlx_new_image(var.mlx, SIDE_LEN, SIDE_LEN);
	var.img.img_pixels_ptr = mlx_get_data_addr(var.img.img_ptr,
												&var.img.bits_per_pixel,
												&var.img.line_len,
												&var.img.endian);

	mlx_hook(var.win, ButtonPress, ButtonPressMask, &button_press, &var);
	mlx_hook(var.win, KeyPress, KeyPressMask, &key_press, &var);
	mlx_hook(var.win, DestroyNotify, StructureNotifyMask, &close_window, &var);
	mlx_loop(var.mlx);
	return (0);
}
