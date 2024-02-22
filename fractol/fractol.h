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

# define WIDTH 1920
# define HEIGHT 1080
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
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;

}	t_fractal;

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

void	fractal_init(t_fractal *fractal);
void	ft_mandelbrot(void);
void	ft_julia(char *ag1, char *arg2);
int		close_window(t_fractal *fr);
void	malloc_error(void);
double	map(double value, double old_min, double old_max, double new_min, double new_max);
void		handle_pixel(int x, int y, t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
int		is_mandelbrot(t_complex c);


#endif
