#include <iostream>

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

	// ������ ũ�� ����
	auto winSize = WorldConnector::Factory::getInstance()->createSize();
	winSize->setSize(1024, 768);

	// ������ ����
	auto window = WorldConnector::Factory::getInstance()->createWindow();
	window->create(*winSize, "Hello, World!");
	window->show();

	// �׷��Ƚ� ����
	auto graphics = WorldConnector::Factory::getInstance()->createGraphics();

	// �簢��1�� ��ġ ����
	auto point1 = WorldConnector::Factory::getInstance()->createPoint();
	point1->setLocation(8, 8);

	// �簢��1�� ũ�� ����
	auto size1 = WorldConnector::Factory::getInstance()->createSize();
	size1->setSize(64, 48);

	// �簢��2�� ��ġ ����
	auto point2 = WorldConnector::Factory::getInstance()->createPoint();
	point2->setLocation(256, 128);

	// �簢��2�� ũ�� ����
	auto size2 = WorldConnector::Factory::getInstance()->createSize();
	size2->setSize(256, 512);

	// �������� ���� ����
	auto backColor = WorldConnector::Factory::getInstance()->createColor();
	backColor->setArgb(255, 0, 0, 100);

	// �簢��1�� �� ����
	auto color1 = WorldConnector::Factory::getInstance()->createColor();
	color1->setArgb(255, 255, 0, 255);

	// �簢��2�� �� ����
	auto color2 = WorldConnector::Factory::getInstance()->createColor();
	color2->setArgb(255, 0, 255, 100);

	// �̺�Ʈ�� ���� �ν��Ͻ� ����
	auto popEvent = WorldConnector::Factory::getInstance()->createEvent();

	// �����찡 �����ִ� ����
	while (window->isRunning())
	{
		// ���� �̺�Ʈ�� ó��
		while (window->pollEvent(popEvent.get()))
		{
			// ���� �̺�Ʈ��� ������ �ݱ�
			if (popEvent->getType() == WorldConnector::Form::Event::Closed)
				window->exit();

			// NOTE: ������ �ӽ� �ڵ�
			if (popEvent->getType() != WorldConnector::Form::Event::Null)
			{
				std::cout << "�̺�Ʈ �߻� : " << popEvent->getType() << std::endl;
			}
		}


		// ���� �ʱ�ȭ �� �׸��� �غ�
		window->clearDrawing(*backColor);
		window->beginDraw();

		// �簢�� �׸��� �غ�
		graphics->beginDrawRectangle(5.0f);

		// �簢��1 �׸���
		graphics->drawRectangle(*point1, *size1, *color1);

		// �簢��2 �׸���
		graphics->drawRectangle(*point2, *size2, *color2);

		// �簢�� �׸��� �Ϸ�
		graphics->endDrawRectangle();

		// �׸��� �Ϸ� �� ǥ��
		window->endDraw();
		window->displayDrawing();
	}
}


int main()
{
	// ���丮 �ʱ�ȭ
	initializeFactory();


	// ���� �׽�Ʈ
	testLogic();


	return 0;
}

