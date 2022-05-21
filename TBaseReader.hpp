#ifndef T_HPP_BASE_READER_
#define T_HPP_BASE_READER_

#include <string>
#include <vector>

using namespace std;

//! ������� ����� ��� �������� ������ ����������
class TBaseReader
{
   public:

      TBaseReader() = default;

      //! ����������� ���������� 
      virtual ~TBaseReader() = default;

      //! ��������� ���������������� ������� ������� ������
      virtual void setNameFile( string fileName ) = 0;

      //! ��������� ������� ��������� ���������� 
      virtual bool getTransaction( vector<int>& transaction ) = 0;

      //! ��������� ������� �������� ������� ������ ����� � ������ �����
      virtual void returnStart() = 0;

   private:

};


#endif // T_HPP_BASE_READER_

