#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 2000
# define HEIGHT 1500

//sets
# define MANDELBROT 1
# define JULIA 2


//colors
# define BLACK 0x0000000
# define WHITE 0xFFFFFFF

// Psychedelic Colors
# define PSY_PINK 0xFF1493
# define PSY_PURPLE 0x9b30ff
# define PSY_BLUE 0x6600FF
# define PSY_GREEN 0x00FF00
# define PSY_YELLOW 0xFFFF00
# define PSY_ORANGE 0xFF7F00
# define PSY_RED 0xFF0000
# define PSY_CYAN 0x00FFFF
# define PSY_TEAL 0x008080
# define PSY_LIME 0xBFFF00
# define PSY_MAGENTA 0xFF00FF
# define PSY_TURQUOISE 0x40E0D0



typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_fractal
{
	int		name;
	void	*mlx;
	void	*win;
	t_img	img;
	double		zoom;
	int		max_iter;
	double	threshold;
	t_complex	julia_c;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;

}	t_fractal;

void	fractal_init(t_fractal *fractal);

int		close_window(t_fractal *fr);
void	malloc_error(void);
double	map(double value, double old_min, double old_max, double new_min, double new_max);
void		handle_pixel(int x, int y, t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
void my_pixel_put(int x, int y, t_img *img, int color);

/* parsing arguments */
int		check_julia(char *argv[]);
int		parse_args(int argc, char *argv[], t_fractal *fractal);
int		help_message(int n);

/* initialization	*/
void	get_initial_size(t_fractal *f);
void	data_init(t_fractal *fractal);
void	events_init(t_fractal *fractal);
void	fractal_init(t_fractal *fractal);

/* events */
int mouse_hook(int button, int x, int y, t_fractal *fractal);
int key_press(int keysym, t_fractal *fractal);
int close_window(t_fractal *fr);

/* sets */
int		mandelbrot(t_complex c, t_fractal *fractal);
int		julia(t_complex z, t_fractal *f);

#endif
