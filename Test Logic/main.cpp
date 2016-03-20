#include "WorldConnector\WCMain.h"

#include "WorldConnector With SFML\Factory.h"

#include <iostream>




void initializeFactory()
{
	// 로직에서 커넥터에 연결될 실제 인스턴스를 만드는 팩토리를 초기화

	WorldConnector::Factory::initializeInstance<Factory>();
}


void testLogic()
{
	// WorldConnector만을 사용해서 로직을 구성

	auto size1 = WorldConnector::Factory::getInstance()->createSize();
	size1->setHeight(123);

	std::cout << size1->getHeight() << std::endl;
}


int main()
{
	// 팩토리 초기화
	initializeFactory();


	// 로직 테스트
	testLogic();


	return 0;
}

