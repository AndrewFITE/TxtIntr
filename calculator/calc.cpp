#include <iostream>
#include <cmath>
#include <getopt.h>
#define PI 3.14159265
using namespace std;
int main(int argc, char *argv[])
{
	{ if (argc==1)
    {
        cout << "Баллистический Калькулятор" << endl
        << "Вам нужно ввести один из параметров, чтобы выбрать выполняемое действие:" << endl
        << "-v — вычисление высоты" << endl 
        << "-d — вычисление дальности" << endl
        << "ВАЖНЫЕ ЗАМЕТКИ О РАБОТЕ КАЛЬКУЛЯТОРА:" << endl
        << "1. Значение угла по умолчанию задаётся в градусах" << endl
        << "2. Значение начальной скорости по умолчанию задаётся в м/с" << endl
        << "3. Разрешённый диапазон для значения угла при вычислении дальности: (0;90]" << endl
        << "Запустите программу ещё раз с нужным параметром и введите значения угла и начальной скорости через пробел" << endl;
    }
	int opt, i, x, t; 
	double result = 0;
	while ((opt = getopt (argc, argv, "vd")) != -1)
        {
            switch (opt)
            {

                case 'v':
        			for(i=2; i<argc; i++)
        			{
            			x = strtod(argv[2], NULL);
            			t = strtod(argv[3], NULL);
            			result = ((t * t) * (sin((x * PI) / 180) * sin((x * PI) / 180))) / (9.8 * 2);
        			}
        		cout << "Высота = " << result << endl;
               	break;

               	case 'd':
    				for(i=2; i<argc; i++)
    				{
       					x = strtod(argv[2], NULL);
       					if (x > 90) {
       						cout << "Введено запрещённое значение угла! Разрешённый диапазон (0;90]. Повторите попытку ввода, используя значение из разрешённого диапазона" << endl;
       						return(0);
       					} if (x == 90) {
       						cout << "Дальность = 0" << endl;
       						return(0);
       					} else {
          				t = strtod(argv[3], NULL);
        				result = ((t * t) * sin(2 * ((x * PI) / 180))) / 9.8;
    					}
    				}
    			cout << "Дальность = " << result << endl;
                break;
            }
        }
    }
}
