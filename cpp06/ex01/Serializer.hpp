#pragma once

#include <sys/types.h>
#include "data.hpp"

// Typedef ici car on code en cpp98 sur UBUNTU donc celon la meteo il est dispo ou pas
#ifndef UINTPTR_MAX
typedef unsigned long uintptr_t;
#endif

class Serializer
{
	private:
		Serializer &operator=(Serializer &to_copy);

		Serializer();
		Serializer(Serializer &to_copy);
		~Serializer();

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};
