#include <iostream>

#include "WorldConnector\WCMain.h"

#include "WorldConnector With SFML\Factory.h"




WorldConnector::Factory* getFactory()
{
	return WorldConnector::Factory::getInstance();
}


void initializeFactory()
{
	// 로직에서 커넥터에 연결될 실제 인스턴스를 만드는 팩토리를 초기화

	WorldConnector::Factory::initializeInstance<Factory>();
}


void testLogic()
{
	// WorldConnector만을 사용해서 로직을 구성

	// 사각형1의 각도
	float angle = 0.0f;

	// 윈도우 크기 생성
	auto winSize = getFactory()->createSize();
	winSize->setSize(1024, 768);

	// 윈도우 생성
	auto window = getFactory()->createWindow();
	window->create(*winSize, "Hello, World!");
	window->show();

	// 그래픽스 생성
	auto graphics = getFactory()->createGraphics();

	// 사각형1의 위치 생성
	auto point1 = getFactory()->createPoint();
	point1->setLocation(200, 150);

	// 사각형1의 크기 생성
	auto size1 = getFactory()->createSize();
	size1->setSize(64, 48);

	// 사각형2의 위치 생성
	auto point2 = getFactory()->createPoint();
	point2->setLocation(512, 128);

	// 사각형2의 크기 생성
	auto size2 = getFactory()->createSize();
	size2->setSize(256, 512);

	// 윈도우의 배경색 생성
	auto backColor = getFactory()->createColor();
	backColor->setArgb(255, 0, 0, 100);

	// 사각형1의 색 생성
	auto color1 = getFactory()->createColor();
	color1->setArgb(255, 255, 0, 255);

	// 사각형2의 색 생성
	auto color2 = getFactory()->createColor();
	color2->setArgb(255, 0, 255, 100);

	// 글자 폰트 생성
	auto font = getFactory()->createFont();
	font->setName("잇걸체.ttf");
	font->setHeight(64);
	font->setStyle(WorldConnector::Drawing::FontStyles::Underline);
	font->addStyle(WorldConnector::Drawing::FontStyles::Bold);

	// 이벤트를 받을 인스턴스 생성
	auto popEvent = getFactory()->createEvent();

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


		// 각 변화
		angle += 0.4f;
		while (angle >= 360.0f) angle -= 360.0f;


		// 배경색 초기화 및 그리기 준비
		window->clearDrawing(*backColor);
		window->beginDraw();


		// 변환행렬 설정
		graphics->translate(point1->getX(), point1->getY());
		graphics->rotate(angle);

		// 사각형 그리기 준비
		graphics->beginDrawRectangle(5.0f);

		// 사각형1 그리기
		graphics->drawRectangle(-size1->getWidth() / 2,
			-size1->getHeight() / 2,
			size1->getWidth(), size1->getHeight(),
			*color1);

		// 사각형 그리기 완료
		graphics->endDrawRectangle();

		// 글자 그리기 준비
		graphics->beginDrawString(*font, *color2);

		// 글자 그리기
		graphics->drawString(L"안녕", -18, -18);

		// 글자 그리기 완료
		graphics->endDrawString();

		// 변환 초기화
		graphics->resetTransform();


		// 사각형 그리기 준비
		graphics->beginFillRectangle();

		// 사각형2 그리기
		graphics->fillRectangle(*point2, *size2, *color2);

		// 사각형 그리기 완료
		graphics->endFillRectangle();


		// 타원 그리기 준비
		graphics->beginDrawEllipse(8.0f);

		// 타원 그리기
		graphics->drawEllipse(point2->getX(), point2->getY(),
			64, 48, *color2);

		// 타원 그리기 완료
		graphics->endDrawEllipse();


		// 타원 그리기 준비
		graphics->beginFillEllipse();

		// 타원 그리기
		graphics->fillEllipse(point2->getX(), point2->getY(),
			64, 48, *color1);

		// 타원 그리기 완료
		graphics->endFillEllipse();


		// 선 그리기 준비
		graphics->beginDrawLine(1.0f);

		// 선 그리기
		graphics->drawLine(16, 512, 32, 700, *color1);
		graphics->drawLine(32, 700, 480, 720, *color2);

		// 선 그리기 완료
		graphics->endDrawLine();


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

