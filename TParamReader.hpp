#ifndef _T_PARAM_READER_HPP_
#define _T_PARAM_READER_HPP_

#include <string>
#include <boost/program_options.hpp>
#include <boost/filesystem/directory.hpp>

using namespace std;
using namespace boost::program_options;
using namespace boost::filesystem;

//! ��������� ������� ���������� 
struct TParamStruct
{
   public:

      //! ����������� �� ��������� 
      TParamStruct() = default;

      //! ���������� �� ��������� 
      ~TParamStruct() = default;

      //! "������" ����-� ������������
      double getR();

      //! "������" ����� �����
      string getFileName();

   private:

      double r = 0.0;      //!< ����������� ������������ 
      string fileName;     //!< ��� �����

};

//! �����, ����������� ������ ���������� �� ��������� ������
class TParamReader
{
   public:
      
      //! ����������� 
      TParamReader();

      //! ���������� 
      ~TParamReader();

      //! �������� �������� ������ ���������� ��������� ������
      //! argc - ���������� ���������� ����������
      //! argv - ��������� �� ��������� ���������, ������� ���� �������� � ��������� ������  
      //! return - ��������� �������� ����������
      int operator()( int argc, char* argv[] );

      //!< ������� �������� � ��������� ������� � ������� ���������� 
      //!< return - ������� ���������.
      TParamStruct& getParamStruct();

   private:

      //! ������� �������� ������� ���������� �� ���������� 
      //! variableMaps - ��������� map � �������� �����������
      //! return - ��������� �������� ����������
      //!   true - ��������� �������
      //!   false - ��������� �� ������� 
      bool checkParam( const variables_map& variableMaps );

      double r;                                                     //!< ����������� ������������ 

      options_description genericOption;                            //!< �������� ����� ����� �������� � ��������� ������ 
      options_description allOption;                                //!< �������� ���� �������� � ��������� ����� 
      variables_map variableMaps;                                   //!< ��������� map � �������� �����������
      TParamStruct prStr;                                           //!< ��������� ������� ����������


      string fileName;                                              //!< ��� �����, � ������� ����� ������ ���������� �������������  

      const string keyHelp = "help";                                //!< ����� ���������� � ����������  
      const string optionHelp = keyHelp + ",h";                     //!< ( ��������� ����� )  

      const string keyInputFile = "input";                          //!< ������� ���� 
      const string optionInputFile = keyInputFile + ",i";           //!< 

      const string keyRepulsion = "repulsion";                      //!< ����������� ������������
      const string optionRepulsionCoeff = keyRepulsion + ",r";      //!<

};

#endif //_T_PARAM_READER_HPP_