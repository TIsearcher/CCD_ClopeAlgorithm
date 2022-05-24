#ifndef _T_LOG_INFO_HPP_
#define _T_LOG_INFO_HPP_

#include <string>
#include <iostream>
#include "TCluster.hpp"

using namespace std;
using ULogCluster = vector<shared_ptr<TCluster>>;

class TLogInfo
{
   public:
      
      //! ����������� �� ���������
      TLogInfo() = default;

      //! ���������� �� ���������
      ~TLogInfo() = default;

      //! ������� ������ ���������� � ��������� ���������
      //! log - ������� ��������� ��������� 
      void displayClusterInfo( ULogCluster& log );

      //! ������� ����������� �������
      //! prof - ������
      void displayProfit( double prof );

   private:

      string headlineLittle = "=====================";                           //!< ����������� 
      string headlineBig = "===============================================";
      int counter = 0;                                                           //!< ������� ������ 
};

#endif // !_T_LOG_INFO_HPP_
