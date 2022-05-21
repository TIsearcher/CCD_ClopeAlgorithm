#ifndef _T_CLUSTER_HPP_
#define _T_CLUSTER_HPP_

#include <map>
#include <memory>
#include <vector>

using namespace std;

//! ����� �������� ������������ ������
class TCluster
{
   public:

      //! ����������� �� ��������� 
      TCluster();

      //! ���������� �� ��������� 
      ~TCluster() = default;

      //! ������� ������� ��������� ���������� ���������� � �������
      //! return - ���� ���������� 
      double costAdd( vector<int>& transaction, float r );

      //! ������� ������� ��������� �������� ���������� �� �������
      //! return - ���� �������� 
      double costDel( vector<int>& transaction, float r );

      //! ������� ���������� ���������� � �������
      //! transaction - ������� ���������� 
      void insertTransaction( vector<int>& transaction );

      //! ������ �������� ���������� �� �������� 
      //! transaction - ������� ����������
      void deleteTransaction( vector<int>& transaction );

      //! ������� �������� ������ ��������
      //! return - ����� ���� �� ����� ������ ��������
      static shared_ptr<TCluster> newCluster();

      //! ������ - ������� ��������� �������� N
      //! return - ������� �������� N 
      size_t getN();

      //! ������� ��������� ������ ���������� �������� � ��������
      //! return - ���������� �������� � �������� S
      size_t getS();

      //! ������� ��������� ������ ��������
      //! return - ������ �������� W
      size_t getW();

      //! �������, ������������ ����� ��������
      //! return - id - ����� ��������
      int getId();

   private:
      
      map<int, int> Occ;         //!< ���������� ��������� (�������) ������� i � ������� CC;
                                 //!< ���� - ������ (������)
                                 //!< ����? - ������� ��������� ������� � �������  
                                 
      size_t S = 0;              //!< ���������� �������� � �������� 
      size_t W = 0;              //!< ������ �������� 
      size_t N = 0;              //!< ���������� ���������� � ��������

      
      inline static int g_id= 0; //!< ������� ���-�� ���������.
      int id = 0;                //!< ������������� ������� ���������� 
};

#endif // _T_CLUSTER_HPP_