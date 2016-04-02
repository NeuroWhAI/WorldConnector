#include "WorldConnector\WCMain.h"

#include "WorldConnector With SFML\Factory.h"




using WorldConnector::Form::Keyboard;
using WorldConnector::Form::Touch;
using WorldConnector::Drawing::FontStyles;
using WorldConnector::Form::Event;
using WorldConnector::Form::Keys;


inline WorldConnector::Factory* getFactory()
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

	// 사각형2 생성
	auto rect2 = getFactory()->createRectangle();
	rect2->setRectangle(512, 128, 256, 512);

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
	font->setStyle(FontStyles::Underline);
	font->addStyle(FontStyles::Bold);

	// 이벤트를 받을 인스턴스 생성
	auto popEvent = getFactory()->createEvent();

	// 윈도우가 열려있는 동안
	while (window->isRunning())
	{
		// 받은 이벤트를 처리
		while (window->pollEvent(popEvent.get()))
		{
			// 종료 이벤트라면 윈도우 닫기
			if (popEvent->getType() == Event::Closed)
				window->exit();
		}


		// 키보드 상태 갱신
		Keyboard::getInstance()->update();

		// 키보드 입력 처리
		if (Keyboard::getInstance()->isKeyPressed(Keys::Left))
		{
			// 각 변화
			angle -= 0.8f;
			while (angle < 0.0f) angle += 360.0f;
		}
		else if (Keyboard::getInstance()->isKeyPressed(Keys::Right))
		{
			// 각 변화
			angle += 0.8f;
			while (angle >= 360.0f) angle -= 360.0f;
		}

		if (Keyboard::getInstance()->isKeyPressed(Keys::W))
		{
			// 이동
			point1->moveY(-1);
		}
		else if (Keyboard::getInstance()->isKeyPressed(Keys::S))
		{
			// 이동
			point1->moveY(+1);
		}

		if (Keyboard::getInstance()->isKeyPressed(Keys::A))
		{
			// 이동
			point1->moveX(-1);
		}
		else if (Keyboard::getInstance()->isKeyPressed(Keys::D))
		{
			// 이동
			point1->moveX(+1);
		}


		// 마우스 상태 갱신
		Touch::getInstance()->update();

		// 마우스 입력 처리
		if (Touch::getInstance()->isDown())
		{
			auto cursor = Touch::getInstance()->getPosition();
			rect2->setLocation(cursor->getX(), cursor->getY());
		}

		if (Touch::getInstance()->isLongPressed())
		{
			point1 = Touch::getInstance()->getPosition();
		}


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
		graphics->fillRectangle(*rect2, *color2);

		// 사각형 그리기 완료
		graphics->endFillRectangle();


		// 타원 그리기 준비
		graphics->beginDrawEllipse(8.0f);

		// 타원 그리기
		graphics->drawEllipse(rect2->getX(), rect2->getY(),
			64, 48, *color2);

		// 타원 그리기 완료
		graphics->endDrawEllipse();


		// 타원 채우기 준비
		graphics->beginFillEllipse();

		// 타원 채우기
		graphics->fillEllipse(rect2->getX(), rect2->getY(),
			64, 48, *color1);

		// 타원 채우기 완료
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

