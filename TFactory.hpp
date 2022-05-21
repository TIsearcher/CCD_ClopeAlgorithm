#ifndef _T_HPP_FACTORY_READER_
#define _T_HPP_FACTORY_READER_

#include <string>
#include <map>
#include "TBaseReader.hpp"
#include "TReader.hpp"

using namespace std;

//! ��������� ��� ��������� �������� ������ �� �����
class TIAbstractReadOnDeviceCreator
{
   public:

   //! ����������� ���������� 
   virtual ~TIAbstractReadOnDeviceCreator() = default;

   //! ������� �������� ��������
   virtual TBaseReader* create() const = 0;
};

//! ��������� ����� �������� �������� 
template<typename readerType>
class TReadOnDeviceCreator final : public TIAbstractReadOnDeviceCreator
{
   //! ������� �������� ��������
   TBaseReader* create() const override
   {
      return new readerType();
   };
};

//! ������� �������� 
class TFactory
{
   protected:

   typedef map<string, TIAbstractReadOnDeviceCreator*> factoryMap;     //<! ���������� ������ 
   factoryMap factory;                                                 //<! ��������� ��������� �������� 

   public:

   //! �����������         
   TFactory()
   {
      this->add<TReader>( mashroomType );
   };

   //! ���������� 
   ~TFactory()
   {
   };

   //! ������� ���������� ��������� ���������� [����-�����]
   //! id - ��� ����� ��� ������ �����
   template<typename readerType>
   void add( const string& id )
   {
      factoryMap::iterator it = factory.find( id );

      if ( it == factory.end() )
         factory[id] = new TReadOnDeviceCreator<readerType>;
   };

   //! ������� �������� �������� �� id
   //! findKeyParams - ��������� ���������� ��� �������������� �����
   //! return - ��������� �� ������ �������
   TBaseReader* create( string typeReader )
   {
      factoryMap::iterator it = factory.find( typeReader );

      if ( it != factory.end() )
         return it->second->create();

      return nullptr;
   };

   private:

   const string mashroomType = "MR";              //!< ������������� ��� ������ ������ "������ ��� �����"  
};

#endif // _T_HPP_FACTORY_READER_

