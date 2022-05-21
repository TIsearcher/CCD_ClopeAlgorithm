#ifndef _T_HPP_READER_
#define _T_HPP_READER_

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "TBaseReader.hpp"

using namespace std;

//! ����� ���������� �� ���������� ������ �� �����, ������� ���������� ����������� ��������� �������������
//! ���� ����� ���������� ������ ���� ������.
//! ��������� � �������� ����� txt, � ������� 1 ���������� �������� � �������
//! � �������� ��������� ������� ���������� �������
//! ������������ ��� ������ ������ ������� ������ ��� �����
class TReader : public TBaseReader
{
   public:

      TReader() = default;

      ~TReader();

      //! ������� ������������� ��� ������������ �����(���. ��)
      void setNameFile ( string fileName ) override;

      //! ������� ��������� ����� ���������� �� �����(��).
      //! transaction - ������ ������������� �������� �������� ����������.
      //! return - ��������� �� ����� ����� 
      //! false - ����� ����� �� ���������
      //! true - ����� ����� ���������
      bool getTransaction( vector<int>& transaction ) override;

      //! ������� �������� ������� ������ ����� � ������ �����
      void returnStart() override;

   private:

      const unsigned int start_char = 97;    //!< ��������� ������� ���������� (�� ����������) ������� � ASCI �������
      string fileName;                       //!< ��� ������������ �����.
      string fileLine;                       //!< ��������� �� �����(��) ������
      ifstream fileManager;                  //!< ������ ������ ��� ������ � ������� �����.
};

#endif // _T_HPP_READER_