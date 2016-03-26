#include <iostream>

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

	// 윈도우 크기 생성
	auto winSize = WorldConnector::Factory::getInstance()->createSize();
	winSize->setSize(1024, 768);

	// 윈도우 생성
	auto window = WorldConnector::Factory::getInstance()->createWindow();
	window->create(*winSize, "Hello, World!");
	window->show();

	// 그래픽스 생성
	auto graphics = WorldConnector::Factory::getInstance()->createGraphics();

	// 사각형1의 위치 생성
	auto point1 = WorldConnector::Factory::getInstance()->createPoint();
	point1->setLocation(8, 8);

	// 사각형1의 크기 생성
	auto size1 = WorldConnector::Factory::getInstance()->createSize();
	size1->setSize(64, 48);

	// 사각형2의 위치 생성
	auto point2 = WorldConnector::Factory::getInstance()->createPoint();
	point2->setLocation(256, 128);

	// 사각형2의 크기 생성
	auto size2 = WorldConnector::Factory::getInstance()->createSize();
	size2->setSize(256, 512);

	// 윈도우의 배경색 생성
	auto backColor = WorldConnector::Factory::getInstance()->createColor();
	backColor->setArgb(255, 0, 0, 100);

	// 사각형1의 색 생성
	auto color1 = WorldConnector::Factory::getInstance()->createColor();
	color1->setArgb(255, 255, 0, 255);

	// 사각형2의 색 생성
	auto color2 = WorldConnector::Factory::getInstance()->createColor();
	color2->setArgb(255, 0, 255, 100);

	// 이벤트를 받을 인스턴스 생성
	auto popEvent = WorldConnector::Factory::getInstance()->createEvent();

	// 윈도우가 열려있는 동안
	while (window->isRunning())
	{
		// 받은 이벤트를 처리
		while (window->pollEvent(popEvent.get()))
		{
			// 종료 이벤트라면 윈도우 닫기
			if (popEvent->getType() == WorldConnector::Form::Event::Closed)
				window->exit();

			// NOTE: 디버깅용 임시 코드
			if (popEvent->getType() != WorldConnector::Form::Event::Null)
			{
				std::cout << "이벤트 발생 : " << popEvent->getType() << std::endl;
			}
		}


		// 배경색 초기화 및 그리기 준비
		window->clearDrawing(*backColor);
		window->beginDraw();

		// 사각형 그리기 준비
		graphics->beginDrawRectangle(5.0f);

		// 사각형1 그리기
		graphics->drawRectangle(*point1, *size1, *color1);

		// 사각형2 그리기
		graphics->drawRectangle(*point2, *size2, *color2);

		// 사각형 그리기 완료
		graphics->endDrawRectangle();

		// 그리기 완료 및 표시
		window->endDraw();
		window->displayDrawing();
	}
}


int main()
{
	// 팩토리 초기화
	initializeFactory();


	// 로직 테스트
	testLogic();


	return 0;
}

