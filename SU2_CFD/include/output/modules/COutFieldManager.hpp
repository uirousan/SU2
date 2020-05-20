#pragma once
#include "../fields/COutFieldCollection.hpp"

class COutFieldManager {

protected:
  COutFieldCollection fields;

public:
  using FieldRefVector = COutFieldCollection::InsertionVector;
  using FieldRef       = COutFieldCollection::Map::iterator;

  COutFieldManager() = default;

  inline void SetFieldValue(const std::string& refName, su2double value){
    fields.SetValueByKey(refName, value);
  }

  inline su2double GetFieldValue(const std::string& refName){
    return fields.GetValueByKey(refName);
  }

  inline COutFieldCollection& GetCollection() { return fields; }

};

class CHistoryOutFieldManager : public COutFieldManager {

public:

  CHistoryOutFieldManager () = default;

  inline FieldRef AddField(const std::string& refName, const std::string& headerName,
                           ScreenOutputFormat format, const std::string& groupName,
                           const std::string& description, FieldType type){
    return fields.AddItem(refName, COutputField(headerName, format, groupName, description, type));
  }
};

class CVolumeOutFieldManager : public COutFieldManager {

public:

  CVolumeOutFieldManager () = default;

  inline FieldRef AddField(const std::string& refName, const std::string& headerName,
                           const std::string& groupName, const std::string& description,
                           FieldType type){
    return fields.AddItem(refName, COutputField(headerName, groupName, description, type));
  }


};