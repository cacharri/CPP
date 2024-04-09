/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:36:56 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/09 16:52:51 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

struct Data {
    int value;
    Data(int val = 0) : value(val) {}
    Data(const Data& other) : value(other.value) {}
    ~Data() {}
};

class Serializer {
    public:
        // Método estático para serializar un puntero a Data
        static uintptr_t serialize(Data* ptr);

        // Método estático para deserializar un uintptr_t a un puntero a Data
        static Data* deserialize(uintptr_t raw);
};

#endif
