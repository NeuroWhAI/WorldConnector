#include "WorldConnector\WCMain.h"

#include "WorldConnector With SFML\Factory.h"

#include <iostream>




void initializeFactory()
{
	// �������� Ŀ���Ϳ� ����� ���� �ν��Ͻ��� ����� ���丮�� �ʱ�ȭ

	WorldConnector::Factory::initializeInstance<Factory>();
}


void testLogic()
{
	// WorldConnector���� ����ؼ� ������ ����

	auto size1 = WorldConnector::Factory::getInstance()->createSize();
	size1->setHeight(123);

	std::cout << size1->getHeight() << std::endl;
}


int main()
{
	// ���丮 �ʱ�ȭ
	initializeFactory();


	// ���� �׽�Ʈ
	testLogic();


	return 0;
}

