#ifndef PUT_PIXEL_H
# define PUT_PIXEL_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>

# define SIDE_LEN 800

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_vars;




int button_press(int button, int x, int y, t_vars *var);
int close_window(t_vars *var);

void color_screen(t_vars *var, int color);
int key_press(int keysym, t_vars *var);

#endif
