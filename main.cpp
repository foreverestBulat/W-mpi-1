#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char* argv[])
{
    // Инициализация MPI
    MPI_Init(&argc, &argv);

    // Определение количества процессов
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Определение ранга текущего процесса
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Вывод информации о процессе
    std::cout << "Hello from process " << world_rank << " out of " << world_size << " processes!" << std::endl;

    // Завершение работы MPI
    MPI_Finalize();
    return 0;
}