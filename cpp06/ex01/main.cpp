#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data*		before = new Data;
	*before = (Data){"Philippe", 42, "42pouet@realmail.coc"};
	std::cout << "Before serialization:" << std::endl;
	std::cout << "Data : " << before << " | Name : " << before->name << " | Age : " << before->age << " | Mail : " << before->mail << std::endl << std::endl;

	uintptr_t	temp = Serializer::serialize(before);
	std::cout << "Serialized data : " << temp << std::endl;
	std::cout << "in hexa : " << std::hex << temp << std::endl << std::endl << std::dec;

	Data*		after = Serializer::deserialize(temp);
	std::cout << "After deserialization:" << std::endl;
	std::cout << "Data : " << after << " | Name : " << after->name << " | Age : " << after->age << " | Mail : " << after->mail << std::endl;

	
	delete before;
	return (0);
}