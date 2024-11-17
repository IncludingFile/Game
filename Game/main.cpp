#include <SFML/Graphics.hpp>
#include <thread>
#include <windows.h>
#include <time.h>
#include <chrono>

constexpr auto MYFONT = "./Inkfree.ttf"; // �滻Ϊ��������ļ�·��
constexpr auto START_TIME = 3;
constexpr auto HJJ_PHOTO = "./photo/HJJ.jpg"; // �滻Ϊ�����Ϸ��ɫͼƬ·��

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(1920, 1080), L"��ɱ�Ƽο�",Style::Fullscreen);
    Font font;

    if (!font.loadFromFile(MYFONT)) {
        return -1;
    }
    Texture HJJ_texture;
    
    // ������Ϸ��Դ
   
        HJJ_texture.loadFromFile(HJJ_PHOTO);
        
        Text text;
        text.setFont(font);
        text.setString(L"Welcome to the game LSJ created!");
        text.setCharacterSize(50);
        text.setFillColor(Color::White);
        text.setPosition(1920 / 2 - text.getLocalBounds().width / 2, 1080 / 2 - text.getLocalBounds().height / 2);
        Event event;
        // ��ʾ��ӭ��Ϣ
    auto start_time = chrono::system_clock::now();
    auto end_time = chrono::system_clock::now();
    while (window.isOpen()&& chrono::duration_cast<chrono::seconds>(end_time - start_time).count() < START_TIME) {
        
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                window.close();
            }
        }
        
        window.clear();
        window.draw(text);
        window.display();
        end_time = chrono::system_clock::now();
    }
    window.clear();
    // ��ʽ��ʼ��Ϸ
    
    // ������ϷԪ��
        Sprite HJJ(HJJ_texture);
        text.setString(L"He is our target!We must kill him!");
        text.setPosition(1920 / 2 - text.getLocalBounds().width / 2, 1000);
        HJJ.setPosition(1920 / 2 - HJJ.getTextureRect().width / 2, 0);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                window.close();
            }
        }
        // ������Ϸ�߼�
        window.clear();
        window.draw(HJJ);
        window.draw(text);
        // ���´���
        
        window.display();
    }

    return 0;
}