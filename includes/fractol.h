/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:48:39 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/31 14:14:33 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

// Identificators for the map
# define MAP_IDENTIFICATORS " 012NSEW"

/*
** ' ' -> Espacio vacío
** '0' -> Suelo/Techo
** '1' -> Muros
** '2' -> Sprites
** '3' -> Objetos puntuación
** '4' -> Teleport
** NSEW-> Posicion y orientación jugador
*/

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

typedef struct s_sprite
{
	double	x;
	double	y;
	int		texture;
	double	dist;
}	t_sprite;

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

typedef struct s_rc_sprites
{
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double	transformy;
	int		spr_screenx;
	int		spr_height;
	int		drawstarty;
	int		drawendy;
	int		spriteWidth;
	int		drawstartx;
	int		drawendx;
	int		stripe;
	int		texx;
	int		texy;
}	t_rc_sprites;

typedef struct s_data {
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltaDistY;
	double	perpwalldist;
	double	wallx;
	double	step;
	double	texpos;
	double	*zbuffer;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		drawstart;
	int		drawend;
	int		color;
	int		lineheight;
	int		texnum;
	int		texx;
	int		texy;
}	t_data;

typedef struct s_raycast {
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}	t_raycast;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}	t_img;

typedef struct s_mlx_txt
{
	t_img		img[5];
	t_img		main_img;
	int			num_sprites;
	int			width[5];
	int			height[5];
	t_list		*sprite_list;
}	t_mlx_txt;

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

typedef struct s_map
{
	t_list	*map_list;
	t_xy	player_pos;
	char	**map_matrix;
	char	player_o;
	int		matrix_mall;
	int		matrix_act;
	int		map_lines;
	int		max_len;
	int		has_content;
	int		map_ko;
}	t_map;

typedef struct s_map_details
{
	char	*no_txt;
	int		no_fd;
	char	*so_txt;
	int		so_fd;
	char	*we_txt;
	int		we_fd;
	char	*ea_txt;
	int		ea_fd;
	char	*s_txt;
	int		s_fd;
	t_rgb	ceiling;
	t_rgb	floor;
}	t_map_details;

/*
** MAIN STRUCT
**
** fd -> fd of the .cub file
** save_first	-> option to start cub3D or take a screenshot as .bmp
** map			-> struct containing the info of the map
** map_d		-> struct containing the details of the map
** elems		-> int where we store the data already added(Resolution, etc...)
** screen		-> struct containing withd/height of the screen
** actual_line	-> a counter used to display error messages
** is_map		-> an int used to check if the reading has ended
** end_map		-> an int to end the reading of the map
** mlx			-> pointer to initialize mlx
** window		-> pointer to the window created with mlx
** txtrs		-> every single texture stored and its info
** raycast		-> all the info needed for the algorythm
** mov			-> everything move related
*/

// Info for the map
# define R	0x001 // 1		00000001
# define NO	0x002 // 2		00000010
# define SO	0x004 // 4		00000100
# define EA	0x008 // 8		00001000
# define WE	0x010 // 16		00010000
# define S	0x020 // 32		00100000
# define F	0x040 // 64		01000000
# define C	0x080 // 128	10000000

typedef struct s_fractol
{
	int				fd;
	int				save_first;
	t_map			map;
	t_map_details	map_d;
	int				elems;
	t_xy			screen;
	int				actual_line;
	int				is_map;
	int				end_map;
	void			*mlx;
	void			*window;
	t_mlx_txt		txtrs;
	t_raycast		raycast;
	t_mov			mov;
	t_data			data;
	t_rc_sprites	rc_spr;
}	t_fractol;

// All functions from src, ordered by type and length
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
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
