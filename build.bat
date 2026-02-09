@echo off
echo Сборка...

REM Компиляция с указанием пути к заголовочным файлам
gcc -c lib/battle.c -Ilib/include
gcc -c lib/character.c -Ilib/include
gcc -c lib/Enemy.c -Ilib/include
gcc -c lib/interface.c -Ilib/include
gcc -c lib/Inventory.c -Ilib/include
gcc -c lib/Item.c -Ilib/include
gcc -c lib/Map.c -Ilib/include
gcc -c main.c -Ilib/include

REM Линковка (файлы .o создались в текущей папке, не в lib/)
gcc battle.o character.o Enemy.o interface.o Inventory.o Item.o Map.o main.o -o program.exe

REM Проверка
if exist program.exe (
    echo Успешно!
    program.exe
) else (
    echo Ошибка!
)

pause.\