/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_prototypes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/22 16:58:41 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_PROTOTYPES_H
# define CUBE_PROTOTYPES_H

# include "cube_structs.h"

/* ------------------------ PROTOTYPES ------------------------ */
/* MAP PARSER */
void		parser(t_prog *game, int ac, char **av);
void		fill_lst(t_prog *game, t_list **aux_lst);
int			parselst(t_prog *game, t_list *aux_lst);
void		printlist(t_list *list);
int			map_build(int data_len, t_prog *game, t_list *aux_lst);
void		build_spaced_layout(t_prog *game, int height, int width);
int			**allocate_all_layout(int height, int width);

/* STRUCT INIT */
void		init_game(t_prog *game);
void		create_image(t_prog *game, int array_position, double size[]);
void		framework_dimensions(t_prog *game);
void		init_map2D(char **map, t_prog *game);
void		minimap_dimensions(t_prog *game);
int			**copy_double_pointer(int **var, int height, int width);
void		print_smap(int **s_map, int height, int width);
/* ------------------------ FPS ------------------------ */
/* FRAMEWORKS */
int			trgb_translate(int red, int blue, int green, int transparency);
int			get_trgb_shadowed(int colour_code);

int			get_opposite(int colour_code);
void		framework_2D(t_prog *game);
void		update_pixel_per_block(t_prog *game);

/* LOOP AND FRAME CONTROL 60FPS */
void		hooks_and_loops(t_prog *game);
void		reset_and_wash_frame(t_prog *game);
void		hk_close(void *game);
void		put_frame2D(t_prog *game);
void		put_frame3D(t_prog *game);
void		hk_keys(mlx_key_data_t key, void *g);

/* CLEAR MEMORY */
void		clean_exit(t_prog *game);
void		ft_shutdown(char *error_msg, t_prog *game);
void		freemat(char **mat);
void		freemat_int(int **mat, int len);
void		ft_mlx_delete_image_safe(int image_position, t_prog *game);

/* ------------------------ RAYCAST ------------------------ */
/* RAY CASTING AND DDA ALGORITHM */
void		main_raycast_calculation(int angle, int ray_offset, t_prog *game);
void		init_ray(t_ray *ray, double origin[], t_vector dir, t_prog *game);
t_vector	raycast(t_data *aux, t_vector dir, double origin[], t_prog *game);
void		clear_raycast(t_prog *game);
/* BEAM */
void		cast_beam(t_beam *beam, t_data *aux, t_prog *game);
double		plane_lenght_and_direction(t_beam *beam, int angle);
/* VECTOR TREATMENT */
void		draw_vector(t_vector vec, double origin[], \
uint32_t colour, t_prog *game);
/* ------------------------ RAYCAST ------------------------ */
/* VECTOR TOOLS */
double		get_module(t_vector vec);
t_vector	get_unit_vector(t_vector vec);
t_vector	rotate_vector(t_vector vec, int angle);
/* VECTOR ARITHMETIC */
t_vector	sum_vec(t_vector lhs, t_vector rhs);
t_vector	sub_vec(t_vector lhs, t_vector rhs);
t_vector	mul_vec(t_vector lhs, double escalar);
t_vector	div_vec(t_vector lhs, double escalar);
/* VECTOR ARITHMETIC ADVANCED */
t_vector	get_perpendicular(t_vector v);
t_vector	invert_sense_vector(t_vector v);
/* ------------------------ DRAWING ------------------------ */
/* GEOMETRY TOOLS */
void		put_vertical(double coordinate_x, \
double limit_y, int colour, t_prog *game);
void		put_horizontal(double coordinate_y, \
double limit_x, int colour, t_prog *game);
void		put_lineH(double start[], double end[], int colour, t_prog *game);
void		put_lineV(double start[], int size, int colour, t_prog *game);
double		degree_to_radian(double degree);
/* DRAWING TOOLS */
double		coor(double y, double size_y);
void		solid_pixel(mlx_image_t *image, \
int coor_x, int coor_y, uint32_t colour);


/* ------------------------ 3D CUBE ------------------------ */
void	draw_first_layer(t_prog *game);
void	draw_3D_walls(t_prog *game);




//descolgada
void		translate_to_screen(double position_map[], \
double position_screen[], int pixel_per_block[], t_prog *game);

/* ------------------------ PLAYER AND MOVEMENT ------------------------ */
/* PLAYER */
void		draw_player_position(mlx_image_t *image, t_prog *game);
void		draw_2d_player(mlx_image_t *image, double pos[], double radio, int colour, t_prog *game);
void		fill_player_pos(t_prog *game, double player_pos[]);
/* MOVEMENT */
void		vison_control(mlx_key_data_t key, t_prog *game);
void		movement_control(mlx_key_data_t key, t_prog *game);
int			wall_coll(t_prog *game, double new_pos[]);
void		filter_final_pos(t_prog *game, double new_pos[], int flag, double prev_pos[]);
/* TOOLS */
void		draw_centered_rectangle(double o_x, double o_y, int base, int height, t_prog *game);

//To remove from here before evaluation
void		ft_leaks(void);
void		log_vector(t_vector v);
void		log_coor(double array[]);
void		log_d(double d);
void		log_beam(t_beam *beam);
void		print_map(char **map, t_prog *game, int **s_map);
void		log_coor_int(int i[]);
void		coor_identifier(mlx_image_t *image, t_prog *game, double coor_x, double coor_y, double window_size);

#endif