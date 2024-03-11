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

# define WIDTH 800
# define HEIGHT 800

//sets
# define MANDELBROT 1


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

typedef struct s_fractal
{
	int		name;
	void	*mlx;
	void	*win;
	t_img	img;
	double		zoom;
	double		shiftx;
	double		shifty;
	int		max_iter;
	double	threshold;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;

}	t_fractal;

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

void	fractal_init(t_fractal *fractal);
int		is_mandelbrot(t_complex c, t_fractal *fractal);
void	ft_julia(char *ag1, char *arg2);
int		close_window(t_fractal *fr);
void	malloc_error(void);
double	map(double value, double old_min, double old_max, double new_min, double new_max);
void		handle_pixel(int x, int y, t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
void my_pixel_put(int x, int y, t_img *img, int color);

/* initialization	*/
void	get_initial_size(t_fractal *f);

/* events */
int mouse_hook(int button, int x, int y, t_fractal *fractal);
int key_press(int keysym, t_fractal *fractal);
int close_window(t_fractal *fr);


#endif
