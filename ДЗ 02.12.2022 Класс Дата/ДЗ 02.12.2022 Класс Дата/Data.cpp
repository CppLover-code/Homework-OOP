#include "Data.h"
#include <iostream>

using namespace std;

Data::Data()
{
    {
        //cout << " �����������\n";
        bool flag = true;
        do
        {
            cout << " ������� ���� (����, �����, ���):\n";
            cin >> d >> m >> y;

            if (((y % 4 == 0 && y % 100 != 0 || y % 400 == 0) && (m == 2) && (d > 0 && d <= 29))
                || ((y % 4 == 0 && y % 100 != 0 || y % 400 == 0) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d > 0 && d <= 31))
                || ((y % 4 == 0 && y % 100 != 0 || y % 400 == 0) && (m == 4 || m == 6 || m == 9 || m == 11) && (d > 0 && d <= 30))
                || ((y % 4 > 0 && y % 400 != 0 || y % 100 == 0) && (m == 2) && (d > 0 && d <= 28))
                || ((y % 4 > 0 && y % 400 != 0 || y % 100 == 0) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d > 0 && d <= 31))
                || ((y % 4 > 0 && y % 400 != 0 || y % 100 == 0) && (m == 4 || m == 6 || m == 9 || m == 11) && (d > 0 && d <= 30)))
            {
                cout << " ���� ������� ���������!\n\n";
                flag = true;
            }
            else
            {
                if ((y % 4 != 0 && y % 100 == 0 || y % 400 != 0) && (m == 2) && (d == 29))
                {
                    cout << " ��� ������������!\n";
                }

                cout << " ���� ������� �����������!\n\n";

                flag = false;
            }

        } while (!flag);                                                     // ���� �������� ���� ������������ ������ ������������ ����

    }
}

int Less(const Data& D)  // ������� ��� ������� ����
{
    int sum = 0;
    int day = D.d;

    for (int i = D.m; i <= 12; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        {
            sum += (31 - day);
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            sum += (30 - day);
        }
        else if (i == 2)
        {
            if ((D.y % 4 == 0 && D.y % 100 != 0) || D.y % 400 == 0) // ���������� ���
            {
                sum += (29 - day);
            }
            else
            {
                sum += (28 - day);
            }
        }

        day = 0;
    }

    return sum;
}

int Greater(const Data& D)  // ������� ��� ������� ����
{
    int sum = 0;
    int day = D.d;
    sum += day;

    for (int i = D.m - 1; i >= 1; i--)
    {
        day = 0;
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        {
            sum += (31 - day);
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            sum += (30 - day);
        }
        else if (i == 2)
        {
            if ((D.y % 4 == 0 && D.y % 100 != 0) || D.y % 400 == 0) // ���������� ���
            {
                sum += (29 - day);
            }
            else
            {
                sum += (28 - day);
            }
        }
    }

    return sum;
}

int checkYear(int y)  // �������� ���� �� ������������
{
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) // ���������� ���
    {
        return 366;
    }
    else return 365;
}

int Data::operator-(Data& t)                                                  // �� ��������� const ��� ������ ����, �� ��������� ���� ������ ���� �������, ���� ������ ���� ������ ������
{
    int total = 0;
    int day = 0;

    if (y < t.y)                                                         // ���� ������ ���� ������ ������
    {
        total += Less(*this) + Greater(t);
        for (int i = y + 1; i < t.y; i++)
        {
            total += checkYear(i);
        }
    }
    else if (y > t.y)                                                    // ���� ������ ���� ������ ������
    {
        total += Less(t) + Greater(*this);
        for (int i = t.y + 1; i < y; i++)
        {
            total += checkYear(i);
        }
    }
    else if (y == t.y)                                                   // ���� ��� ���� � ��� ��
    {
        if (m < t.m)
        {
            day = d;
            for (int i = m; i < t.m; i++)
            {
                if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                {
                    total += (31 - day);
                }
                else if (i == 4 || i == 6 || i == 9 || i == 11)
                {
                    total += (30 - day);
                }
                else if (i == 2)
                {
                    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)    // ���������� ���
                    {
                        total += (29 - day);
                    }
                    else
                    {
                        total += (28 - day);
                    }
                }
                if (i + 1 == t.m) total += t.d;
                else day = 0;
            }
        }
        else if (m > t.m)
        {
            day = t.d;
            for (int i = t.m; i < m; i++)
            {
                if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                {
                    total += (31 - day);
                }
                else if (i == 4 || i == 6 || i == 9 || i == 11)
                {
                    total += (30 - day);
                }
                else if (i == 2)
                {
                    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)   // ���������� ���
                    {
                        total += (29 - day);
                    }
                    else
                    {
                        total += (28 - day);
                    }
                }

                if (i + 1 == m) total += d;
                else day = 0;
            }
        }
        else if (m == t.m)                                              // ���� ������ �����, �� ��������� ���
        {
            (d > t.d) ? total += (d - t.d) : total += (t.d - d);
            if (d == t.d) total = 0;                                    // ���� ���� ��������� ��������� ���� ����� � ���, �� ����� ���� ����
        }
    }

    return total;
}

Data Data::operator+(int count)                                         // ���������� ��������� + (int)
{
    for (int i = m; i <= 12; )                                          // ����������� ���������� �������� �� �������� ������, ������� ����� �������� � ����������� �� �������
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)  // �������� �������� ������
        {
            if (count + d <= 31)                                        // ���� ����� ���-�� ���� ��� ���������� � �������� ���-�� ���� <= ������ ���-�� ���� � ������,
            {
                d += count;                                             // �� ������������ ���-�� ������� ���� �� ���-�� ���� ��� ����������
                break;                                                  // ��������� ����
            }
            else                                                        // �����, �������� �� ���-�� ���� ��� ���������� ������� ����� ������� ���-��� ����
            {
                count -= (31 - d);                                      //  � ����� ���-��� ���� � ������
                d = 0;                                                  //  �������� ������� ���-�� ����
                m++;                                                    // � ����������� ����� �� 1
            }
        }
        else if (i == 12)
        {
            if (count + d <= 31)
            {
                d += count;
                break;
            }
            else                                                        // ������ ������ � 12 �������
            {                                                           // ���� ���-�� ���� ��� ���������� ������ 31,
                count -= (31 - d);                                      // �� �������� �� ���-�� ���� ��� ���������� ������� ����� ������� ���-��� ����, �������� ������� ���-�� ����
                d = 0;                                                  // �������� ������� ���-�� ����
                m = 1;                                                  // � ����� ���������� 1 (������)
                y++;                                                    // ��� ������������� �� 1
            }
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            if (count + d <= 30)
            {
                d += count;
                break;
            }
            else
            {
                count -= (30 - d);
                d = 0;
                m++;
            }
        }
        else if (i == 2)
        {
            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)            // ���������� ���
            {
                if (count + d <= 29)
                {
                    d += count;
                    break;
                }
                else
                {
                    count -= (29 - d);
                    d = 0;
                    m++;
                }
            }
            else
            {
                if (count + d <= 28)
                {
                    d += count;
                    break;
                }
                else
                {
                    count -= (28 - d);
                    d = 0;
                    m++;
                }
            }
        }
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Data& P)                  // ����� ������ ����� �����
{
    os << P.d << "." << P.m << "." << P.y << "\n";

    return os;
}