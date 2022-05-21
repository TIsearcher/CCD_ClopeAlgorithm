#ifndef _T_HPP_CLOPE_
#define _T_HPP_CLOPE_

#include "vector"
#include <memory>
#include "TCluster.hpp"
#include "TFactory.hpp"

using namespace std;

//! ����� ��������������� ��������� ������������� CLOPE ( Clustering with sLOPE ) 
//! https://loginom.ru/blog/clope - �������� �������� ������ ���������
//! https://algowiki-project.org/ru/��������:�����_��������/��������_CLOPE_�������������_��������������_������
class TClope
{
   public:

      //! ����������� �� ���������
      //! typeReader - ��� ������� ������.
      //! fileName - ��� ��������� �����.
      //! r - ����������� ������������.
      TClope( string typeReader, string fileName, double r );

      //! ������� ���������� ������������� ���������� Clope
      void exec();

      //! ����� ��� ����� �������� ������
      using UCluster = shared_ptr<TCluster>;

   private:

      //! ����� ���������� ������� ���������� "profit"
      void firstStage( vector<int>& transaction, UCluster& bestCluster, double delCost );
        
      //! ���������� ������������� �������� ��� ������ ������(����) ���������
      //! transaction - ������� ����������.
      //! curentCluster - ������� �������
      //! return - ������ �� ������� ��������� �������, ��� �������� ��������� ������ ���������� ������ 
      UCluster& Profit2Stage( vector<int>& transaction, UCluster& curentCluster );

      //! ������� ���������� �������
      double profit();

      bool moved = true;                      //!< ���������� ���������� ���������� ��� ���������� ��������
      double r = 0;                            //!< ����������� ������������  
      TFactory factory;                        //!< ������ ������� �������� ������� ������
      TBaseReader* fileReader;                 //!< ��������� �� ������� ����� �������� ( ��������� �� )
      vector<UCluster> clusters;               //!< ������ ���������
   
};

#endif // _T_HPP_CLOPE_