#include "WorldConnector\WCMain.h"

#include "WorldConnector With SFML\Factory.h"




void initializeFactory()
{
	// 로직에서 커넥터에 연결될 실제 인스턴스를 만드는 팩토리를 초기화

	WorldConnector::Factory::initializeInstance<Factory>();
}


void testLogic()
{
	// WorldConnector만을 사용해서 로직을 구성

	auto graphics = WorldConnector::Factory::getInstance()->createGraphics();

	auto size1 = WorldConnector::Factory::getInstance()->createSize();
	size1->setHeight(123);

	auto color1 = WorldConnector::Factory::getInstance()->createColor();
	color1->setArgb(255, 255, 0, 255);

	graphics->beginDrawRectangle(3.0f);
	graphics->drawRectangle(8, 8, 64, 48, *color1);
	graphics->endDrawRectangle();
}


int main()
{
	// 팩토리 초기화
	initializeFactory();


	// 로직 테스트
	testLogic();


	return 0;
}

