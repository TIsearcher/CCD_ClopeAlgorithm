#include "TReader.hpp"
//TODO: ���� � ���� ����� ��������� ��������� � �� ���� ��������� ��� ����

void TReader::setNameFile( string fileName )
{
   fileManager.open( fileName );
   char c;

   fileManager >> c;          // ������� utf ��������� txt
   fileManager >> c;
   fileManager >> c;

   if ( !fileManager.is_open() )
   {
      cout << "File is not open. Check him" << endl;             //! TODO: �������� ���� ������
      exit( 1 );
   }
}

bool TReader::getTransaction( vector<int>& transaction )
{
   string line;
   char c;
   int pos = 0;
   getline( fileManager, line );
   istringstream iss( line );          // ������ ����� � ������� �������� ����� �������� ��� �� 
   transaction.clear();                // ����� ������� ����� - ���� ������ ����� ��� ���������� ���������� ������� �� ���� ������������
   while ( true )
   {
      iss >> c;

      if ( iss.eof() ) 
         break;

      if ( c == ',' )
      {
         ++pos;
      }
      else
      {
         if ( c != '?' )
         {
            unsigned int data = static_cast<int>( c ) - startPos + 1;
            data = data + 26 * pos;
            transaction.push_back( data );
         }
      }

   };

   if ( transaction.size() == 0 )
      return false;

   return true;

};

TReader::~TReader()
{
   fileManager.close();
};

void TReader::returnStart()
{
   fileManager.seekg( 0 );

};

