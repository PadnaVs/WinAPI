// fakt.ch.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

unsigned int rekFak(unsigned int iV) {
   if (iV == 1) return 1;
   return iV * rekFak(iV-1);
    
    /*static unsigned res = 1;
    static unsigned step = 0;
    
    if (iV == step) {
        return res;
    }
    
    res *= ++step;
    
    rekFak(iV);*/
};

unsigned int cirkleFak(unsigned int iV) {
    unsigned int res = 1;

    for (size_t i = 1; i != iV;) {
        res *= ++i;
    }

    return res;
};

template<typename T>
unsigned int shabl(T iV) {
    try {
        static_cast<unsigned>(iV);

        if (typeid(iV) == typeid(char)) {
            throw 1;
        }
        return cirkleFak(iV);
    }
    catch(int a) {
        std::cout << "Error: it is CHAR" << '\n';
        return 0;
    };
};

int main()
{
    int a = 0;
    unsigned res = 0;

    do {
        std::cout << "Res -> ";
        std::cin >> a;
        if (a <= 0) {
            std::cout << "\nErorr: it is not uint or a <= 0!\n";
        };
    } while (a <= 0);

   // res = rekFak(a);
   // std::cout << "Res " << res  << "! rekurs\n\n";
   //
   // res = cirkleFak(a);
   // std::cout << "Res " << res << "! cirkle\n\n";

    res = shabl(a);
    std::cout << "Res " << res << "! shabl\n\n";

    res = shabl('c');
    std::cout << "Res " << res << "! shabl\n\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
