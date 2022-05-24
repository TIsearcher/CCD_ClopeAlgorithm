#ifndef _T_FILE_DISPATCHER_HPP_
#define _T_FILE_DISPATCHER_HPP_

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

//! ����� ����������� ��� ���������� ���������� � ����������� � �� ������������� � i - ��� ��������.
class TFileDispatcher
{
   public:

      //! ����������� �� ���������.
      TFileDispatcher();

      //! ���������� �� ���������.
      ~TFileDispatcher();

      //! ������� ������������ ���������� � �������� �� ��������� ����.
      //! transaction - ������� ��������� ����������. 
      //! clusterId - ������������������ ����� ��������, � �������� ����� �������� ������ ����������.
      void writeTransactionInfo( vector<int>& transaction, int clusterId );

      //! ������� ����������� ���������� � ����� �������� �� ���������� ��������� 
      //! transaction - ���������� ��������� �� ����� � ��������������� � - clusterId
      bool readTransactionInfo( vector<int>& transaction, int& clusterId );

      //! �������, ������� �������������� id �������� � ��������� ��������� ���������� 
      void overwriteClusterId( int clusterId );

      //! ������� �������� ������� � ������ ����� 
      void return2Begin();

   private:

      fstream fileDispatcher;                      //!< ����� ������ ��������� � ���������
      fpos<_Mbstatet> startPos;                    //!< ������� ��������� � ������ ������ ������ 
      fpos<_Mbstatet> stopPos;                     //!< ������� ��������� � ������ ����� ������ 
      const int sep = 0;                           //!< ����������� ����� ������������
};

#endif //_T_FILE_DISPATCHER_HPP_
