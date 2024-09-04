/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:50:03 by ialvarez          #+#    #+#             */
/*   Updated: 2024/05/29 19:41:22 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base * generate(void) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }
    int randNum = rand() % 3;
    switch (randNum) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    identify(&p);
}

int main() {

    Base* obj = generate();

    identify(obj);

    identify(*obj);

    delete obj;

    return 0;
}

