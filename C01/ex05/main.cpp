/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:14:40 by ialvarez          #+#    #+#             */
/*   Updated: 2023/07/03 18:06:21 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl harl;

	// Prueba de diferentes niveles de queja
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	// Prueba de nivel desconocido
	harl.complain("UNKNOWN");

	return 0;
}
