#include "Serializer.hpp"
#include "data.hpp"
#include <cstdint>
#include <iostream>

int main(void)
{
	Data		*ori = new	Data;
	Data		*nori;
	uintptr_t	ans;

	ori->name = "test";
	ori->id = 12;

	ans = Serializer::serialize(ori);
	std::cout << ans  << std::endl;

	nori = Serializer::deserialize(ans);
	std::cout << nori->name << std::endl;
	std::cout << nori->id << std::endl;

	if (nori->name == ori->name && nori->id == ori->id && nori == ori)
		std::cout << "success" << std::endl;
	else
		std::cout << "failure" << std::endl;

	delete ori;
	return (0);
}
