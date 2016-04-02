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
	// �������� Ŀ���Ϳ� ����� ���� �ν��Ͻ��� ����� ���丮�� �ʱ�ȭ

	WorldConnector::Factory::initializeInstance<Factory>();
}


void testLogic()
{
	// WorldConnector���� ����ؼ� ������ ����

	// �簢��1�� ����
	float angle = 0.0f;

	// ������ ũ�� ����
	auto winSize = getFactory()->createSize();
	winSize->setSize(1024, 768);

	// ������ ����
	auto window = getFactory()->createWindow();
	window->create(*winSize, "Hello, World!");
	window->show();

	// �׷��Ƚ� ����
	auto graphics = getFactory()->createGraphics();

	// �簢��1�� ��ġ ����
	auto point1 = getFactory()->createPoint();
	point1->setLocation(200, 150);

	// �簢��1�� ũ�� ����
	auto size1 = getFactory()->createSize();
	size1->setSize(64, 48);

	// �簢��2 ����
	auto rect2 = getFactory()->createRectangle();
	rect2->setRectangle(512, 128, 256, 512);

	// �������� ���� ����
	auto backColor = getFactory()->createColor();
	backColor->setArgb(255, 0, 0, 100);

	// �簢��1�� �� ����
	auto color1 = getFactory()->createColor();
	color1->setArgb(255, 255, 0, 255);

	// �簢��2�� �� ����
	auto color2 = getFactory()->createColor();
	color2->setArgb(255, 0, 255, 100);

	// ���� ��Ʈ ����
	auto font = getFactory()->createFont();
	font->setName("�հ�ü.ttf");
	font->setHeight(64);
	font->setStyle(FontStyles::Underline);
	font->addStyle(FontStyles::Bold);

	// �̺�Ʈ�� ���� �ν��Ͻ� ����
	auto popEvent = getFactory()->createEvent();

	// �����찡 �����ִ� ����
	while (window->isRunning())
	{
		// ���� �̺�Ʈ�� ó��
		while (window->pollEvent(popEvent.get()))
		{
			// ���� �̺�Ʈ��� ������ �ݱ�
			if (popEvent->getType() == Event::Closed)
				window->exit();
		}


		// Ű���� ���� ����
		Keyboard::getInstance()->update();

		// Ű���� �Է� ó��
		if (Keyboard::getInstance()->isKeyPressed(Keys::Left))
		{
			// �� ��ȭ
			angle -= 0.8f;
			while (angle < 0.0f) angle += 360.0f;
		}
		else if (Keyboard::getInstance()->isKeyPressed(Keys::Right))
		{
			// �� ��ȭ
			angle += 0.8f;
			while (angle >= 360.0f) angle -= 360.0f;
		}

		if (Keyboard::getInstance()->isKeyPressed(Keys::W))
		{
			// �̵�
			point1->moveY(-1);
		}
		else if (Keyboard::getInstance()->isKeyPressed(Keys::S))
		{
			// �̵�
			point1->moveY(+1);
		}

		if (Keyboard::getInstance()->isKeyPressed(Keys::A))
		{
			// �̵�
			point1->moveX(-1);
		}
		else if (Keyboard::getInstance()->isKeyPressed(Keys::D))
		{
			// �̵�
			point1->moveX(+1);
		}


		// ���콺 ���� ����
		Touch::getInstance()->update();

		// ���콺 �Է� ó��
		if (Touch::getInstance()->isDown())
		{
			auto cursor = Touch::getInstance()->getPosition();
			rect2->setLocation(cursor->getX(), cursor->getY());
		}

		if (Touch::getInstance()->isLongPressed())
		{
			point1 = Touch::getInstance()->getPosition();
		}


		// ���� �ʱ�ȭ �� �׸��� �غ�
		window->clearDrawing(*backColor);
		window->beginDraw();


		// ��ȯ��� ����
		graphics->translate(point1->getX(), point1->getY());
		graphics->rotate(angle);

		// �簢�� �׸��� �غ�
		graphics->beginDrawRectangle(5.0f);

		// �簢��1 �׸���
		graphics->drawRectangle(-size1->getWidth() / 2,
			-size1->getHeight() / 2,
			size1->getWidth(), size1->getHeight(),
			*color1);

		// �簢�� �׸��� �Ϸ�
		graphics->endDrawRectangle();

		// ���� �׸��� �غ�
		graphics->beginDrawString(*font, *color2);

		// ���� �׸���
		graphics->drawString(L"�ȳ�", -18, -18);

		// ���� �׸��� �Ϸ�
		graphics->endDrawString();

		// ��ȯ �ʱ�ȭ
		graphics->resetTransform();


		// �簢�� �׸��� �غ�
		graphics->beginFillRectangle();

		// �簢��2 �׸���
		graphics->fillRectangle(*rect2, *color2);

		// �簢�� �׸��� �Ϸ�
		graphics->endFillRectangle();


		// Ÿ�� �׸��� �غ�
		graphics->beginDrawEllipse(8.0f);

		// Ÿ�� �׸���
		graphics->drawEllipse(rect2->getX(), rect2->getY(),
			64, 48, *color2);

		// Ÿ�� �׸��� �Ϸ�
		graphics->endDrawEllipse();


		// Ÿ�� ä��� �غ�
		graphics->beginFillEllipse();

		// Ÿ�� ä���
		graphics->fillEllipse(rect2->getX(), rect2->getY(),
			64, 48, *color1);

		// Ÿ�� ä��� �Ϸ�
		graphics->endFillEllipse();


		// �� �׸��� �غ�
		graphics->beginDrawLine(1.0f);

		// �� �׸���
		graphics->drawLine(16, 512, 32, 700, *color1);
		graphics->drawLine(32, 700, 480, 720, *color2);

		// �� �׸��� �Ϸ�
		graphics->endDrawLine();


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

