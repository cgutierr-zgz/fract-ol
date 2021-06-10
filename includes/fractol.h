/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:48:39 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/10 13:48:31 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

// Buttons
# define K_ESC		53
# define K_W		13
# define K_A		0
# define K_S		1
# define K_D		2
# define K_LEFT		123
# define K_RIGHT	124
# define L_SHIFT	257
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

typedef struct s_mov
{
	int				left;
	int				right;
	int				up;
	int				down;
	int				rotate_left;
	int				rotate_right;
	double			mov_s;
	double			rot_s;
	int				x_mouse;
	int				y_mouse;
	unsigned int	delay;
}	t_mov;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}	t_img;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
	int		trgb;
}	t_rgb;

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_fractol
{
	t_img			main_img;
	int				order;
	int				julia;
	int				mandelbrot;
	t_xy			screen;
	void			*mlx;
	void			*window;
	t_mov			mov;
}	t_fractol;

// All functions from src, ordered by type and length
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		mandelbrot(t_fractol *cub);
int julia(t_fractol *fractol);
int		raycast(t_fractol *fractol);
int		destroy(t_fractol *fractol);
int		open_texture(char *texture);
int		keys(int keycode, t_fractol *fractol);
int		set_bit(int value, int index);
int		reset_bit(int value, int index);
int		is_bit_set(int value, int bitindex);
int		key_release(int keycode, t_fractol *fractol);
int		create_trgb(int t, int r, int g, int b);
int		my_pixel_get(t_img *data, int x, int y);

void	key_w(t_fractol *fractol);
void	key_a(t_fractol *fractol);
void	key_s(t_fractol *fractol);
void	key_d(t_fractol *fractol);
void	sprites(t_fractol *fractol);
void	bmp_save(t_fractol *fractol);
void	key_left(t_fractol *fractol);
void	key_right(t_fractol *fractol);
void	cub_tresd(t_fractol *fractol);
void	close_fds(t_fractol *fractol);
void	print_list(t_list *start);
void	bubble_sort(t_list *start);
void	start_graphics(t_fractol *fractol);
void	check_textures(t_fractol *fractol);
void	check_matrix_ok(t_fractol *fractol);
void	free_content_fractol(t_fractol *fractol);
void	check_map_details(t_fractol *fractol);
void	wallcasting(t_fractol *fractol, int x);
void	print_simple_errors(char *str);
void	print_specificators(t_fractol *fractol);
void	parse_map(char *line, t_fractol *fractol);
void	rotate_x(t_fractol *fractol, double force);
void	print_errors(t_fractol *fractol, char *str);
void	free_content_map_matrix(t_fractol *fractol);
void	clear_matrix_content(void *content);
void	player_orientation_error(t_fractol *fractol);
void	fill_sprites(t_fractol *fractol, void *content);
void	draw_walls(t_fractol *fractol, int *draw, int x);
void	fill_map_matrix(t_fractol *fractol, void *content);
void	add_spaces_c_f(int n_words, char **content);
void	parse_specificators(t_fractol *fractol, char *line);
void	aux(t_fractol *fractol, char **content, int n_words);
void	calcular_distancia(t_fractol *fractol, void *content);
void	free_content_array(char **content, int n_words);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	handle_map_r(t_fractol *fractol, char **content, int n_words);
void	handle_map_s(t_fractol *fractol, char **content, int n_words);
void	handle_map_f(t_fractol *fractol, char **content, int n_words);
void	handle_map_c(t_fractol *fractol, char **content, int n_words);
void	handle_map_no(t_fractol *fractol, char **content, int n_words);
void	handle_map_so(t_fractol *fractol, char **content, int n_words);
void	handle_map_we(t_fractol *fractol, char **content, int n_words);
void	handle_map_ea(t_fractol *fractol, char **content, int n_words);
void	handle_map_c_aux1(t_fractol *fractol, char **content, int n_words);
void	handle_map_f_aux1(t_fractol *fractol, char **content, int n_words);
void	check_commas(char **content, int n_words, t_fractol *fractol, int x);
void	handle_content_else(t_fractol *fractol, int n_words, char **content);
void	iter_cub_list(t_fractol *fractol, t_list *lst, void (*f)(t_fractol *, void *));
void	iter_sprite_list(t_fractol *fractol, t_list *lst, void (*f)(t_fractol *, void *));

#endif
