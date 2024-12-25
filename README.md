# PP-MPI

## Как установить MPI на Visual Studio на Windows
- Установить файлы из MPI_installation_files.zip
- Свойства проекта: 
    - C/C++ -> Общие -> Дополнительные каталоги включаемых файлов: C:\Program Files (x86)\Microsoft SDKs\MPI\Include (или путь куда вы установили msmpisdk.msi + '\Include')
    - Компоновщик -> Общие -> Дополнительные каталоги библиотек: C:\Program Files (x86)\Microsoft SDKs\MPI\Lib\x64 (или путь куда вы установили msmpisdk.msi + '\Lib\x{platform}')
    - Компоновщик -> Ввод -> Дополнительные зависимости: msmpi.lib

Видеосопровождение (не мое)
[YouTube](https://www.youtube.com/watch?v=PPEu5KyTx3c)
