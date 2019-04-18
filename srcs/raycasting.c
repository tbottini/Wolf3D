#include "wolf3d.h"

float		iswall(t_wolf *wolf, t_fvct2 inter)
{
	if (inter.x < wolf->map_size.x && inter.y < wolf->map_size.y
		&& inter.x > -1 && inter.y > -1)
	{
		if (wolf->map[(int)inter.y][(int)inter.x] == '#')
		{
			wolf->map[(int)inter.y][(int)inter.x] = 'X';
			return (sqrt(inter.x * inter.x + inter.y * inter.y));
		}
		return (0);
	}
	return (-1);
}

float		hor_detection(t_wolf *wolf, float angle)
{
	t_fvct2		ratio;
	t_fvct2		inter;
	float		dist;

	ratio.y = (angle < 180) ? 1 : -1;
	ratio.x = ratio.y / tan(angle * PI / 180);
	inter.y = (int)wolf->pos.y + ((angle < 180) ? 1 : 0);
	inter.x = wolf->pos.x + fabs(inter.y - wolf->pos.y) * ratio.x;
	while ((dist = iswall(wolf, inter)) == 0)
	{
		inter.y += ratio.y;
		inter.x += ratio.x;
	}
	return (dist);
}

float		ver_detection(t_wolf *wolf, float angle)
{
	t_fvct2		ratio;
	t_fvct2		inter;
	float		dist;

	ratio.x = (angle < 90 || angle > 270) ? 1 : -1;
	ratio.y = ratio.x / tan((90 - angle) * PI / 180);
	inter.x = (int)wolf->pos.x + ((angle < 90 || angle > 270) ? 1 : 0);
	inter.y = wolf->pos.y + fabs(inter.x - wolf->pos.x) * ratio.y;
	while ((dist = iswall(wolf, inter)) == 0)
	{
		inter.y += ratio.y;
		inter.x += ratio.x;
	}
	return (dist);
}

void		draw_colomn(t_wolf *wolf, float dist, int num)
{
	float	column_size;
	int		i;
	int		iprint;

	i = 0;
	column_size = (wolf->sdl.size.y * 0.8) / dist;
	iprint = num;
	while (i < wolf->sdl.size.y)
	{
		wolf->sdl.screen[iprint] = color_rgb(255, 255, 255);

	}
}


void		raycasting(t_wolf *wolf, int ang)
{
	float	iangle;
	float	start_angle;
	int		i;

	(void)ang;
	i = 0;
	start_angle = wolf->rot + wolf->fov / 2.0;
	iangle = wolf->fov / (float)wolf->sdl.size.x;
}
