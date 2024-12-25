#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char* argv[])
{
    // ������������� MPI
    MPI_Init(&argc, &argv);

    // ����������� ���������� ���������
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // ����������� ����� �������� ��������
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // ����� ���������� � ��������
    std::cout << "Hello from process " << world_rank << " out of " << world_size << " processes!" << std::endl;

    // ���������� ������ MPI
    MPI_Finalize();
    return 0;
}