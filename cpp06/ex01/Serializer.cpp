#include "Serializer.hpp"
#include "data.hpp"
#include <cstdint>

// --- Functions --- //
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

// --- Constructor --- //
Serializer::Serializer() {}

Serializer::Serializer(Serializer &to_copy)
{
	(void)to_copy;
}

// --- Destructor --- //
Serializer::~Serializer() {};

// --- Operator --- //
Serializer &Serializer::operator=(Serializer &to_copy)
{
	(void)to_copy;
	return (*this);
}
