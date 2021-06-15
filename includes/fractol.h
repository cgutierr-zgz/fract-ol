/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:48:39 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/15 15:25:51 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

// Buttons
# define K_ESC			53
# define K_W			13
# define K_A			0
# define K_S			1
# define K_D			2
# define K_DOWN			125
# define K_LEFT			123
# define K_RIGHT		124
# define K_UP			126
# define K_PLUS			30
# define K_LESS			44
# define K_ENTER		36
# define SCROLL_UP		4
# define SCROLL_DOWN	5

// X11 Events
# define KEY_PRESS				02
# define KEY_RELEASE			03
# define BUTTON_PRESS			04
# define BUTTON_RELEASE			05
# define MOTION_NOTIFY			06
# define ENTER_NOTIFY			07
# define LEAVE_NOTIFY			08
# define FOCUS_IN				09
# define FOCUS_OUT				10
# define KEYMAP_NOTIFY			11
# define EXPOSE					12
# define GRAPHIC_EXPOSE			13
# define NO_EXPOSE				14
# define VISIBILITY_NOTIFY		15
# define CREATE_NOTIFY			16
# define DESTROY_NOTIFY			17
# define UNMAP_NOTIFY			18
# define MAP_NOTIFY				19
# define MAP_REQUEST			20
# define REPARENT_NOTIFY		21
# define CONFIG_NOTIFY			22
# define CONFIG_REQUEST			23
# define GRAVITY_NOTIFY			24
# define RESIZE_REQUEST			25
# define CIRCULATE_NOTIFY		26
# define CIRCULATE_REQUEST		27
# define PROPERTY_NOTIFY		28
# define SELECTION_CLEAR		29
# define SELECTION_REQUEST		30
# define SELECTION_NOTIFY		31
# define COLOR_MAP_NOTIFY		32
# define CLIENT_MESSAGE			33
# define MAPPING_NOTIFY			34
# define GENERIC_EVENT			35
# define LAST_EVENT				36
// MLX SYNC
# define MLX_SYNC_IMAGE_WRITABLE    1
# define MLX_SYNC_WIN_FLUSH_CMD     2
# define MLX_SYNC_WIN_CMD_COMPLETED 3

/*
** X11 EVENTS MASKS:
** # define NO_EVENT_MASK				0L
** # define KEY_PRESS_MASK				(1L<<0)
** # define KEY_RELEASE_MAS				(1L<<1)
** # define BUTTON_PRESS_MASK			(1L<<2)
** # define BUTTON_RELEASE_MASK			(1L<<3)
** # define ENTER_WINDOW_MASK			(1L<<4)
** # define LEAVE_WINDOW_MASK			(1L<<5)
** # define POINTER_MOTION_MASK			(1L<<6)
** # define POINTER_MOTION_HINT_MASK	(1L<<7)
** # define BUTTON1_MOTION_MASK			(1L<<8)
** # define BUTTON2_MOTION_MASK			(1L<<9)
** # define BUTTON3_MOTION_MASK			(1L<<10)
** # define BUTTON4_MOTION_MASK			(1L<<11)
** # define BUTTON5_MOTION_MASK			(1L<<12)
** # define BUTTON_MOTION_MASK			(1L<<13)
** # define KEYMAP_STATE_MASK			(1L<<14)
** # define EXPOSURE_MASK				(1L<<15)
** # define VISIBILITY_CHANGE_MASK		(1L<<16)
** # define STRUCTURE_NOTIFY_MASK		(1L<<17)
** # define RESIZE_REDIRECT_MASK		(1L<<18)
** # define SUBSTRUCTURE_NOTIFY_MASK	(1L<<19)
** # define SUBSTRUCTURE_REDIRECT_MASK	(1L<<20)
** # define FOCUS_CHANGE_MASK			(1L<<21)
** # define PROPERTY_CHANGE_MASK		(1L<<22)
** # define COLORMAP_CHANGE_MASK		(1L<<23)
** # define OWNER_GRAB_BUTTON_MASK		(1L<<24)
*/

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}	t_img;

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_mandelbrot
{
	int		selected;
	double	pr;
	double	pi;
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
}	t_mandelbrot;

typedef struct s_julia
{
	int		selected;
	double	cRe;
	double	cIm;
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;

}	t_julia;

typedef struct s_trees
{
	int		selected;
}	t_trees;

typedef struct s_fractol
{
	t_img			main_img;
	t_xy			screen;
	void			*mlx;
	void			*window;
	int				bonus;
	t_mandelbrot	mdlbr;
	t_julia			julia;
	t_trees			trees;
	double			random;
	double			random_two;
	double			moveX;
	double			moveY;
	double			zoom;
	int				maxIterations;
	int				color;
	int				zoom_in;
	int				zoom_out;
	int				move_down;
	int				move_up;
	int				move_right;
	int				move_left;
	int				more_iter;
	int				less_iter;
}	t_fractol;

// All functions from src, ordered by type and length
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		julia(t_fractol *fractol);
int		mandelbrot(t_fractol *cub);
int		trees(t_fractol *fractol);
int		destroy(t_fractol *fractol);
int		fractals(t_fractol *fractol);
int		keys(int keycode, t_fractol *fractol);
int		create_trgb(int t, int r, int g, int b);
int		my_pixel_get(t_img *data, int x, int y);
int		ft_strcmp(const char *s1, const char *s2);
int		keys_release(int keycode, t_fractol *fractol);
int		mouse_hook(int keycode, int x, int y, t_fractol *fractol);

void	ft_bzero(void *s, size_t n);
void	print_simple_errors(char *str);
void	fractal_keys(t_fractol *fractol);
void	set_color(t_fractol *fractol, int *i);
void	my_pixel_put(t_img *img, int x, int y, int color);

void	bmp_save(t_fractol *fractol);

#endif
