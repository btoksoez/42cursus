/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:16:50 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/18 11:50:53 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "libft/libft.h"
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

// screen size
# define WIDTH 1000
# define HEIGHT 1000

// sets
# define MANDELBROT 1
# define JULIA 2
# define MANDELBOX 3

// palette size
# define PALETTE_SIZE 256

// colors
# define GRAD_START 0x0000000
# define GRAD_END 0x9966FF

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

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}		t_rgb;

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
	int			name;
	void		*mlx;
	void		*win;
	t_img		img;
	double		zoom;
	int			max_iter;
	double		threshold;
	t_complex	julia_c;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	int			palette[PALETTE_SIZE];
	int			fast;
	double		box_s;
	double		box_r;
	double		box_f;

}	t_fractal;

/* rendering */
double	map(double value, double old_max, double new_min, double new_max);
void	fractal_render(t_fractal *fractal);
void	my_pixel_put(int x, int y, t_img *img, int color);

/* parsing arguments */
int		check_julia_params(char *argv[]);
int		check_julia(int argc, char *argv[], t_fractal *fractal);
int		parse_args(int argc, char *argv[], t_fractal *fractal);
int		help_message(int n);
double	ft_atof(const char *n);
int		fractal_fast(int argc, char *argv[], t_fractal *fractal);

/* initialization	*/
void	get_initial_size(t_fractal *f);
void	data_init(t_fractal *fractal);
void	events_init(t_fractal *fractal);
void	fractal_init(t_fractal *fractal);

/* events */
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
int		key_press(int keysym, t_fractal *fractal);
int		close_window(t_fractal *fr);
void	malloc_error(void);

/* sets */
int		mandelbrot(t_complex c, t_fractal *fractal);
int		julia(t_complex z, t_fractal *f);
int		mandelbox(t_complex c, t_fractal *f);

/* colors */
void	init_palette(t_fractal *fractal);
int		get_gradient(int startColor, int endColor, int steps);

#endif
