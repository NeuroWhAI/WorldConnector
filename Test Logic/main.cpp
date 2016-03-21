#include "WorldConnector\WCMain.h"

#include "WorldConnector With SFML\Factory.h"




void initializeFactory()
{
	// �������� Ŀ���Ϳ� ����� ���� �ν��Ͻ��� ����� ���丮�� �ʱ�ȭ

	WorldConnector::Factory::initializeInstance<Factory>();
}


void testLogic()
{
	// WorldConnector���� ����ؼ� ������ ����

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
	// ���丮 �ʱ�ȭ
	initializeFactory();


	// ���� �׽�Ʈ
	testLogic();


	return 0;
}

