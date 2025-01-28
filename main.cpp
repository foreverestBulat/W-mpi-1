#include <iostream>
#include <mpi.h>

#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    float start_iteration = 0;
    float end_iteration = 24;
    float step = (end_iteration - start_iteration) / size;

    // функция y = x^2
    // s - площадь, где step - длина, а (rank + step / 2) * (rank + step / 2) - высота
    int s = step * (rank + step / 2) * (rank + step / 2);

    cout << "process " << rank << " S=" << s << endl;

    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == 0) 
    {
        cout << "--------------Barrier--------------" << endl;
    }
    MPI_Barrier(MPI_COMM_WORLD);

    int received_s;
    int rank_receiver = rank - 1;
    int rank_sender = rank + 1;
    if (rank % 2 != 0) 
    {
        cout << "process " << rank << " Send to process " << rank_receiver << endl;
        MPI_Send(&s, 1, MPI_FLOAT, rank_receiver, 0, MPI_COMM_WORLD);
    }
    else 
    {
        MPI_Status status;
        MPI_Recv(&received_s, 1, MPI_FLOAT, rank_sender, 0, MPI_COMM_WORLD, &status);
        cout << "Process " << rank << " Received S=" << received_s << " from process " << rank_sender << endl;

        s += received_s;

        rank_receiver = rank - 2;
        rank_sender = rank + 2;
        if (rank % 4 != 0) 
        {
            cout << "process " << rank << " Send to process " << rank_receiver << endl;
            MPI_Send(&s, 1, MPI_FLOAT, rank_receiver, 0, MPI_COMM_WORLD);
        }
        else 
        {
            MPI_Recv(&received_s, 1, MPI_FLOAT, rank_sender, 0, MPI_COMM_WORLD, &status);
            cout << "Process " << rank << " Received S=" << received_s << " from process " << rank_sender << endl;

            s += received_s;

            // important processes 0 4 8
            // 4 -> 0
            // 8 -> 0
            rank_receiver = 0;
            if (rank == 4 or rank == 8) 
            {
                cout << "process " << rank << " Send to process " << rank_receiver << endl;
                MPI_Send(&s, 1, MPI_FLOAT, rank_receiver, 0, MPI_COMM_WORLD);
            }
            else 
            {
                MPI_Recv(&received_s, 1, MPI_FLOAT, 4, 0, MPI_COMM_WORLD, &status);
                cout << "Process " << rank << " Received S=" << received_s << " from process " << rank_sender << endl;

                s += received_s;

                MPI_Recv(&received_s, 1, MPI_FLOAT, 8, 0, MPI_COMM_WORLD, &status);
                cout << "Process " << rank << " Received S=" << received_s << " from process " << rank_sender << endl;

                s += received_s;

                cout << "Result: " << s << endl;
            }
        }
    }

    MPI_Finalize();
    return 0;
}


//#include <iostream>
//#include <mpi.h>
//
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//    // Инициализация MPI
//    MPI_Init(&argc, &argv);
//
//    // Определение количества процессов
//    int world_size;
//    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//    // Определение ранга текущего процесса
//    int world_rank;
//    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//
//    // Вывод информации о процессе
//    std::cout << "Hello from process " << world_rank << " out of " << world_size << " processes!" << std::endl;
//
//    // Завершение работы MPI
//    MPI_Finalize();
//    return 0;
//}