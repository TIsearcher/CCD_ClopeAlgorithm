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

      //! �������
      void writeClusterId( int clusterId );
      
      //! ������� ������������ ��������� ������/������ ������ �����/������ � ������
      void setSeekToBegin();

   private:

      streamoff startPos;                          //!< ������� ��������� � ������ ������ ������ 
      streamoff stopPos;                           //!< ������� ��������� � ������ ����� ������ 
      ofstream fileDispatcher;                     //!< ����� ������ ��������� � ���������
      const int sep = 0;                           //!< ����������� ����� ������������
};

#endif //_T_FILE_DISPATCHER_HPP_
