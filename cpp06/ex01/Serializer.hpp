#pragma once

#include <cstdint>
#include <sys/types.h>
#include "data.hpp"

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
