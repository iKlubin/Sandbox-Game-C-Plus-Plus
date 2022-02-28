#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string>

#define W 50
#define H 50
#define SIZE 256

using namespace std;

class Player
{
private:
    int x;
    int y;
public:
    Player(int xP, int yP);
    int getX();
    int getY();
    void setX(int xP);
    void setY(int yP);
};

class Object
{
private:
    int x;
    int y;
public:
    Object() = default;
    Object(int xP, int yP);
    int getX();
    int getY();
    void del();
    void setX(int xP);
    void setY(int yP);
};

class Enemy
{
private:
    int x;
    int y;
public:
    Enemy() = default;
    Enemy(int xP, int yP);
    int getX();
    int getY();
    void del();
    void setX(int xP);
    void setY(int yP);
};

Object obj[SIZE];

Player p(W / 2, H / 2);

void print(wchar_t screen[], int n, wchar_t map[50][50], HANDLE hConsole);

int main()
{

    wchar_t* screen = new wchar_t[W * H];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;
    srand(time(NULL));

    wstring Map;
    Map += L"██████████████████████████████████████████████████";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"█                                                █";
    Map += L"██████████████████████████████████████████████████";

    int s = 0;
    wchar_t map[50][50];
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            map[i][j] = Map[s];
            s++;
        }
    }

    int tick = 0;
    int n = 0;
    int x;
    int y;

    for (int n = 0; n < SIZE; n++)
    {
        x = (rand() % (W - 2)) + 1;
        y = (rand() % (H - 2)) + 1;
        obj[n] = { x, y };
        n++;
    }
    n = 128;
    while (!GetAsyncKeyState((unsigned short)' '))
    {
        if (tick % 10 == 0 and n >= 0)
        {
            obj[n].del();
            n--;
        }
        if (GetAsyncKeyState((unsigned short)'W'))
        {
            p.setY(-1);
            if (p.getY() == 0)
            {
                p.setY(1);
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (p.getY() == obj[i].getY() and p.getX() == obj[i].getX() and obj[i].getY() - 1 != 0)
                    {
                        obj[i].setY(-1);
                        for (int j = 0; j < n; j++)
                        {
                            if (obj[i].getY() == obj[j].getY() and obj[i].getX() == obj[j].getX() and obj[j].getY() - 1 != 0 and i != j)
                            {
                                obj[j].setY(-1);
                                for (int k = 0; k < n; k++)
                                {
                                    if (obj[j].getY() == obj[k].getY() and obj[j].getX() == obj[k].getX() and obj[k].getY() - 1 != 0 and j != k)
                                    {
                                        obj[k].setY(-1);
                                        for (int l = 0; l < n; l++)
                                        {
                                            if (obj[k].getY() == obj[l].getY() and obj[k].getX() == obj[l].getX() and obj[k].getY() - 1 != 0 and k != l)
                                            {
                                                obj[l].setY(-1);
                                                for (int m = 0; m < n; m++)
                                                {
                                                    if (obj[l].getY() == obj[m].getY() and obj[l].getX() == obj[m].getX() and l != m)
                                                    {
                                                        obj[m].setY(-1);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (GetAsyncKeyState((unsigned short)'A'))
        {
            p.setX(-1);
            if (p.getX() == 0)
            {
                p.setX(1);
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (p.getY() == obj[i].getY() and p.getX() == obj[i].getX() and obj[i].getX() - 1 != 0)
                    {
                        obj[i].setX(-1);
                        for (int j = 0; j < n; j++)
                        {
                            if (obj[i].getY() == obj[j].getY() and obj[i].getX() == obj[j].getX() and obj[j].getX() - 1 != 0 and i != j)
                            {
                                obj[j].setX(-1);
                                for (int k = 0; k < n; k++)
                                {
                                    if (obj[j].getY() == obj[k].getY() and obj[j].getX() == obj[k].getX() and obj[k].getX() - 1 != 0 and j != k)
                                    {
                                        obj[k].setX(-1);
                                        for (int l = 0; l < n; l++)
                                        {
                                            if (obj[k].getY() == obj[l].getY() and obj[k].getX() == obj[l].getX() and obj[k].getX() - 1 != 0 and k != l)
                                            {
                                                obj[l].setX(-1);
                                                for (int m = 0; m < n; m++)
                                                {
                                                    if (obj[l].getY() == obj[m].getY() and obj[l].getX() == obj[m].getX() and obj[m].getX() - 1 != 0 and l != m)
                                                    {
                                                        obj[m].setX(-1);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (GetAsyncKeyState((unsigned short)'S'))
        {
            p.setY(1);
            if (p.getY() == H - 1)
            {
                p.setY(-1);
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (p.getY() == obj[i].getY() and p.getX() == obj[i].getX() and obj[i].getY() + 1 != H)
                    {
                        obj[i].setY(1);
                        for (int j = 0; j < n; j++)
                        {
                            if (obj[i].getY() == obj[j].getY() and obj[i].getX() == obj[j].getX() and obj[j].getY() + 1 != H and i != j)
                            {
                                obj[j].setY(1);
                                for (int k = 0; k < n; k++)
                                {
                                    if (obj[j].getY() == obj[k].getY() and obj[j].getX() == obj[k].getX() and obj[k].getY() + 1 != H and j != k)
                                    {
                                        obj[k].setY(1);
                                        for (int l = 0; l < n; l++)
                                        {
                                            if (obj[k].getY() == obj[l].getY() and obj[k].getX() == obj[l].getX() and obj[k].getY() + 1 != H and k != l)
                                            {
                                                obj[l].setY(1);
                                                for (int m = 0; m < n; m++)
                                                {
                                                    if (obj[l].getY() == obj[m].getY() and obj[l].getX() == obj[m].getX() and obj[m].getY() + 1 != H and l != m)
                                                    {
                                                        obj[m].setY(1);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (GetAsyncKeyState((unsigned short)'D'))
        {
            p.setX(1);
            if (p.getX() == W - 1)
            {
                p.setX(-1);
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (p.getY() == obj[i].getY() and p.getX() == obj[i].getX() and obj[i].getX() + 1 != W)
                    {
                        obj[i].setX(1);
                        for (int j = 0; j < n; j++)
                        {
                            if (obj[i].getY() == obj[j].getY() and obj[i].getX() == obj[j].getX() and obj[j].getX() + 1 != W and i != j)
                            {
                                obj[j].setX(1);
                                for (int k = 0; k < n; k++)
                                {
                                    if (obj[j].getY() == obj[k].getY() and obj[j].getX() == obj[k].getX() and obj[k].getX() + 1 != W and j != k)
                                    {
                                        obj[k].setX(1);
                                        for (int l = 0; l < n; l++)
                                        {
                                            if (obj[k].getY() == obj[l].getY() and obj[k].getX() == obj[l].getX() and obj[k].getX() + 1 != W and k != l)
                                            {
                                                obj[l].setX(1);
                                                for (int m = 0; m < n; m++)
                                                {
                                                    if (obj[l].getY() == obj[m].getY() and obj[l].getX() == obj[m].getX() and obj[m].getX() + 1 != W and l != m)
                                                    {
                                                        obj[m].setX(1);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        print(screen, n, map, hConsole);
        WriteConsoleOutputCharacter(hConsole, screen, W * H, { 0, 0 }, &dwBytesWritten);
        tick++;
        Sleep(80);
    }
    return 0;
}

void print(wchar_t screen[], int n, wchar_t map[50][50], HANDLE hConsole)
{
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            screen[i + j * W] = map[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        screen[obj[i].getX() + obj[i].getY() * W] = L'\052';
    }
    screen[p.getX() + p.getY() * W] = L'☻';
    screen[0] = L'█';
}

Object::Object(int xP, int yP)
{
    x = xP;
    y = yP;
}

int Object::getX()
{
    return x;
}

int Object::getY()
{
    return y;
}

void Object::del()
{
    x = 51;
    y = 51;
}

void Object::setX(int xP)
{
    x += xP;
}

void Object::setY(int yP)
{
    y += yP;
}

Player::Player(int xP, int yP)
{
    x = xP;
    y = yP;
}

int Player::getX()
{
    return x;
}

int Player::getY()
{
    return y;
}

void Player::setX(int xP)
{
    x += xP;
}

void Player::setY(int yP)
{
    y += yP;
}
