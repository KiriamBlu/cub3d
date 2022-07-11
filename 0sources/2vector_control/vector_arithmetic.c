/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 05:44:20 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/11 05:45:01 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Vecotrial sum. */
t_vector	sum_vec(t_vector lhs, t_vector rhs)
{
	t_vector	result;

	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	return (result);
}

/** PURPOSE : Vecotrial substraction. */
t_vector	sub_vec(t_vector lhs, t_vector rhs)
{
	t_vector	result;

	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	return (result);
}

/** PURPOSE : Ecalar multiplication of a vector. */
t_vector	mul_vec(t_vector lhs, float escalar)
{
	t_vector	result;

	result.x = lhs.x * escalar;
	result.y = lhs.y * escalar;
	return (result);
}

/** PURPOSE : Escaalar divison of a vector. */
t_vector	div_vec(t_vector lhs, float escalar)
{
	t_vector	result;

	result.x = lhs.x / escalar;
	result.y = lhs.y / escalar;
	return (result);
}