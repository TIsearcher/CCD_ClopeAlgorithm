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
   //if ( fileManager.eof() )
   //   return true;
   //
   //getline( fileManager, fileLine );


   //transaction.clear();

   //fileLine.erase( remove_if( fileLine.begin(),       // �������� �� ���������� �������� � �������������� ���������
   //                fileLine.end(),
   //                []( char c )
   //                {
   //                   if ( c == ',' )
   //                      return true;
   //                   else
   //                      return false;
   //                } ),
   //                fileLine.end() );

   //size_t sizeTrans = fileLine.size();
   //transaction.resize( sizeTrans );       // ��� ������ ����� ������ ���� 1 ��� ����� ������( �� ��� �� ����� )

   //int pos = 0;                           // ������� �������� � ���������� t

   //for ( int a = 0; a < sizeTrans; ++a )
   //{
   //   transaction[a] = static_cast< int >( fileLine[a] ) + 26 * pos - start_char + 1;
   //   ++pos;
   //}

   //return false;
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
            unsigned int data = static_cast<int>( c ) - start_char + 1;
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

