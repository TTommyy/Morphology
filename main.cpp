#include <iostream>
#include "Morfologia.cpp"
#include <chrono>
void dylInf(){
  BitmapaExt b(2,3,3);
    b(0,0,0) = b(0,1,1)=b(0,2,2) = 1;
    b(1,0,2) = b(1,1,1) = b(1,2,0) = 1;

    Dylatacja d;
    Inwersja i;
    ZlozeniePrzeksztalcen z;
    z.dodajPrzeksztalcenie(&d);
    z.dodajPrzeksztalcenie(&i);
    std::cout << "Oryginalna bitmapa: "<< b << "\n\n";
    /*Powinno byc:
    {
        {
            {1,0,0},
            {0,1,0},
            {0,0,1}
        },
        {
            {0,0,1},
            {0,1,0},
            {1,0,0}
        }
    }
    */
    z.przeksztalc(b);
    std::cout << "Przeksztalcona bitmapa: "<< b << "\n\n";
   
   /*
    Po dylatacji:
    {
        {
            {1,1,1},
            {1,1,1},
            {1,1,1}
        },
        {
            {1,1,1},
            {1,1,1},
            {1,1,1}
        }
    }
    Po inwersji:
    {
        {
            {0,0,0},
            {0,0,0},
            {0,0,0}
        },
        {
            {0,0,0},
            {0,0,0},
            {0,0,0}
        }
    }
    */
}

void jawny(){
    BitmapaExt b(3,4,5);
    b(0,1,0)= b(0,2,2) = b(0,2,3) = b(0,1,2)= true;
    b(1,2,1) = b(1,2,2) = b(1,2,3) = b(1,1,1) = b(2,1,2)= true;
    b(2,2,1) = b(2,2,2) = b(2,2,3) = b(2,1,1) = true;

    std::cout << "Oryginalna bitmapa:\n" <<  b << "\n\n";

    Usrednianie u;
    Dylatacja d;

    ZlozeniePrzeksztalcen z;
    z.dodajPrzeksztalcenie(&u);
    z.dodajPrzeksztalcenie(&d);

    // przeksztalcenie 'z' najpierw wykona usrednianie, a potem dylatacje
    z.przeksztalc(b);

    std::cout << "Przeksztalcona bitmapa:\n" << b << "\n";
}

void eroInf(){
    BitmapaExt b(2,3,3);
    b(0,0,0) = b(0,1,1)=b(0,2,2) = 1;
    b(1,0,2) = b(1,1,1) = b(1,2,0) = 1;

    Inwersja i;
    Erozja e;

    ZlozeniePrzeksztalcen z;
    z.dodajPrzeksztalcenie(&e);
    z.dodajPrzeksztalcenie(&i);
    std::cout << "Oryginalna bitmapa: "<< b << "\n\n";
    /*Powinno byc:
    {
        {
            {1,0,0},
            {0,1,0},
            {0,0,1}
        },
        {
            {0,0,1},
            {0,1,0},
            {1,0,0}
        }
    }
    */
    z.przeksztalc(b);
    std::cout << "Przeksztalcona bitmapa: "<< b << "\n\n";
    /*Najpierw erozja a wiec:
    {
        {
            {0,0,0},
            {0,0,0},
            {0,0,0}
        },
        {
            {0,0,0},
            {0,0,0},
            {0,0,0}
        }
    }
    Potem Inwersja wiec:
    {
        {
            {1,1,1},
            {1,1,1},
            {1,1,1}
        },
        {
            {1,1,1},
            {1,1,1},
            {1,1,1}
        }
    }
    */
}

using namespace std::chrono;

int main(){  
  auto start = std::chrono::high_resolution_clock::now();
  jawny();
  //dylInf();
  //eroInf();
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<microseconds>(stop - start);
  std::cout << duration.count() << std::endl;
}