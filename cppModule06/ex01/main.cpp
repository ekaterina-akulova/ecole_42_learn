//
// Created by Екатерина Акулова on 01.11.2022.
//

/* Сериализация — процесс перевода структуры данных в последовательность байтов.
   Обратной к операции сериализации является операция десериализации —
   создание структуры данных из битовой последовательности.
   Сериализация используется для передачи объектов по сети и для сохранения их в файлы.

  reinterpret_cast  позволяет преобразовывать любой указатель в указатель любого другого типа.
  Также позволяет преобразовывать любой целочисленный тип в любой тип указателя и наоборот.

  Тип uintptr_t - это тип, специально предназначенный для "хранения" указателей.
  Именно в этот тип можно безопасно записать указатель. */

#include <iostream>

struct Data
{
    std::string name;
};

Data* deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data *>(raw));
}

uintptr_t serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

int main()
{
    Data data = {"Horses"};
    uintptr_t test;
    Data *p_data;

    std::cout << "Data name, Data Adress:" << std::endl;
    std::cout << data.name  << ' '<< &data << std::endl;
    test = serialize(&data);
    std::cout << "Serialize Data - adress: \n" << test << std::endl;
    p_data = deserialize(test);
    std::cout << "Deserialize Data - value, adress\n" << p_data->name << ' '  << p_data << "\n" << std::endl;
   return 0;
}