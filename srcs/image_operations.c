/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:08:08 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/18 16:16:27 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_image		*ft_delimage(t_mlx *mlx, t_image *img)
{
	if (img != NULL)
	{
		if (img->ptr != NULL)
			mlx_destroy_image(mlx->init, img->ptr);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

void	image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
//	ft_putendl(ft_itoa(color));
	*(int *)(image->data + (x * image->bitspp + y * image->string)) = color;
//	ft_putendl(ft_itoa(*(int *)(image->data + (x + y * WIN_WIDTH) * image->bitspp)));
}

t_image	*new_image(t_mlx *mlx)
{
	t_image		*img;

	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((img->ptr = mlx_new_image(mlx->init, WIN_WIDTH, WIN_HEIGHT)) == NULL)
		return (ft_delimage(mlx, img));
	img->data = mlx_get_data_addr(img->ptr, &img->bitspp, &img->string,
			&img->endian);
	img->bitspp /= 8;
	return (img);
}
