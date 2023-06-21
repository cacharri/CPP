/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:06:40 by ialvarez          #+#    #+#             */
/*   Updated: 2023/06/21 19:07:36 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    sartPos = 0;
    size_t foundPos;
    while ((foundPos = str.find(from, startPos)) != std::string::npos) {
        str = str.substr(0, foundPos) + to + str.substr(foundPos + from.length());
        startPos = foundPos + to.length();
    }
}
